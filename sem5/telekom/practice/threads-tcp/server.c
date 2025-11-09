#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>

#define IP "127.0.0.1"
#define PORT 42069
#define MAX_CLIENTS 5

void handle_exit(int signum);
void cleanup();
void* worker(void* arg);
void sendall(int sock_fd, const char* string);
int receive(int sock_fd, char* buffer, size_t n);

int server;
struct sockaddr_in server_addr = {0};

int worker_count = 0;
pthread_t workers[MAX_CLIENTS];

volatile sig_atomic_t running = 1;

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_exit);

    server = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_addr.s_addr = inet_addr(IP);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

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
        struct sockaddr_in conn_addr = {0};
        socklen_t conn_addr_len = sizeof(conn_addr);
        int *conn = malloc(sizeof(int));
        *conn = accept(server, (struct sockaddr*)&conn_addr, &conn_addr_len);
        pthread_create(&workers[worker_count], NULL, worker, conn);
        worker_count++;
    }
    
    cleanup();
    
    return EXIT_SUCCESS;
}

void handle_exit(int signum) {
    running = 0;
    cleanup();
}

void cleanup() {
    printf("Waiting for workers to finish...\n");
    for (int i = 0; i < worker_count; i++) {
        pthread_join(workers[i], NULL);
    }
    close(server);
    printf("Server closed\n");
}

void* worker(void* arg) {
    int client = *(int*)arg;
    free(arg);

    char buffer[1024];
    receive(client, buffer, 1024);
    printf("(%d) Received from client: %s\n", client, buffer);

    unsigned int seed = time(NULL) ^ pthread_self();
    int t = rand_r(&seed) % 5;
    sleep(t);
    char resp[1024];
    snprintf(resp, 1024, "Time till response: %d", t);
    sendall(client, resp);

    close(client);
    return NULL;
}

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

    buffer[bytes_received] = '\0';
    return bytes_received;
}

