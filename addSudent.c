#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 51 // Maximum length of the name, including the null terminator

char studentName[MAX_NAME_LENGTH];

void addNewStudent()
{
    system("cls");                          //clear the screen

    printf("student's name (maximum 50 characters): ");
    student_name(studentName);
    printf("Student's name: %s\n", studentName);

    printf("Gender(M/F): ");

    printf("Age: ");

    printf("Study year: ");
}

void student_name(char *name)
{
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Remove the trailing newline character if present
    size_t length = strlen(name);
    if (length > 0 && name[length - 1] == '\n') {
        name[length - 1] = '\0';
    }
}

