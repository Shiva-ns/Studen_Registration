/*The student.h header file defines the structure of a student and declares function prototypes for operations on student records, 
such as adding, displaying, searching, deleting, and saving/loading students.
It also includes validation functions for fields like name, email, course, and phone number.*/

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 10
#define MAX_COURSE_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 10
#define MAX_STATUS_LENGTH 20

// Define constants for maximum limits of various fields

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char course[MAX_COURSE_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];

    //char *text_fname;
}Student;

// Function prototypes for the validation functions
int validateName(const char* name);
int validateEmail(const char* email);
int validateCourse(const char* course);
int validatePhoneNumber(const char* phoneNumber);


// Function prototypes for the various operations on student records
void addStdnt(Student* students[], int* count);
void displayStdnt(Student* students[], int count);
//void search_student(Student* student[], int count, int searchID);

#endif







