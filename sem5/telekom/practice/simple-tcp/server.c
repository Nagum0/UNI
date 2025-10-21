#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

void sendall(int sock_fd, const char* string) {
    size_t total_sent = 0;
    size_t length = strlen(string);

    while (total_sent < length) {
        ssize_t sent = send(sock_fd, string + total_sent, length - total_sent, 0);

        if (sent < 0) {
            fprintf(stderr, "Error sending data\n");
            return;
        }

        total_sent += sent;
    }
}

int receive(int sock_fd, char* buffer, size_t n) {
    ssize_t bytes_received = recv(sock_fd, buffer, n, 0);

    if (bytes_received < 0) {
        fprintf(stderr, "Error while received data.\n");
        return -1;
    }

    return bytes_received;
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(42069);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Binding error.\n");
        exit(EXIT_FAILURE);
    }

    listen(sock, 1);

    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int connection = accept(sock, (struct sockaddr*)&client_address, &client_address_len);
    printf("New connection: %d\n", client_address.sin_addr.s_addr);

    sendall(connection, "Hello, Client!");

    char buffer[16];
    int bytes_received = receive(connection, buffer, sizeof(buffer));
        
    if (bytes_received > 0)
        buffer[bytes_received] = '\0';

    printf("Received from client: %s\n", buffer);

    close(connection);
    close(sock);

    return EXIT_SUCCESS;
}
