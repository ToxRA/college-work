#include <stdio.h>

#define MAX_SIZE 10

int rear = -1, front = 0, Q[MAX_SIZE];

void display() {
    printf("\nQueue: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", Q[i]);
        }
    printf("\n");
}

void enqueueR(int num) {
    if ( ( (front == 0)&&(rear == MAX_SIZE - 1) ) 
    || (front == rear + 1) ) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        rear++;
        Q[rear] = num;
    }
}

void enqueueF(int num) {
    if ( ( (front == 0)&&(rear == MAX_SIZE - 1) ) 
    || (front == rear + 1) ) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        front--;
        Q[front] = num;
    }
}

void dequeue() {
    if (front == rear == -1) {
    printf("Queue is empty!\n");
    return;
    }
    
    Q[front] = 0;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

int main(void) {
    int choice, element;

    display();
    while (1) {
        
        printf("\nWhat would you like to do?");
        printf("\n1. Enqueue from Rear\n2. Enqueue from Front\n3. Dequeue from Rear\n4. Dequeue fro Front\n5. Exit\nEnter choice: ");
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
            dequeue();
            display();
            break;
            
            case 5:
            printf("Exiting program.\n");
            return 0;
            
            default:
            printf("Invalid choice.\n");
            }
    }

    return 0;
}