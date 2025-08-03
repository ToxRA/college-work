#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int stackTop = -1;

void push(char c) {
    if (stackTop < MAX_SIZE - 1) {
        stack[++stackTop] = c;
    } else {
        printf("Stack overflow! Cannot push %c\n", c);
    }
}

char pop() {
    if (stackTop >= 0) {
        return stack[stackTop--];
    }
    return '\0';
}

char peek() {
    if (stackTop >= 0) {
        return stack[stackTop];
    }
    return '\0';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int main(void) {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    int i, j = 0;

    printf("Enter the Infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infix[strcspn(infix, "\n")] = '\0';

    printf("\nEntered Infix expression: %s\n", infix);
    printf("Converting to Postfix expression using Stack...\n");

    for (i = 0; i < strlen(infix); i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            postfix[j++] = currentChar;
        } else if (currentChar == '(') {
            push(currentChar);
        } else if (currentChar == ')') {
            while (stackTop >= 0 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (stackTop >= 0 && peek() == '(') {
                pop(); 
            } else {
                printf("Error: Mismatched parentheses in expression.\n");
                return 1;
            }
        } else if (isOperator(currentChar)) {
            while (stackTop >= 0 && isOperator(peek()) &&
                   getPrecedence(peek()) >= getPrecedence(currentChar)) {
                postfix[j++] = pop();
            }
            push(currentChar);
        }
    }

    while (stackTop >= 0) {
        if (peek() == '(') {
            printf("Error: Mismatched parentheses in expression.\n");
            return 1;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\nPostfix Expression: %s\n", postfix);

    return 0;
}