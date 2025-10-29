#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MSG_N 1024
#define RESP_N 2048

int read_sock(int sock_fd, char* buffer, size_t n);
int sendall(int sock_fd, char* buffer, size_t n);
void sigint_handler(int sig);

int server;

int main(int argc, char *argv[]) {
    signal(SIGINT, sigint_handler);

    server = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(42069);

    if (bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error while binding server...\n");
        return EXIT_FAILURE;
    }
 
    if (listen(server, 5) < 0) {
        fprintf(stderr, "Error while starting server...\n");
        return EXIT_FAILURE;
    }
    printf("Server listening on 127.0.0.1:42069\n");

    fd_set sockets;
    fd_set readfds;
    FD_ZERO(&sockets);
    FD_SET(server, &sockets);
    int maxfd = server;

    while (true) {
        readfds = sockets;
        
        if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0) {
            fprintf(stderr, "Error while selecting...\n");
            return EXIT_FAILURE;
        }

        for (int fd = 0; fd <= maxfd; fd++) {
            if (FD_ISSET(fd, &readfds)) {
                if (fd == server) {
                    int conn = accept(server, NULL, NULL);
                    FD_SET(conn, &sockets);
                    printf("New connection (%d)...\n", conn);

                    if (conn > maxfd)
                        maxfd = conn;
                } else {
                    char buffer[MSG_N];
                    int read_bytes = read_sock(fd, buffer, MSG_N);
                    
                    // Client disconnected
                    if (read_bytes <= 0) {
                        close(fd);
                        FD_CLR(fd, &sockets);
                        printf("Client %d disconnected...\n", fd);
                    } 
                    // Echo back
                    else {
                        printf("Received from client %d: %s\n", fd, buffer);

                        char resp_buffer[RESP_N];
                        snprintf(resp_buffer, RESP_N, "Echo: %s", buffer);

                        if (sendall(fd, resp_buffer, strlen(resp_buffer)) < 0) {
                            fprintf(stderr, "Error while responding to client %d...\n", fd);
                            close(fd);
                            FD_CLR(fd, &sockets);
                        }
                    }
                }
            }
        }
    }

    close(server);
    
    return EXIT_SUCCESS;
}

int read_sock(int sock_fd, char* buffer, size_t n) {
    int read_bytes = recv(sock_fd, buffer, n, 0);

    if (read_bytes < 0) {
        fprintf(stderr, "Error while reading from client...\n");
        return -1;
    }
    buffer[read_bytes] = '\0';

    return read_bytes;
}

int sendall(int sock_fd, char* buffer, size_t n) {
    ssize_t total_sent = 0;

    while (total_sent < n) {
        ssize_t sent = send(sock_fd, buffer + total_sent, n - total_sent, 0);
        if (sent < 0) {
            fprintf(stderr, "Error while sending data...\n");
            return -1;
        }
        total_sent += sent;
    }

    return 0;
}

void sigint_handler(int sig) {
    close(server);
    printf("Closing server...\n");
    exit(EXIT_SUCCESS);
}
