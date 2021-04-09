/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a program that prompts the user for his or her income, taxes,
*    expenses, etc. and display the results on the screen in a table.
*
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*
* Please describe briefly what was the most difficult part:
*
*    To be honest, the most difficult part of this project was just figuring
*    out what to do. The instructions in the book are very poor and the 
*    assignment description online isn't any better. I hope further projects
*    have better documentation and/or instructions.
************************************************************************/

#include <iostream>
#include <iomanip>  // we will use setw() in this example
using namespace std;

/**********************************************************************
* MONTHLY BUDGET
* Prompt the user for input and display the input back in a table.
*    INPUT:    User's monthly income, budgeted living expenses, actual living
*              expenses, actual taxes withheld, actual tithe offerings, and
*              actual other expenses.
*    OUTPUT:   User's budgeted and actual income, taxes, tithing, living and
*              other expenses.
***********************************************************************/
int main()
{

   // use "double" to account for decimals
   // income
   double income;
   // budgeted
   double budgetedTaxes       = 0;
   double budgetedTithing     = 0;
   double budgetedExpenses    = 650;
   double budgetedOther       = 0;
   double budgetedDifference  = 0;
   // actual
   double actualTaxes;
   double actualTithing;
   double actualExpenses;
   double actualOther;
   double actualDifference    = 0;

   // User instructions
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";

   // prompt the user for his or her monthly income
   cout << "\t" // tab before prompt
        << "Your monthly income: ";

   // write user-submitted value to "income" variable
   cin >> income;

  // prompt the user for his or her budgeted living expenses
   cout << "\t" // tab before prompt
        << "Your budgeted living expenses: ";

   // write user-submitted value to "budgetedExpenses" variable
   cin >> budgetedExpenses;

  // prompt the user for his or her actual living expenses
   cout << "\t" // tab before prompt
        << "Your actual living expenses: ";

   // write user-submitted value to "actualExpenses" variable
   cin >> actualExpenses;

  // prompt the user for his or her actual taxes withheld
   cout << "\t" // tab before prompt
        << "Your actual taxes withheld: ";

   // write user-submitted value to "actualTaxes" variable
   cin >> actualTaxes;

  // prompt the user for his or her actual tithe offerings
   cout << "\t" // tab before prompt
        << "Your actual tithe offerings: ";

   // write user-submitted value to "actualTithing" variable
   cin >> actualTithing;

  // prompt the user for his or her actual other expenses
   cout << "\t" // tab before prompt
        << "Your actual other expenses: ";

   // write user-submitted value to "actualOther" variable
   cin >> actualOther;

   // New line before table output
   cout << "\n";

   // configure the output to display money for monthly income
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // two decimals for cents

   // Display the results as a table
   // Table summary
   cout << "The following is a report on your monthly expenses\n";
   // Table headers
   cout << "\t"
        << "Item"
        << setw(24) << "Budget"
        << setw(17) << "Actual\n";
   // row separator (=)
   cout << "\t"
        << "=============== =============== ===============\n";
   // User-defined entries (next five "cout" commands)
   cout << "\t"
        << "Income"
        << setw(11) << "$"
        << setw(11) << income
        << setw(5) << "$"
        << setw(11) << income
        << "\n";
   cout << "\t"
        << "Taxes"
        << setw(12) << "$"
        << setw(11) << budgetedTaxes
        << setw(5) << "$"
        << setw(11) << actualTaxes
        << "\n";
   cout << "\t"
        << "Tithing"
        << setw(10) << "$"
        << setw(11) << budgetedTithing
        << setw(5) << "$"
        << setw(11) << actualTithing
        << "\n";
   cout << "\t"
        << "Living"
        << setw(11) << "$"
        << setw(11) << budgetedExpenses
        << setw(5) << "$"
        << setw(11) << actualExpenses
        << "\n";
   cout << "\t"
        << "Other"
        << setw(12) << "$"
        << setw(11) << budgetedOther
        << setw(5) << "$"
        << setw(11) << actualOther
        << "\n";
   // row separator (=)
   cout << "\t"
        << "=============== =============== ===============\n";
   // End calculations (balance/difference)
   cout << "\t"
        << "Difference"
        << setw(7) << "$"
        << setw(11) << budgetedDifference
        << setw(5) << "$"
        << setw(11) << actualDifference
        << "\n";

   return 0;
}
