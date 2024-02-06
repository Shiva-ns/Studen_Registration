/*The function "displayStudents" prints the information of all students in an array. 
It checks if there are any students to display and then iterates over each student.
prints their ID, name, email, course, and phone number. */

#include "main.h"

#define PAGE_SIZE 5 // Number of students to display per page

void readStudentsFromFile(Student* students[], int* count) {
    FILE* fp = fopen("students.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    while (fscanf(fp, "Name: %[^\n]\nEmail: %s\nCourse: %[^\n]\nPhone Number: %[^\n]\n\n", students[*count]->name, students[*count]->email, students[*count]->course, students[*count]->phone) == 4) {
        // Increment the count for each successfully read student
        (*count)++;
        // Allocate memory for the next student
        students[*count] = (Student*)malloc(sizeof(Student));
    }

    fclose(fp);
}

void displayStdnt(Student* students[], int count) {
    // Check if there are no students to display
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    // Calculate the number of pages
    int numPages = (count + PAGE_SIZE - 1) / PAGE_SIZE;

    // Iterate over each page
    for (int currentPage = 1; currentPage <= numPages; currentPage++) {
        int startIdx = (currentPage - 1) * PAGE_SIZE;
        int endIdx = startIdx + PAGE_SIZE - 1;
        endIdx = (endIdx < count) ? endIdx : count - 1;

        // Print the header for the student list to the console
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
}

