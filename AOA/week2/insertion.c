#include <stdio.h>

int main() {
    int curr, prev, n = 5, a[10];

    printf("Enter the number of elements(max. 10): ");
    scanf("%d", &n);
    
    printf("Enter the elements of Array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++) {
       curr = a[i];
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