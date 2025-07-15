#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, arr[10], isSwap = 0;
    
    printf("Enter the number of elements; ");
    scanf("%d", &n);
    
    printf("Enter the elements of Array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                isSwap = 1;
            }
        }
        if (isSwap == 0) {
            break;
        }
        
    }
    
    printf("\nSorting using Bubble sort\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}