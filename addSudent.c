#include <stdio.h>
#include <string.h>
#include "addSudent.h"

#define MAX_NAME_LENGTH 51 // Maximum length of the name, including the null terminator


char studentName[MAX_NAME_LENGTH];
char studentGender;
char studentAge;

void addNewStudent()
{
    system("cls");                          //clear the screen
    ///////////////////////////////////////////////////////////////////////////////
    // getting student name part
    printf("student's name (maximum 50 characters): ");
    student_name(studentName);
    printf("Student's name: %s\n", studentName);
    ///////////////////////////////////////////////////////////////////////////////
    // getting student Gender part
    printf("Gender(M/F): ");
    studentGender = getStudentGender();
    if(studentGender == 'M')
        printf("Student's gender: Male\n");
    else
        printf("Student's gender: Female\n");
    ///////////////////////////////////////////////////////////////////////////////
    // getting student Age part
    printf("Age: ");
    studentAge = getStudentAge();
    printf("Student's age: %d\n", studentAge);
    ///////////////////////////////////////////////////////////////////////////////
    // getting student Study year part
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

char getStudentGender()
{
    char gender;
    char isValid = 0;

    do {
        printf("Enter student's gender (M/F): ");
        gender = getchar();

        // Check if the input is valid
        if (gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f')
        {
            isValid = 1;
            if (gender == 'm')
            {
                gender = 'M';
            }
            if (gender == 'f')
            {
                gender = 'F';
            }
        }
        else printf("Invalid input! Please enter either 'M' or 'F'.\n");

        // Clear input buffer
        while (getchar() != '\n'); // Clearing the input buffer

    } while (!isValid);

    return gender;
}

char getStudentAge()
{
    char age;
    char isValid = 0;

    do {
        printf("Enter student's age (1-30): ");
        scanf("%d", &age);

        // Check if the input is within the valid range
        if (age >= 1 && age <= 30) {
            isValid = 1;
        } else {
            printf("Invalid input! Please enter an age between 1 and 30.\n");
        }

        // Clear input buffer
        while (getchar() != '\n'); // Clearing the input buffer

    } while (!isValid);

    return age;
}

