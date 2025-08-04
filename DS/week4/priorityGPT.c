#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define PRIORITIES 3  // Number of different priority levels

// Structure for the priority queue
struct PriorityQueue {
    int data[PRIORITIES][MAX];  // 2D array to represent the queue for each priority
    int front[PRIORITIES];      // Array to track the front of each priority queue
    int rear[PRIORITIES];       // Array to track the rear of each priority queue
};

// Function to initialize the queue
void initQueue(struct PriorityQueue* pq) {
    for (int i = 0; i < PRIORITIES; i++) {
        pq->front[i] = pq->rear[i] = -1;
    }
}

// Function to check if a specific priority queue is full
int isFull(struct PriorityQueue* pq, int priority) {
    return pq->rear[priority] == MAX - 1;
}

// Function to check if a specific priority queue is empty
int isEmpty(struct PriorityQueue* pq, int priority) {
    return pq->front[priority] == -1;
}

// Function to display the queue
void display(struct PriorityQueue* pq) {
    printf("\nPriority Queue Status:\n");
    for (int i = 0; i < PRIORITIES; i++) {
        printf("Priority Level %d: ", i);
        if (isEmpty(pq, i)) {
            printf("Empty\n");
        } else {
            for (int j = pq->front[i]; j <= pq->rear[i]; j++) {
                printf("%d ", pq->data[i][j]);
            }
            printf("\n");
        }
    }
}

// Function to enqueue (insert) into the queue at a specific priority level
void enqueue(struct PriorityQueue* pq) {
    int priority, val;
    printf("Enter priority (0, 1, or 2): ");
    scanf("%d", &priority);

    if (priority < 0 || priority >= PRIORITIES) {
        printf("Invalid priority! Please enter a value between 0 and 2.\n");
        return;
    }

    if (isFull(pq, priority)) {
        printf("Priority level %d queue is full! Cannot enqueue.\n", priority);
    } else {
        printf("Enter value to enqueue at priority level %d: ", priority);
        scanf("%d", &val);

        // If the queue is empty for this priority level, initialize it
        if (isEmpty(pq, priority)) {
            pq->front[priority] = pq->rear[priority] = 0;
        } else {
            pq->rear[priority]++;
        }

        pq->data[priority][pq->rear[priority]] = val;
        printf("Value %d enqueued at priority level %d.\n", val, priority);
    }
}

// Function to dequeue (remove) from the queue at the highest priority
void dequeue(struct PriorityQueue* pq) {
    // Find the first non-empty queue (highest priority)
    for (int i = 0; i < PRIORITIES; i++) {
        if (!isEmpty(pq, i)) {
            printf("Value %d dequeued from priority level %d.\n", pq->data[i][pq->front[i]], i);
            pq->front[i]++;
            if (pq->front[i] > pq->rear[i]) {
                pq->front[i] = pq->rear[i] = -1;  // Reset if the queue becomes empty
            }
            return;
        }
    }

    printf("Queue is empty! Cannot dequeue.\n");
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);

    int choice;

    while (1) {
        // Menu options
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&pq);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
