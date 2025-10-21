#include <arpa/inet.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

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

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(42069);
    server_address.sin_family = AF_INET;

    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error while connecting.\n");
        return EXIT_FAILURE;
    }

    const char* msg = "Hello, Server!";
    sendall(sock, msg);

    char buffer[16];
    size_t bytes_received = recv(sock, buffer, sizeof(buffer), 0);

    if (bytes_received < 0) {
        fprintf(stderr, "Error while received data.\n");
        return EXIT_FAILURE;
    }
    
    if (bytes_received > 0)
        buffer[bytes_received] = '\0';

    printf("Received from server: %s\n", buffer);

    return EXIT_SUCCESS;
}
