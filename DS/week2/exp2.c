#include <stdio.h>

#define MAX_SIZE 100

int stackTop = -1;
char stack[100];

push(char c) {
    if(stackTop == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push %c\n", c);
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

void getPrecendence() {
    
}

int main(void) {

    printf("\n");
    return 0;
}