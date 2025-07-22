#include <stdio.h>

void merge(int A[], int start, int mid, int end) {
    int i = start; // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = 0; // Index for the temporary array
    int temp[end - start + 1]; // Temporary array to hold merged elements

    // Merge the two halves into the temporary array
    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }

    // Copy the remaining elements of the left subarray, if any
    while (i <= mid) {
        temp[k++] = A[i++];
    }

    // Copy the remaining elements of the right subarray, if any
    while (j <= end) {
        temp[k++] = A[j++];
    }

    // Copy the merged elements back into the original array
    for (i = start, k = 0; i <= end; i++, k++) {
        A[i] = temp[k];
    }
}

void mergeSort(int A[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(A, start, mid); // Sort the left half
        mergeSort(A, mid + 1, end); // Sort the right half
        merge(A, start, mid, end); // Merge the sorted halves
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
