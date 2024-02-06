/* The given code defines four functions for validating different aspects of student information 
validateName: Checks if the given name is valid by iterating over each character and ensuring that it does not contain digits or punctuation marks. 

validateEmail: Validates the format of the email by checking if it contains an "@" symbol and a "." symbol in the correct order. 

validateCourse: Validates the course name by checking if it contains only alphabetic characters and matches one of the predefined valid courses. 

validatePhoneNumber: Validates the format of the phone number by checking if it consists of exactly 10 digits. */
#include "main.h"

//validate the name of a student
int validateName(const char* name)
{

    for (int i = 0; i < strlen(name); i++)
    {
    // Check if the character is a digit
        if (isdigit(name[i])) 
        {
            return 0; // Name should not contain numbers, so return 0 (false)
        }
        // Check if the character is a digit or a punctuation mark
        else if(isdigit(name[i]) || ispunct(name[i]))
        {
            return 0; 
        }
    }
    return 1;
}

// Function to validate  email
int validateEmail(const char* email)
{
    int foundAtSymbol = 0;
    int foundDotSymbol = 0;
    int atSymbolIndex = -1;
    int dotSymbolIndex = -1;

 //validate email
    for (int i = 0; i < strlen(email); i++)
    {
        // Check if the character is an '@' symbol
        if (email[i] == '@') 
        {
            foundAtSymbol = 1;
            atSymbolIndex = i;
        }
        // Check if the character is a '.' symbol
        if (email[i] == '.') {
            foundDotSymbol = 1;
            dotSymbolIndex = i;
        }
    }
    if (foundAtSymbol && foundDotSymbol && atSymbolIndex < dotSymbolIndex && dotSymbolIndex < strlen(email) - 1)
    {
        return 1;
    } else {
        return 0;
    }
}



// Function to validate the course name
int validateCourse(const char* course) 
{
    const char* validCourses[] = { "CSE", "ECE", "EEE", "MECH", "CIVIL" };     //array of caharecter pointer 
    const int numValidCourses = sizeof(validCourses) / sizeof(validCourses[0]);

 
    for (int i = 0; i < strlen(course); i++)
    {
       // Check if the character is a digit
        if (isdigit(course[i]))
        {
            return 0; // Course should not contain numbers, so return 0 (false)
        }
    }

    // Iterate over each valid course in the list
    for (int i = 0; i < numValidCourses; i++)
    {
    // Check if the course matches any of the valid courses
        if (strcmp(course, validCourses[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// Function to validate the format of a phone number
int validatePhoneNumber(const char* phoneNumber)
{
 // Check if the length of the phone number is not equal to 10
    if (strlen(phoneNumber) != 10) {
        return 0;
    }
    // Iterate over each character in the phone number string
    for (int i = 0; i < strlen(phoneNumber); i++)
    {
           // Check if the character is not a digit
        if (!isdigit(phoneNumber[i]))
        {
            return 0; // Phone number should only contain digits, so return 0 (false)
        }
    }
    return 1;    // If all characters are digits and the length is 10, return 1 (true) to indicate a valid phone number
}
