#include <stdio.h>

void merge(int A[], int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;
    int temp[end - start + 1];

    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }

    while (j <= end) {
        temp[k++] = A[j++];
    }

    for (i = start, k = 0; i <= end; i++, k++) {
        A[i] = temp[k];
    }
}

void mergeSort(int A[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
}

int main() {
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    mergeSort(A, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
