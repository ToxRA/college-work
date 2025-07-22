#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int start, int end) {
    int pivot = A[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (A[j] < pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[end];
    A[end] = temp;

    return (i + 1);
}

void quicksort(int A[], int start, int end) {
    if (start < end) {
        int p = partition(A, start, end);
        quicksort(A, start, p - 1);
        quicksort(A, p + 1, end);
    }
}

int main() {
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    quicksort(A, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
