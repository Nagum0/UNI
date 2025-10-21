#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>


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

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    int maxfd = sock;

    struct timeval timeout = {1, 0}; // 1 second

    int nready = select(maxfd + 1, &readfds, NULL, &readfds, &timeout);

    for (int fd = 0; fd <= maxfd; fd++) {
        if (FD_ISSET(fd, &readfds)) {
            if (fd == sock) {
                int client = accept(sock, NULL, NULL);
                FD_SET(client, &readfds);
                if (client > maxfd) maxfd = client;
            } else {
                char buffer[1024];
                int bytes = recv(fd, buffer, sizeof(buffer), 0);
                if (bytes <= 0) {
                    close(fd);
                    FD_CLR(fd, &readfds);
                } else {
                    buffer[bytes] = '\0';
                    printf("Message from client: %s\n", buffer);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
