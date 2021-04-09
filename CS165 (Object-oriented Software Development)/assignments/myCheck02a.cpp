/***********************************************************************
* Program:
*    Checkpoint 02a, structs
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// structures
struct Student
{
   string firstName;
   string lastName;
   int id;
};

// prototypes
void displayStudent(const Student & info);
void promptForStudentInfo(Student & info);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // declare "studentInfo" as a "Student" data type
   // Note: this variable is NOT initialized
   Student studentInfo;

   // prompt for student's info
   promptForStudentInfo(studentInfo);
   // display student's info
   displayStudent(studentInfo);

   return 0;
}

/**
 * DISPLAY STUDENT INFO
 * Display user-provided student info to the screen
 *    INPUT: studentInfo [Structure]
 */
void displayStudent(const Student & info)
{
   cout << "Your information:\n"
        << info.id
        << " - "
        << info.firstName
        << " "
        << info.lastName
        << endl;

   return;
}

/**
 * PROMPT STUDENT FOR INFO
 * Ask the student for his/her first and last name
 * as well as student ID
 *    INPUT: studentInfo [Structure]
 */
void promptForStudentInfo(Student & info)
{
   cout << "Please enter your first name: ";
   cin >> info.firstName;
   cout << "Please enter your last name: ";
   cin >> info.lastName;
   cout << "Please enter your id number: ";
   cin >> info.id;
   cout << endl;
}
