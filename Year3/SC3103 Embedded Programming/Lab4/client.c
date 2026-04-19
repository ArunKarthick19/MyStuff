/************************************************************
 * client.c — Runs on RPi
 * Usage: ./client <N>
 * Forks N child processes. Each child connects to the server
 * via TCP, sends one random integer, receives a reply, and
 * prints: PID, value sent, buffer slot index, current buffer sum.
 ************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <time.h>

#define SERVER_IP   "192.168.3.1"   // Change to your PC's IP
#define PORT        8080

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    // Seed random differently per process later
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            return 1;
        }

        if (pid == 0)
        {
            /* ---- Child process ---- */

            // Re-seed so each child gets a different random number
            srand(time(NULL) ^ getpid());
            int number = rand() % 100 + 1;   // random 1–100

            // 1. Create socket
            int sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
                perror("socket");
                exit(1);
            }

            // 2. Server address
            struct sockaddr_in server_addr;
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family      = AF_INET;
            server_addr.sin_port        = htons(PORT);
            server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

            // 3. Connect
            if (connect(sock, (struct sockaddr *)&server_addr,
                        sizeof(server_addr)) < 0) {
                perror("connect");
                exit(1);
            }

            // 4. Send the integer as a string
            char send_buf[64];
            sprintf(send_buf, "%d", number);
            write(sock, send_buf, strlen(send_buf));

            // 5. Receive reply from server
            char recv_buf[256];
            memset(recv_buf, 0, sizeof(recv_buf));
            read(sock, recv_buf, sizeof(recv_buf) - 1);

            // Parse reply: "value slot_index buffer_sum"
            int val, slot, sum;
            sscanf(recv_buf, "%d %d %d", &val, &slot, &sum);

            // 6. Print result
            printf("[Client PID %d] Sent: %d | Slot: %d | Buffer Sum: %d\n",
                   getpid(), val, slot, sum);
            fflush(stdout);

            close(sock);
            exit(0);
        }
    }

    // Parent waits for all children
    for (int i = 0; i < N; i++)
        wait(NULL);

    printf("All %d clients finished.\n", N);
    return 0;
}
