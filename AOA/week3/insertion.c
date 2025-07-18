#include <stdio.h>

int main() {
    int curr, prev, n = 5;

    int a[5] = {4, 1, 5, 2, 3};

    for (int i = 1; i < n; i++) {
       curr = i;
       prev = i - 1;
       
       while (prev >= 0 && a[prev] > curr) {
        a[prev + 1] = a[prev];
        prev--;
       }

       a[prev + 1] = curr;
    }
    
    printf("Sorting using Insertion Sorting\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}