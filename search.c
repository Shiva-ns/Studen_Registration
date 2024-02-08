/*The function "searchStudent" searches for a student with a specific ID in an array of students. 
It iterates over each student, comparing their ID with the search ID. 
If a match is found, it prints the student's information. If no matching student is found, it displays a message indicating that. */

#include "main.h"

// Function to search for a student by ID

void searchStudent(Student* students[], int count, int searchId) {
    // Iterate over each student in the array
    for (int i = 0; i < count; i++) {
        // Check if the ID of the current student matches the search ID
        if (students[i]->id == searchId) {
            // If a match is found, print the information of the student
            printf("\nStudent found:\n");
            printf("Student ID: %d\n", students[i]->id);
            printf("Name: %s\n", students[i]->name);
            printf("Email: %s\n", students[i]->email);
            printf("Course: %s\n", students[i]->course);
            printf("Phone Number: %s\n", students[i]->phone);
            return; // Return from the function, as the search is complete
        }
    }
    // If no matching student is found, print a message indicating it
    printf("Student with ID %d not found.\n", searchId);
}