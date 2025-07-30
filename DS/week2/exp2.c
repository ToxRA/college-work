#include <stdio.h>

#define MAX_SIZE 10
int rear = -1, front = 0, Q[MAX_SIZE];

void enqueue(int num) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow, cannot add %d\n", num);
    } else {
        rear++;
        Q[rear] = num;
    }
}

void dequeue() {
    if (front > rear) {
        printf("Queue Underflow! No elements in the queue\n");
    } else {
        front++;
    }
}

void display() {
    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", Q[i]);
    }
}

int main(void) {
    int choice, num;

    while (1) {
        printf("\n\nChoose from 1-4:\n1. Display the Queue\n2. Enqueue\n3. Dequeue\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
            display();
            break;

            case 2:
            printf("Enter the number to enqueue: ");
            scanf("%d", &num);
            enqueue(num);
            break;

            case 3:
            dequeue();
            break;

            case 4:
            return 0;
            
            default:
            printf("Please enter a number from 1-4!\n");
            break;
        }
    }
   
    printf("\n");

    return 0;
}