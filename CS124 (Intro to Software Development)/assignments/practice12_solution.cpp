/***********************************************************************
* Program:
*    Practice 1.2, Automatic grading program
*    Brother Helfrich, CS124
* Author:
*    The Key
* Summary: 
*    This program will determine if the student passed his test
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*******************************************************
 * GET GRADE
 * Prompt the user for the grade on a test and return the answer
 ******************************************************/
int getGrade()
{
   // PROMPT for the grade
   cout << "What was your grade on the last test? ";

   // GET grade
   int grade;
   cin >> grade;

   return grade;
}


/*********************************************************
 * DISPLAY PASS
 * Display the "you've passed" message
 ********************************************************/
void displayPass()
{
   cout << "You passed the test.\n";
   return;
}

/*********************************************************
 * DISPLAY FAIL
 * Display the "you've failed" message
 ********************************************************/
void displayFail()
{
   cout << "You failed the test.\n";
   return;
}

/**********************************************************
 * IS PASS
 * Is the grade a passing grade?
 *********************************************************/
bool isPass(int grade)
{
   return (grade >= 60);
}

/**********************************************************************
* Main will prompt for the grade and select the appropriate message
***********************************************************************/
int main()
{
   // GET grade
   int grade;
   grade = getGrade();

   // IF grade >= 60
   //    displayPass
   // ELSE
   //    displayFail    
   if (isPass(grade))
      displayPass();
   else
      displayFail();

   return 0;
}
