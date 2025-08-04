#include <stdio.h>

#define MAX_SIZE 10

int rear = -1, front = -1, Q[MAX_SIZE];

void display() {
    // If the queue is empty
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue: ");
    if (front <= rear) {
        // If the queue has not wrapped around
        for (int i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
    } else {
        // If the queue has wrapped around
        for (int i = front; i < MAX_SIZE; i++) {
            printf("%d ", Q[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
    }
    printf("\n");
}

void enqueueR(int num) {
    // Check for overflow condition
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        if (front == -1) {
            front = 0;  // If the queue is empty, set front to 0
        }
        rear = (rear + 1) % MAX_SIZE;
        Q[rear] = num;
    }
}

void enqueueF(int num) {
    // Check for overflow condition
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        if (front == -1) {
            front = 0;  // If the queue is empty, set front to 0
        }
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;  // Move front backwards
        Q[front] = num;
    }
}

void dequeueR() {
    if (front == -1) {
        printf("Queue Underflow, nothing to dequeue.\n");
    } else {
        Q[rear] = 0;  // Clear the last element
        if (front == rear) {
            front = rear = -1;  // Queue is now empty
        } else {
            rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;  // Move rear backwards
        }
    }
}

void dequeueF() {
    if (front == -1) {
        printf("Queue Underflow, nothing to dequeue.\n");
    } else {
        Q[front] = 0;  // Clear the front element
        if (front == rear) {
            front = rear = -1;  // Queue is now empty
        } else {
            front = (front + 1) % MAX_SIZE;  // Move front forwards
        }
    }
}

int main(void) {
    int choice, element;

    display();  // Display initially

    while (1) {
        printf("\nWhat would you like to do?");
        printf("\n1. Enqueue from Rear\n2. Enqueue from Front\n3. Dequeue from Rear\n4. Dequeue from Front\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueueR(element);
                display();
                break;

            case 2:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueueF(element);
                display();
                break;

            case 3:
                dequeueR();
                display();
                break;

            case 4:
                dequeueF();
                display();
                break;

            case 5:
                printf("\n......Exiting program......\n\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
