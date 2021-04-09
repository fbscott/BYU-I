/***********************************************************************
* Program:
*    Assignment 30, Files
*    Brother Schwieder, CS124
*    
* Author:
*    Scott Currell
*    
* Summary: 
*    Prompt the user for 10 grades, calculate the average, and print the
*    results to the screen.
*
*    Estimated:  2 hrs   
*    Actual:     1 hrs
*
* Please describe briefly what was the most difficult part:
*
*    Not bad. I got this pretty easily for once :)
************************************************************************/

#include <iostream>
using namespace std;

void getGrades(short grades[], short numGrades);
float averageGrades(short grades[]);

/*********************************************************************
 * FIND GRADE AVERAGE
 * Prompt the user for a file containing grades and calculate the average.
 *********************************************************************/
int main()
{
   short grades[10]; // grades array

   getGrades(grades, 10);

   cout << "Average Grade: " << averageGrades(grades) << "%\n";

   return 0;
}

/*********************************************************************
 * GET GRADES
 * Prompt the user for ten grades and update the grades array via
 * pass-by-reference.
 *    INPUT: array of grades, number of grades
 *    OUTPUT: grades array
 ********************************************************************/
void getGrades(short grades[], short numGrades)
{
   for(short iGrades = 0; iGrades < numGrades; iGrades++)
   {
      // prompt user for grades
      cout << "Grade " << iGrades + 1 << ": ";
      // update grades array
      cin >> grades[iGrades];
   }

   return;
}

/*********************************************************************
 * AVERAGE GRADES
 * Find the average of the grades.
 *    INPUT: array of grades
 ********************************************************************/
float averageGrades(short grades[])
{
   short sum = 0;       // sum of grades
   short iGrades = 0;   // iterator (number of grades)

   for(iGrades; iGrades < 10; iGrades++)
   {
      // update the sum of all grades
      sum += grades[iGrades];
   }

   float average = ((float)sum / iGrades); // average of grades array

   return average;
}
