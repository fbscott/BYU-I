/******************************************************************************
* Program:
*    Assignment 16, IF Statements
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Collect the user's annual income. Based on that income, output the
*    user's tax bracket.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.3 hrs
*
* Please describe briefly what was the most difficult part:
*
*    This one was a piece of cake. No issues to report. Also, I'm getting
*    the hang of emacs :)
******************************************************************************/

#include <iostream>
using namespace std;

double computeTax(double income);

/******************************************************************************
 * Main will call computeTax() and display an appropriate tax bracket
 * to the user based on his/her income.
******************************************************************************/
int main()
{
   // user's income
   double income = 0;
   // prompt for income
   cout << "Income: ";
   cin >> income;

   cout << "Your tax bracket is " << computeTax(income) << "%\n";

   return 0;
}

/******************************************************************************
* COMPUTE TAXES
* Determines which tax bracket to return based on user's income.
*    INPUT: User Income
*    OUTPUT: User's tax bracket
******************************************************************************/
double computeTax(double income)
{
   // return appropriate tax bracket depending on income
   if (income < (double)15100.0)
      return 10;
   else if (income < (double)61300.0)
      return 15;
   else if (income < (double)123700.0)
      return 25;
   else if (income < (double)188450.0)
      return 28;
   else if (income < (double)336550.0)
      return 33;
   else
      return 35;
}
