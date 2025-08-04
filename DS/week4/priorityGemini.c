#include <stdio.h> // Required for input/output operations like printf and scanf
#include <stdlib.h> // Required for the exit() function to terminate the program

// Define the maximum number of priority levels.
// The user specified 0(1), 0(2), 0(3), which implies 3 distinct priorities.
#define MAX_PRIORITIES 3

// Define the maximum number of elements that can be stored within each priority queue.
#define MAX_SIZE 10

// Global 2D array to represent the priority queue.
// pq[i] will store elements belonging to priority (i + 1).
// For example, pq[0] stores elements of priority 1, pq[1] for priority 2, and so on.
int pq[MAX_PRIORITIES][MAX_SIZE];

// Global array to keep track of the number of elements in each priority queue.
// rear[i] indicates the next available position (or current count) for priority (i + 1).
int rear[MAX_PRIORITIES];

/**
 * @brief Initializes the priority queue by setting the count of elements
 * for each priority level to zero, effectively making all queues empty.
 */
void initializePQ() {
    for (int i = 0; i < MAX_PRIORITIES; i++) {
        rear[i] = 0; // Set the count of elements for each priority to 0
    }
}

/**
 * @brief Displays the current status of all priority queues.
 * It iterates through each priority level and prints the elements it contains.
 */
void displayPQ() {
    printf("\n--- Priority Queue Status ---\n");
    int isEmpty = 1; // Flag to check if the entire priority queue system is empty

    // Iterate through each priority level (from 1 to MAX_PRIORITIES)
    for (int i = 0; i < MAX_PRIORITIES; i++) {
        printf("Priority %d: ", i + 1); // Print the current priority level

        if (rear[i] == 0) { // Check if the current priority queue is empty
            printf("Empty\n");
        } else {
            isEmpty = 0; // At least one priority queue is not empty
            // Iterate and print elements for the current priority queue
            for (int j = 0; j < rear[i]; j++) {
                printf("%d ", pq[i][j]);
            }
            printf("\n");
        }
    }

    if (isEmpty) {
        printf("The entire priority queue system is empty.\n");
    }
    printf("-----------------------------\n");
}

/**
 * @brief Adds an element to the priority queue based on its value and specified priority.
 * It prompts the user for the value and priority, validates the priority,
 * and adds the element to the corresponding priority queue if space is available.
 */
void enqueue() {
    int value, priority;

    printf("Enter value to enqueue: ");
    scanf("%d", &value); // Read the value from the user

    printf("Enter priority (1, 2, or 3): ");
    scanf("%d", &priority); // Read the priority from the user

    // Validate the entered priority
    if (priority < 1 || priority > MAX_PRIORITIES) {
        printf("Invalid priority! Please enter 1, 2, or 3.\n");
        return; // Exit the function if priority is invalid
    }

    // Convert the 1-indexed priority to a 0-indexed array index
    int p_index = priority - 1;

    // Check for overflow for the specific priority queue
    if (rear[p_index] == MAX_SIZE) {
        printf("Priority Queue for priority %d is full! Cannot enqueue.\n", priority);
        return; // Exit the function if the queue is full
    }

    // Add the value to the end of the selected priority queue
    pq[p_index][rear[p_index]] = value;
    rear[p_index]++; // Increment the count for this priority queue

    printf("Enqueued %d with priority %d.\n", value, priority);
    displayPQ(); // Display the updated queue status
}

/**
 * @brief Removes an element from the priority queue.
 * It dequeues the element with the highest priority (lowest numerical value, e.g., priority 1 first).
 * If multiple elements have the same highest priority, the one that was enqueued first is removed (FIFO).
 */
void dequeue() {
    int dequeuedValue = -1;     // Variable to store the dequeued value, initialized to -1 (sentinel)
    int dequeuedPriority = -1;  // Variable to store the priority of the dequeued element

    // Iterate from the highest priority (index 0 for priority 1) to the lowest priority
    for (int i = 0; i < MAX_PRIORITIES; i++) {
        if (rear[i] > 0) { // Check if the current priority queue is not empty
            dequeuedValue = pq[i][0]; // Get the element at the front of this queue
            dequeuedPriority = i + 1; // Store its priority

            // Shift all subsequent elements in this priority queue one position to the left.
            // This effectively removes the front element.
            for (int j = 0; j < rear[i] - 1; j++) {
                pq[i][j] = pq[i][j + 1];
            }
            rear[i]--; // Decrement the count for this priority queue

            break; // An element has been dequeued from the highest available priority, so exit the loop
        }
    }

    // Check if an element was successfully dequeued
    if (dequeuedValue != -1) {
        printf("Dequeued %d from Priority %d.\n", dequeuedValue, dequeuedPriority);
    } else {
        printf("Priority Queue is empty. Nothing to dequeue.\n");
    }
    displayPQ(); // Display the updated queue status
}

/**
 * @brief The main function that runs the priority queue program.
 * It initializes the queue and presents a menu to the user in a loop,
 * allowing them to perform enqueue, dequeue, or exit operations.
 */
int main() {
    initializePQ(); // Call the initialization function at the start of the program

    int choice; // Variable to store the user's menu choice

    // Infinite loop to keep the menu running until the user chooses to exit
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n");  // Option to add an element
        printf("2. Dequeue\n");  // Option to remove an element
        printf("3. Exit\n");     // Option to terminate the program
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        // Use a switch statement to perform actions based on the user's choice
        switch (choice) {
            case 1:
                enqueue(); // Call the enqueue function
                break;
            case 2:
                dequeue(); // Call the dequeue function
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0); // Terminate the program gracefully
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n"); // Handle invalid input
        }
    }

    return 0; // This line is technically unreachable because exit(0) terminates the program
}
