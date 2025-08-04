#include <stdio.h>

#define MAX_SIZE 10
int rear = -1, front = 0, Q[MAX_SIZE];

void enqueueF(int num) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        front--;
        Q[front] = num;
    }
}

void enqueueR(int num) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        rear++;
        Q[rear] = num;
    }
}