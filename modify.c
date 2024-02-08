/*The modifyStudent function allows the user to enter new information (name, email, course, and phone number) and
updates the corresponding fields in the student structure.
The sortStudentsByName function sorts an array of student pointers based on their names in alphabetical order.
The filterStudentsByCourse function displays the information of students who are enrolled in a specific course, matching the provided course name. 
If no students are found, it displays a message indicating the absence of students with that course.*/

#include "main.h"

void modifyStudent(Student* student) {
    printf("Enter new name: ");
    scanf(" %[^\n]s", student->name);  // Read a new name from the user and store it in the student struct.

    printf("Enter new email: ");
    scanf(" %[^\n]s", student->email);  // Read a new email from the user and store it in the student struct.

    printf("Enter new course: ");
    scanf(" %[^\n]s", student->course);  // Read a new course from the user and store it in the student struct.

    printf("Enter new phone number: ");
    scanf(" %[^\n]s", student->phone);  // Read a new phone number from the user and store it in the student struct.

    printf("Student information modified successfully.\n");
}
