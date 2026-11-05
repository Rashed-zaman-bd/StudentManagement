#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[studentCount].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[studentCount].name);

    printf("Enter Age: ");
    scanf("%d", &students[studentCount].age);

    printf("Enter Marks: ");
    scanf("%f", &students[studentCount].marks);

    studentCount++;

    printf("\nStudent added successfully!\n");
}

void showStudents() {
    int i;

    if (studentCount == 0) {
        printf("\nNo students found!\n");
        return;
    }

    printf("\n========== Student List ==========\n");

    for (i = 0; i < studentCount; i++) {
        printf("\nID    : %d", students[i].id);
        printf("\nName  : %s", students[i].name);
        printf("\nAge   : %d", students[i].age);
        printf("\nMarks : %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int id;
    int i;
    int found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID    : %d\n", students[i].id);
            printf("Name  : %s\n", students[i].name);
            printf("Age   : %d\n", students[i].age);
            printf("Marks : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n\n========== STUDENT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                showStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("\nThank you!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
