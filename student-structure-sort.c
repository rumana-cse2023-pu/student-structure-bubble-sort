#include <stdio.h>

struct Student {
    int id;
    char name[50];
    char address[50];
};

void swapStudents(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void Sort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                swapStudents(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int MAX_STUDENTS = 100;
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student students[MAX_STUDENTS];

    for (int i = 0; i < numStudents; i++) {
        printf("Enter student ID, name, and address for student %d: ", i + 1);
        scanf("%d %s %s", &students[i].id, students[i].name, students[i].address);
    }

    Sort(students, numStudents);

    printf("\nSorted array by student's ID:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d %s %s\n", students[i].id, students[i].name, students[i].address);
    }

    return 0;
}
