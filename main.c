
/*The main function serves as the entry point for the Student Record System program. 
It provides a  interface for the user to perform various operations, 
such as adding a student, displaying student's information, and exiting the program.
The program uses an array to store pointers to Student objects and keeps track of the number of students using the count variable. */

#include "main.h"
#include"student.c"
#include"add.c"
#include"display.c"
#include "search.c"
#include "save.c"
#include "modify.c"


//Entry point of the program
int main() {     
    Student *students[MAX_STUDENTS]; // Array of structures pointer 
    int count = 0; //Variable to keep track of the number of students
    loadStudentsFromFile(students, &count); // Load student data from a file into the array

    int choice; // Variable to store user's choice
    int searchId, deleteId; // Variables for searching and deleting students
    char filterCourse[MAX_COURSE_LENGTH]; // Variable to store a course for filtering
    char email[MAX_EMAIL_LENGTH]; // Variable to store an email address

    do {
        printf("\n--- Student Admission System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student Information\n");
        printf("5. Save Students data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user's choice

        switch (choice) {
            case 1:
                addStudent(students, &count); // Add a new student to the array
                break;
            case 2:
                displayStudents(students, count); // Display all the students in the array
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &searchId); // Read student ID to search
                searchStudent(students, count, searchId); // Search for a student with the given ID
                break;

            case 4:
                printf("Enter student ID to modify: ");
                scanf("%d", &searchId); // Read student ID to modify
                searchStudent(students, count, searchId); // Search for a student with the given ID
                if (searchId != -1) {
                    modifyStudent(students[searchId - 1]); // Modify the information of the found student
                }
                break;
            case 5:
                saveStudentsToFile(students, count); // Save the student data from the array to a file
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(1);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 9); 
    return 0;
}