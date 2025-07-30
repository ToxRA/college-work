#include <stdio.h>

int s_top = -1;
int max_size;

void push(int arr[], int n) {
    if (s_top == max_size - 1) {
        printf("Stack overflow\n");
    }
    else {
        s_top = s_top + 1;
        arr[s_top] = n;
    }
}

void pop(int arr[]) {
    if (s_top < 0) {
        printf("Underflow\n");
    }
    else {
        arr[s_top] = 0;
        s_top--;
    }
}

void display(int arr[]) {
    if (s_top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Current stack: ");
        for (int i = 0; i <= s_top; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the size of stack: ");
    scanf("%d", &max_size);
    
    int stack[max_size];
    int initial_size;
    
    printf("How many elements do you want to initialize in stack? (0-%d): ", max_size);
    scanf("%d", &initial_size);
    
    if (initial_size > max_size) {
        printf("Error: Initial size can't be larger than stack size\n");
        return 1;
    }
    
    printf("Enter %d elements: ", initial_size);
    for (int i = 0; i < initial_size; i++) {
        scanf("%d", &stack[i]);
        s_top++;
    }
    
    display(stack);
    
    int choice, value;
    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (s_top == max_size - 1) {
                    printf("Cannot push - stack is full\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(stack, value);
                }
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    
    return 0;
}

