#include <stdio.h>
#define MAX_SIZE 100

struct Student{
    char* name;
    int rollno;
    float marks;
};

int main(void) {
    int num;

    struct Student student[MAX_SIZE];
    printf("Enter the number of students: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter the name: ");
        scanf("%s", student[i].name);

        printf("Enter the roll no. ");
        scanf("%d", &student[i].rollno);

        printf("Enter the marks: ");
        scanf("%f", &student[i].marks);
    }

    float marks[] = {};
    for (int i = 0; i < num; i++) {
        marks[i] = student[i].marks;
    }

    for (int i = 0; i < num; i++) {
        printf("%f", marks[i]);
    }
    printf("\n");

    return 0;
}