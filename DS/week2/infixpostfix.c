#include <stdio.h>
#define MAX_SIZE 100

int main(void) {
    char infix[MAX_SIZE], postfix[MAX_SIZE], stack[MAX_SIZE];

    printf("Enter the Infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    printf("Entered Infix expression: ");
    printf("%s", infix);

    printf("Converting to Postfix expression using Stack...\n");

    


    printf("\nPostfix Expression: ");
    printf("%s", postfix);

    printf("\n");
    return 0;
}