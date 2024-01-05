#include "main.h"

void addStdnt(Student* students[], int* count)
{
    // Check if maximum limit of students is reached
    if (*count >= MAX_STUDENTS)
    {
        printf("Maximum limit of students reached.\n");
        return;
    }
      //using file pointer to handle the files 
    FILE* fp = fopen("students.txt", "a");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    // Allocate memory for a new Student
    Student* newStudent = (Student*)malloc(sizeof(Student));

    int isValidInput = 0;

    while (!isValidInput)
    {
        printf("Enter name: ");
        scanf(" %[^\n]s", newStudent->name);
        isValidInput = validateName(newStudent->name);

        if (!isValidInput)
        {
            printf("Invalid input. Name should not contain numbers.\n");
        }
        else
        {
            fprintf(fp, "Name: %s\n", newStudent->name);
        }
    }

    isValidInput = 0;

    while (!isValidInput)
    {
        printf("Enter email: ");
        scanf(" %[^\n]s", newStudent->email);
        isValidInput = validateEmail(newStudent->email);

        if (!isValidInput)
        {
            printf("Invalid input. Email should be in the format 'abc@gmail.com'.\n");
        }
        else
        {
            // Check if email already exists
            for (int i = 0; i < *count; i++)
            {
                if (strcmp(newStudent->email, students[i]->email) == 0)
                {
                    printf("Email already exists. Please enter a different email.\n");
                    isValidInput = 0;
                    break;
                }
            }

            fprintf(fp, "Email: %s\n", newStudent->email);
        }
    }

    isValidInput = 0;

    while (!isValidInput)
    {
        printf("Enter course (CSE, ECE, EEE, MECH, CIVIL): ");
        scanf(" %[^\n]s", newStudent->course);
        isValidInput = validateCourse(newStudent->course);

        if (!isValidInput)
        {
            printf("Invalid input. Course should be one of the following: CSE, ECE, EEE, MECH, CIVIL.\n");
        }

        fprintf(fp, "Course: %s\n", newStudent->course);
    }

    isValidInput = 0;

    while (!isValidInput)
    {
        printf("Enter phone number: ");
        scanf(" %[^\n]s", newStudent->phone);
        isValidInput = validatePhoneNumber(newStudent->phone);

        if (!isValidInput)
        {
            printf("Invalid input. Phone number should contain exactly 10 digits.\n");
        }
        else
        {
            // Check if phone number already exists
            for (int i = 0; i < *count; i++)
            {
                if (strcmp(newStudent->phone, students[i]->phone) == 0)
                {
                    printf("Phone number already exists. Please enter a different phone number.\n");
                    isValidInput = 0;
                    break;
                }
            }

            fprintf(fp, "Phone Number: %s\n", newStudent->phone);
        }
    }
    printf("fp,\n");

    // Assign an ID to the new student
    newStudent->id = *count + 1;

    // Add the new student to the array of students
    students[*count] = newStudent;

    // Increment the count of students
    (*count)++;

    // Close the file after writing
    fclose(fp);

    printf("Student added successfully.\n");
}
