#include <stdio.h>
#include <string.h>
#include <ctype.h> // For isalnum()

// Maximum size for expressions and the stack
#define MAX_SIZE 100

// --- Stack (Implemented using a char array) ---
char stack[MAX_SIZE];
int stackTop = -1; // -1 indicates an empty stack

// Pushes a character onto the stack
void push(char c) {
    if (stackTop < MAX_SIZE - 1) { // Check for stack overflow
        stack[++stackTop] = c;
    } else {
        printf("Stack overflow! Cannot push %c\n", c);
    }
}

// Pops a character from the stack
char pop() {
    if (stackTop >= 0) { // Check for empty stack
        return stack[stackTop--];
    }
    return '\0'; // Return null character for empty stack
}

// Peeks at the top character of the stack without removing it
char peek() {
    if (stackTop >= 0) {
        return stack[stackTop];
    }
    return '\0'; // Return null character for empty stack
}

// --- Helper Functions ---

// Checks if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Gets the precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '^':
            return 3; // Highest precedence
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1; // Lowest precedence
        default:
            return 0; // Not an operator
    }
}

// --- Main Conversion Logic ---
int main(void) {
    char infix[MAX_SIZE];
    // Postfix expression will also be a char array
    char postfix[MAX_SIZE];
    int i, j = 0; // j is the index for the postfix expression

    printf("Enter the Infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove the trailing newline character from fgets input
    infix[strcspn(infix, "\n")] = '\0';

    printf("\nEntered Infix expression: %s\n", infix);
    printf("Converting to Postfix expression using Stack...\n");

    for (i = 0; i < strlen(infix); i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) { // If it's an operand (letter or digit)
            postfix[j++] = currentChar;
        } else if (currentChar == '(') {
            push(currentChar);
        } else if (currentChar == ')') {
            // Pop operators until an opening parenthesis is found
            while (stackTop >= 0 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (stackTop >= 0 && peek() == '(') {
                pop(); // Pop the '('
            } else {
                printf("Error: Mismatched parentheses in expression.\n");
                return 1; // Indicate an error
            }
        } else if (isOperator(currentChar)) {
            // Pop operators with higher or equal precedence
            while (stackTop >= 0 && isOperator(peek()) &&
                   getPrecedence(peek()) >= getPrecedence(currentChar)) {
                postfix[j++] = pop();
            }
            push(currentChar); // Push the current operator
        }
        // Any other characters (like spaces) are ignored
    }

    // Pop any remaining operators from the stack
    while (stackTop >= 0) {
        if (peek() == '(') {
            printf("Error: Mismatched parentheses in expression.\n");
            return 1; // Indicate an error
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string

    printf("\nPostfix Expression: %s\n", postfix);

    return 0; // Indicate successful execution
}