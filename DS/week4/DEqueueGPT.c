#include <stdio.h>

#define MAX_SIZE 10

int rear = -1, front = -1, Q[MAX_SIZE];  // Initialize front and rear to -1 for an empty queue

void display() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue: ");
    int i = front;
    while (i != rear) {
        printf("%d ", Q[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d ", Q[rear]);
    printf("\n");
}

void enqueueR(int num) {
    // Check if the queue is full
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        if (front == -1) {
            front = 0;  // If the queue is empty, set the front to 0
        }
        rear = (rear + 1) % MAX_SIZE;
        Q[rear] = num;
    }
}

void enqueueF(int num) {
    // Check if the queue is full
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        if (front == -1) {
            front = 0;  // If the queue is empty, set the front to 0
        }
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;  // Move front backwards
        Q[front] = num;
    }
}

void dequeueR() {
    // Check if the queue is empty
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
    // Check if the queue is empty
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

    display();
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
