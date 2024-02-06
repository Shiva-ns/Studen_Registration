/*The main function serves as the entry point for the Student Record System program. 
It provides a  interface for the user to perform various operations, 
such as adding a student, displaying student's information, and exiting the program.
The program uses an array to store pointers to Student objects and keeps track of the number of students using the count variable. */

#include "main.h"
#include"student.c"
#include"add.c"
#include"display.c"
#include "search.c"
//Entry point of the program
int main() {     
    Student *students[MAX_STUDENTS]; // Array of structures pointer 
    int count = 0; //Variable to keep track of the number of students
   // loadStudentsFromFile(students, &count);

    int choice; //variable to select the user's choise
    int searchId;
    //int  deleteId;
    char filterCourse[MAX_COURSE_LENGTH]; //to store a course for filtering
    char email[MAX_EMAIL_LENGTH]; //to store an email address

    while(choice != 9){
        printf("\n--- Student Admission System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Modify Student Information\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
       if (scanf("%d", &choice) != 1) { // Check if the input is not an integer
            printf("Invalid input. Please enter a number.\n");
            scanf("%*s"); // Clear the input buffer
            continue; // Skip the rest of the loop and prompt the user again
        }
        switch (choice) {  
            case 1:
                addStdnt(students, &count); //Add a new student to the array
                break;
            case 2:
                displayStdnt(students, count);// Display all the students
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &searchId);
                search_student(students, count, searchId);
                break;
            /* case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &deleteId);
                deleteStudent(students, &count, deleteId);
                break;6
            case 5:
                printf("Enter student ID to modify: ");1
                
                scanf("%d", &searchId);
                searchStudent(students, count, searchId);
                if (searchId != -1) {
                    modifyStudent(students[searchId - 1]);
                }
                break;*/
           case 6:
                printf("Exiting the program.\n");//terminate the program
                exit(1);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }  // Continue the loop until the user chooses to exit
    return 0; //successfully terminte the program
}

