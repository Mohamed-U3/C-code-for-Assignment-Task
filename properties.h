#ifndef PROPERTIES_H_INCLUDED
#define PROPERTIES_H_INCLUDED

#define MAX_NAME_LENGTH 51 // Maximum length of the name, including the null terminator
#define MAX_STUDENTS 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char gender;
    char age;
    char studyYear;
    int studentID;
    int isEmpty; // Flag to indicate if the row is empty (0 = filled, 1 = empty)
} Student;
Student studentArray[MAX_STUDENTS];

//Function Declaration
void initializeStudentArray();
void saveToCSV(const char *filename);
void loadFromCSV(const char *filename);

#endif // PROPERTIES_H_INCLUDED
