#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void modifiedBubbleSort(struct Student arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].marks < arr[j + 1].marks) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void insertionSort(struct Student arr[], int n) {
    int i, j;
    struct Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].marks < key.marks) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(struct Student arr[], int n) {
    int i, j, max_idx;
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].marks > arr[max_idx].marks) {
                max_idx = j;
            }
        }
        swap(&arr[max_idx], &arr[i]);
    }
}

void displayStudents(struct Student arr[], int n) {
    printf("Rank\tName\tMarks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", i + 1, arr[i].name, arr[i].marks);
    }
}

int main() {
    int n;
    printf("Enter the total number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    struct Student tempArr[n];

    printf("Enter student data:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Student %d Marks: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    for (int i = 0; i < n; i++) {
        tempArr[i] = students[i];
    }

    int choice;
    printf("\nDisplay Sorting Menu:\n");
    printf("1. Modified Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            modifiedBubbleSort(tempArr, n);
            printf("\nStudents sorted using Modified Bubble Sort:\n");
            break;
        case 2:
            insertionSort(tempArr, n);
            printf("\nStudents sorted using Insertion Sort:\n");
            break;
        case 3:
            selectionSort(tempArr, n);
            printf("\nStudents sorted using Selection Sort:\n");
            break;
        default:
            printf("Invalid choice! Program terminated.\n");
            return 1;
    }

    displayStudents(tempArr, n);

    return 0;
}