#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, arr[10], isSwap = 0, min;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements of Array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

         if (min != i) {
            swap(&arr[i], &arr[min]);
        }
    }

    printf("\nSorting using Selection Sorting\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}