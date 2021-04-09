/******************************************************************************
* Program:
*    Test 1, Unit 1 Practice Test
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Prompt the user for his/her grade. Output a pass message if grade > 59 or
*    a fail message if 59 or below.
******************************************************************************/

#include <iostream>
using namespace std;

// prototypes
int getGrade(); // prompt for grade
void displayPassed();  // pass response
void diaplayFailed();  // fail response

/******************************************************************************
* PASS OR FAIL MESSAGE
* Prompt the user for his/her grade and display a pass/fail message.
*    INPUT:    User's grade
*    OUTPUT:   Pass/Fail message
******************************************************************************/
int main()
{
   // get the user's grade
   int grade = getGrade();

   if (grade > 59)
      displayPassed();
   else
      diaplayFailed();

   return 0;
}

/******************************************************************************
* GET USER'S GRADE
* Prompt the user for his/her grade.
*    INPUT: none
*    OUTPUT: user's grade
******************************************************************************/
int getGrade()
{
   // prompt user for grade
   cout << "What was your grade on the last test? ";

   // user's grade
   int grade = 0;
   // update grade
   cin >> grade;

   return grade;
}

/******************************************************************************
* PASS MESSAGE
* Message to display to user if he/she passes the test.
*    INPUT: none
*    OUTPUT: pass message
******************************************************************************/
void displayPassed()
{
   cout << "You passed the test.\n";
   return;
}

/******************************************************************************
* FAIL MESSAGE
* Message to display to user if he/she fails the test.
*    INPUT: none
*    OUTPUT: fail message
******************************************************************************/
void diaplayFailed()
{
   cout << "You failed the test.\n";
   return;
}
