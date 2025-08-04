#include <stdio.h>

#define size 5

int queue[size];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((rear + 1) % size == front) {
    printf("Queue is full!\n");
    return;
    }

    if (front == -1 && rear == -1) {
    front = rear = 0;
    }
    else {
    rear = (rear + 1) % size;
    }
    queue[rear] = data;
}

void dequeue() {
    if (front == -1) {
    printf("Queue is empty!\n");
    return;
    }
    
    queue[front] = 0;
    if (front == rear) {
    front = rear = -1;
    } else {
    front = (front + 1) % size;
    }
}

void display() {
    printf("\nQueue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i]);
        }
    printf("\n");
}

int main() {
    int choice, data;
    display();
    while (1) {
        printf("\nWhat would you like to do?");
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            display();
            break;
            
            case 2:
            dequeue();
            display();
            break;
            
            case 3:
            printf("Exiting program.\n");
            return 0;
            
            default:
            printf("Invalid choice.\n");
            }
    }
    return 0;
}