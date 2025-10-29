#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define MAX_CLIENTS 5

int server;
struct sockaddr_in server_addr = {0};

int main(int argc, char *argv[]) {
    server = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(42069);

    if (bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server");
        return EXIT_FAILURE;
    }

    if (listen(server, MAX_CLIENTS) < 0) {
        perror("Error during server startup");
        return EXIT_FAILURE;
    } 

    printf("Starting server on 127.0.0.1:42069\n");

    while (true) {
        
    }

    close(server);

    return EXIT_SUCCESS;
}
