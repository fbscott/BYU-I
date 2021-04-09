/***********************************************************************
* Program:
*    Assignment 12, Input & Variables
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a program that prompts the user for his or her income and displays
*    the result on the screen.
*
*    Estimated:  0.75 hrs   
*    Actual:     1.5 hrs
*
* Please describe briefly what was the most difficult part:
*
*    I continue to struggle with emacs. The most difficult part of the
*    assignment, however, trying to follow the instructions. They were unclear.
*    I had a hard time trying to figure out what to do.
************************************************************************/

#include <iostream> 
#include <iomanip>  // we will use setw() in this example
using namespace std;

/**********************************************************************
* INPUT & VARIABLES
* Prompt the user for his or her income and displays the result on the screen.
*    INPUT: User's monthly income
*    OUTPUT: User's monthly income as a decimal
***********************************************************************/
int main()
{

   double income; // use "double" to account for decimals

   // prompt the user for his income
   cout << "\t"                     // tab before prompt
        << "Your monthly income: ";

   // write user-submitted value to "income" variable
   cin >> income;

   // configure the output to display money for monthly income
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // two decimals for cents

   // display the results 
   cout << "Your income is: $"
        << setw(9) // right aligned to 9 spaces from the dollar sign.
        << income
        << "\n";

   return 0;
}
