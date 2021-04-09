/***********************************************************************
* Program:
*    Assignment 31, Files
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
#include <cassert>
using namespace std;

void getGrades(int grades[], int numGrades);
float averageGrades(int grades[]);

/*********************************************************************
 * FIND GRADE AVERAGE
 * Prompt the user for a file containing grades and calculate the average.
 *********************************************************************/
int main()
{
   int grades[10]; // grades array

   getGrades(grades, 10);

   int average = averageGrades(grades);

   // if there are no completed assignments
   if(average == 0)
   {
      cout << "Average Grade: ---%\n";
   // but, if there are . . .
   } else {
      cout << "Average Grade: " << average << "%\n";
   }

   return 0;
}

/*********************************************************************
 * GET GRADES
 * Prompt the user for ten grades and update the grades array via
 * pass-by-reference.
 *    INPUT: array of grades, number of grades
 *    OUTPUT: grades array
 ********************************************************************/
void getGrades(int grades[], int numGrades)
{
   for(int iGrades = 0; iGrades < numGrades; iGrades++)
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
float averageGrades(int grades[])
{
   int sum = 0;            // sum of grades
   int iGrades = 0;        // iterator (number of grades)
   int numIncomplete = 0;  // number of incomplete assignments
   float average = 0;      // average of grades array

   for(iGrades; iGrades < 10; iGrades++)
   {
      // if completed assignment
      if(grades[iGrades] <= 0)
      {
         // update incomplete assignment count
         numIncomplete++;
      } else
      {
         // update the sum of all grades
         sum += grades[iGrades];
      }
   }

   // calculate average only if sum > 0
   if(sum > 0)
   {
      average = ((float)sum / (float)(iGrades - numIncomplete));
   }

   return average;
}
