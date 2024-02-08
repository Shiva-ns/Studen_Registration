/*The function "displayStudents" prints the information of all students in an array. 
It checks if there are any students to display and then iterates over each student.
prints their ID, name, email, course, and phone number. */

#include "main.h"

#define PAGE_SIZE 5 // Number of students to display per page

void displayStudents(Student* students[], int count) {
    // Check if there are no students to display
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    // Calculate the number of pages
    int numPages = (count + PAGE_SIZE - 1) / PAGE_SIZE;

    int currentPage = 1; // Current page being displayed
    int startIdx = (currentPage - 1) * PAGE_SIZE; // Index of the first student on the current page
    int endIdx = startIdx + PAGE_SIZE - 1; // Index of the last student on the current page
    endIdx = (endIdx < count) ? endIdx : count - 1; // Adjust the end index if it exceeds the number of students

    // Print the header for the student list
    printf("Student List (Page %d/%d, Total Students: %d):\n", currentPage, numPages, count);

    // Iterate over each student and display their information for the current page
    for (int i = startIdx; i <= endIdx; i++) {
        
        printf("\nStudent ID: %d\n", students[i]->id);
        printf("Name: %s\n", students[i]->name);
        printf("Email: %s\n", students[i]->email);
        printf("Course: %s\n", students[i]->course);
        printf("Phone Number: %s\n", students[i]->phone);
    }
}
   