#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "properties.h"

/***********************************      Initialize student array Functions   ***********************/
// Initialize student array
void initializeStudentArray()
{
    for (int i = 0; i < MAX_STUDENTS; ++i)
        studentArray[i].isEmpty = 1; // Initially, all rows are empty
}
/*******************************************      save the student Functions   ***********************/
// Function to save the student array to a CSV/text file
void saveToCSV(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        if (!studentArray[i].isEmpty)
        {
            fprintf(file, "%d,%s,%c,%d,%d\n", studentArray[i].studentID, studentArray[i].name,
                    studentArray[i].gender, studentArray[i].age, studentArray[i].studyYear);
        }
    }

    fclose(file);
}

/*******************************************      load the student Functions   ***********************/
// Function to load the student array from a CSV/text file
void loadFromCSV(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    initializeStudentArray(); // Clear the student array before loading

    int studentID, age, studyYear;
    char name[MAX_NAME_LENGTH], gender;

    while (fscanf(file, "%d,%[^,],%c,%d,%d\n", &studentID, name, &gender, &age, &studyYear) != EOF)
    {
        strncpy(studentArray[studentID - 1].name, name, MAX_NAME_LENGTH - 1);
        studentArray[studentID - 1].name[MAX_NAME_LENGTH - 1] = '\0';
        studentArray[studentID - 1].gender = gender;
        studentArray[studentID - 1].age = age;
        studentArray[studentID - 1].studyYear = studyYear;
        studentArray[studentID - 1].studentID = studentID;
        studentArray[studentID - 1].isEmpty = 0; // Set as filled
    }

    fclose(file);
}
