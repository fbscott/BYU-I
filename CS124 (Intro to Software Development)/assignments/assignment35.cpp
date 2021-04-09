/***********************************************************************
* Program:
*    Assignment 35, Files
*    Brother Schwieder, CS124
*    
* Author:
*    Scott Currell
*    
* Summary: 
*    Write two functions (computeLetterGrade() and computeGradeSign()) and a
*    single driver program to test them.
*
*    Estimated:  1.5 hrs
*    Actual:     1 hrs
*
* Please describe briefly what was the most difficult part:
*
*    Not bad. I got this pretty easily for once :)
************************************************************************/

#include <iostream>
using namespace std;

char computeLetterGrade(int numGrade);
char computeGradeSign(int numGrade);

/**
 * MAIN
 * Determine the number of given letters are in a given text string.
 *    INPUT: letter (from user), text (string from user)
 */
int main()
{
   // get number grade (e.g., 85)
   int numGrade;
   cout << "Enter number grade: ";
   cin >> numGrade;

   cout << numGrade << "% is "
        << computeLetterGrade(numGrade)
        << computeGradeSign(numGrade)
        << endl;

}

/**
 * COMPUTE LETTER GRADE
 * Return the letter grade from a number grade.
 *    INPUT:   number grade (e.g., 85)
 *    OUTPUT:  grade letter (e.g, B)
 */
char computeLetterGrade(int numGrade)
{
   char letter;

   switch(numGrade - (numGrade % 10))
   {
      case 100:
      case 90:
         letter = 'A';
         break;
      case 80:
         letter = 'B';
         break;
      case 70:
         letter = 'C';
         break;
      case 60:
         letter = 'D';
         break;
      default:
         letter = 'F';
   }

   return letter;
}

/**
 * COMPUTE GRADE SIGN
 * Return the grade sign (+ or -) from a number grade.
 *    INPUT:   number grade (e.g., 85)
 *    OUTPUT:  grade sign (+ or -)
 */
char computeGradeSign(int numGrade)
{
   char sign = '*';
   int onesPlace = numGrade % 10;
   
   if(numGrade < 93 && numGrade > 60)
   {
      if(onesPlace < 3)
      {
         sign = '-';
      }
      else if(onesPlace > 6)
      {
         sign = '+';
      }
   }

   return sign;
}
