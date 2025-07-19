#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int stackTop = -1;


void push(char c) {
    if (stackTop == MAX_SIZE - 1) {
        printf("Stack overflow! Cannot push %c\n", c);
    } else {
        stackTop++;
        stack[stackTop] = c;
    }
}

char pop() {
    if (stackTop < 0) {
        return '\0';
    } else {
        char poppedChar = stack[stackTop];
        stackTop--;
        return poppedChar;
    }
}

char peek() {
    if (stackTop < 0) {
        return '\0';
    } else {
        return stack[stackTop];
    }
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int isOperand(char c) {
    return isalnum(c);
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
    int i, j;

    printf("Enter the Infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infix[strcspn(infix, "\n")] = 0;

    printf("\nEntered Infix expression: %s\n", infix);
    printf("Converting to Postfix expression using Stack...\n");

    j = 0;
    for (i = 0; i < strlen(infix); i++) {
        char currentChar = infix[i];

        if (isOperand(currentChar)) {
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

    printf("\n");
    return 0;
}
