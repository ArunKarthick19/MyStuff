/************************************************************
 * server.c — Runs on PC (Ubuntu)
 * Listens on TCP port. One thread per client connection.
 * Maintains a shared circular buffer (size 5), a write index,
 * and a running sum. Each thread receives an integer, enters
 * a critical section (mutex), inserts into buffer, updates
 * index and sum, sends back: value, slot index, buffer sum.
 ************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT        8080
#define BUF_SIZE    5       // circular buffer size

/* ---- Shared data (protected by mutex) ---- */
int circ_buffer[BUF_SIZE] = {0};   // circular buffer
int write_idx  = 0;                 // next write position
int buffer_sum = 0;                 // running sum of buffer contents
pthread_mutex_t mutex;

/* ---- Thread function: handles one client ---- */
void *handle_client(void *arg)
{
    int client_sock = *(int *)arg;
    free(arg);

    char recv_buf[256];
    char send_buf[256];

    // 1. Receive integer from client
    memset(recv_buf, 0, sizeof(recv_buf));
    int n = read(client_sock, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) {
        perror("read");
        close(client_sock);
        return NULL;
    }

    int value = atoi(recv_buf);

    // 2. Enter critical section
    pthread_mutex_lock(&mutex);

    // Subtract old value at this slot from sum (circular overwrite)
    buffer_sum -= circ_buffer[write_idx];

    // Insert new value
    circ_buffer[write_idx] = value;
    buffer_sum += value;

    int slot = write_idx;                       // record which slot was used
    write_idx = (write_idx + 1) % BUF_SIZE;    // advance, wrap around
    int current_sum = buffer_sum;               // snapshot the sum

    // Print on server side
    printf("[Server] Received: %d | Slot: %d | Buffer Sum: %d | Buffer: [",
           value, slot, current_sum);
    for (int i = 0; i < BUF_SIZE; i++) {
        printf("%d%s", circ_buffer[i], (i < BUF_SIZE - 1) ? ", " : "");
    }
    printf("]\n");
    fflush(stdout);

    pthread_mutex_unlock(&mutex);
    // 3. Exit critical section

    // 4. Send reply: "value slot_index buffer_sum"
    sprintf(send_buf, "%d %d %d", value, slot, current_sum);
    write(client_sock, send_buf, strlen(send_buf));

    close(client_sock);
    return NULL;
}

int main()
{
    int server_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // 1. Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        exit(1);
    }

    // Allow port reuse (avoids "Address already in use" on restart)
    int opt = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 2. Bind
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // 3. Listen
    listen(server_sock, 10);
    printf("Server listening on port %d...\n", PORT);
    printf("Circular buffer size: %d\n\n", BUF_SIZE);

    // 4. Accept loop
    while (1)
    {
        int *client_sock_ptr = malloc(sizeof(int));
        *client_sock_ptr = accept(server_sock,
                                  (struct sockaddr *)&client_addr,
                                  &client_len);

        if (*client_sock_ptr < 0) {
            perror("accept");
            free(client_sock_ptr);
            continue;
        }

        // Spawn a thread for this client
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, (void *)client_sock_ptr);
        pthread_detach(tid);
    }

    close(server_sock);
    pthread_mutex_destroy(&mutex);
    return 0;
}
