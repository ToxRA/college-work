#include <stdio.h>

#define MAX_SIZE 100

int stackTop = -1;
char stack[10];

int getPrecedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int main(void) {
    char postfix[MAX_SIZE], stack[MAX_SIZE];
    char infix[] = "A * B + C";

    for (int i = 0; i < MAX_SIZE; i++) {
        if (getPrecedence(infix[i]) > 0) {
            infix[i] = stack[i];
        } else {
            infix[i] = postfix[i];
        }
    }

    for (int i = MAX_SIZE; i > 0; i--) {
        stack[i] = postfix[i];
    }

    for (int i = 0; i < 10; i++) {
        printf("%c ", postfix[i]);
    }

    printf("\n");
    return 0;
}