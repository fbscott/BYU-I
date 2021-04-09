/*****************************************************************************
* Program:
*    Project 04, Monthly Budget
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
*    I didn't realize that the instructions for the WHOLE project were spread
*    across pages 101-106 (This is what was tripping me up from the last
*    project). Now that I see how the book is structured, I should fare better
*    the next time around. Other than that, it went pretty smoothly.
*****************************************************************************/

#include <iostream>
#include <iomanip>  // we will use setw() in this example
using namespace std;

// prototypes
double getIncome();
double getBudgetLiving();
double getActualLiving();
double getActualTax();
double getActualTithing();
double getActualOther();
double computeTax(double income);
void display(double income,
             double budgetLiving, double actualLiving,
             double budgetTax, double actualTax,
             double budgetTithing, double actualTithing,
             double budgetOther, double actualOther,
             double budgetTotal, double actualTotal);

/*****************************************************************************
* MONTHLY BUDGET
* Prompt the user for input and display the input back in a table.
*    INPUT:    User's monthly income, budgeted living expenses, actual living
*              expenses, actual taxes withheld, actual tithe offerings, and
*              actual other expenses.
*    OUTPUT:   User's budgeted and actual income, taxes, tithing, living and
*              other expenses.
*****************************************************************************/
int main()
{

   // User instructions
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";

   // use "double" to account for decimals
   // income
   double income        = getIncome();
   // budgeted
   double budgetLiving  = getBudgetLiving();
   double budgetTax     = computeTax(income);
   double budgetTithing = income * 0.1;
   double budgetOther   = income - budgetTax - budgetTithing - 
                          budgetLiving;
   double budgetTotal   = 0;
   // actual
   double actualLiving  = getActualLiving();
   double actualTax     = getActualTax();
   double actualTithing = getActualTithing();
   double actualOther   = getActualOther();
   double actualTotal   = income - actualLiving - actualTax -
                          actualTithing - actualOther;

   display(income,
           budgetLiving, actualLiving,
           budgetTax, actualTax,
           budgetTithing, actualTithing,
           budgetOther, actualOther,
           budgetTotal, actualTotal);

   return 0;

}

/*****************************************************************************
* GET INCOME
* Ask the user for his/her monthly income and return the value.
*    INPUT:    User's monthly income.
*    RETURN:   User's monthly income.
*****************************************************************************/
double getIncome()
{

   double income;

   // prompt the user for his/her monthly income
   cout << "\t" << "Your monthly income: ";

   // update income with what the user entered
   cin >> income;

   return income;
}

/*****************************************************************************
* GET BUDGETED LIVING EXPENSES
* Ask the user for his/her budgeted living expenses and return the value.
*    INPUT:    User's budgeted living expenses.
*    RETURN:   User's budgeted living expenses.
*****************************************************************************/
double getBudgetLiving()
{

   double bLiving;

   // prompt the user for his/her budgeted living expenses
   cout << "\t" << "Your budgeted living expenses: ";

   // update bLiving with what the user entered
   cin >> bLiving;

   return bLiving;
}

/*****************************************************************************
* GET ACTUAL LIVING EXPENSES
* Ask the user for his/her actual living expenses and return the value.
*    INPUT:    User's actual living expenses.
*    RETURN:   User's actual living expenses.
*****************************************************************************/
double getActualLiving()
{

   double aLiving;

   // prompt the user for his/her actual living expenses
   cout << "\t" << "Your actual living expenses: ";

   // update aLiving with what the user entered
   cin >> aLiving;

   return aLiving;
}

/*****************************************************************************
* GET ACTUAL TAXES
* Ask the user for his/her actual taxes withheld and return the value.
*    INPUT:    User's actual taxes withheld.
*    RETURN:   User's actual taxes withheld.
*****************************************************************************/
double getActualTax()
{

   double aTaxes;

   // prompt the user for his/her actual taxes withheld
   cout << "\t" << "Your actual taxes withheld: ";

   // update aTaxes with what the user entered
   cin >> aTaxes;

   return aTaxes;
}

/*****************************************************************************
* GET ACTUAL TITHING
* Ask the user for his/her actual tithe offerings and return the value.
*    INPUT:    User's actual tithe offerings.
*    RETURN:   User's actual tithe offerings.
*****************************************************************************/
double getActualTithing()
{

   double aTithing;

   // prompt the user for his/her actual tithe offerings
   cout << "\t" << "Your actual tithe offerings: ";

   // update aTithing with what the user entered
   cin >> aTithing;

   return aTithing;
}

/*****************************************************************************
* GET ACTUAL OTHER EXPENSES
* Ask the user for his/her actual other expenses and return the value.
*    INPUT:    User's actual other expenses.
*    RETURN:   User's actual other expenses.
*****************************************************************************/
double getActualOther()
{

   double expenses;

   // prompt the user for his/her actual other expenses
   cout << "\t" << "Your actual other expenses: ";

   // update expenses with what the user entered
   cin >> expenses;

   return expenses;
}

/*****************************************************************************
 * COMPUTE TAX
 * Convert user's monthly income to annual income. Determine tax liability
 * based on that value.
 *    INPUT: User's monthly income
 *    OUTPUT: User's tax liability
 *****************************************************************************/
double computeTax(double income)
{
   // multiply income by 12 for yearly figure
   double yearlyIncome = (income * 12.0);
   double yearlyTax = 0;

   // determine which tax amount to use
   // 10% bracket
   if (yearlyIncome > 0 && yearlyIncome < 15100.0)
   {
      yearlyTax = (yearlyIncome * 0.10);
   }
   // 15% bracket
   else if (yearlyIncome < 61300.0)
   {
      yearlyTax = (1510.0 + ((yearlyIncome - 15100.0) * 0.15));
   }
   // 25% bracket
   else if (yearlyIncome < 123700.0)
   {
      yearlyTax = (8440.0 + ((yearlyIncome - 61300.0) * 0.25));
   }
   // 28% bracket
   else if (yearlyIncome < 188450.0)
   {
      yearlyTax = (24040.0 + ((yearlyIncome - 123700.0) * 0.28));
   }
   // 33% bracket
   else if (yearlyIncome < 336550.0)
   {
      yearlyTax = (42170.0 + ((yearlyIncome - 188450.0) * 0.33));
   }
   // 35% bracket
   else
   {
      yearlyTax = (91043.0 + ((yearlyIncome - 336550.0) * 0.35));
   }

   // divide tax amount by 12 for monthly amount
   double monthlyTax = (yearlyTax / 12.0);

   return monthlyTax;
}

/*****************************************************************************
* DISPLAY MONTHLY BUDGET
* Display the results as a table.
*    INPUT:    Income, taxes, tithes, etc.
*    OUTPUT:   Income, taxes, tithes, etc.
*****************************************************************************/
void display(double income,
             double budgetLiving, double actualLiving,
             double budgetTax, double actualTax,
             double budgetTithing, double actualTithing,
             double budgetOther, double actualOther,
             double budgetTotal, double actualTotal)
{

   // configure the output to display money for monthly income
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // two decimals for cents

   // Table summary, headers, and row separators
   cout << "\nThe following is a report on your monthly expenses\n"
        << "\tItem                  Budget          Actual\n"
        << "\t=============== =============== ===============\n";
   // User-defined entries (next five "cout" commands)
   cout << "\tIncome"
        << setw(11) << "$"
        << setw(11) << income
        << setw(5) << "$"
        << setw(11) << income << endl;
   cout << "\tTaxes"
        << setw(12) << "$"
        << setw(11) << budgetTax
        << setw(5) << "$"
        << setw(11) << actualTax << endl;
   cout << "\tTithing"
        << setw(10) << "$"
        << setw(11) << budgetTithing
        << setw(5) << "$"
        << setw(11) << actualTithing << endl;
   cout << "\tLiving"
        << setw(11) << "$"
        << setw(11) << budgetLiving
        << setw(5) << "$"
        << setw(11) << actualLiving << endl;
   cout << "\tOther"
        << setw(12) << "$"
        << setw(11) << budgetOther
        << setw(5) << "$"
        << setw(11) << actualOther << endl;
   // row separator (=)
   cout << "\t=============== =============== ===============\n";
   // End calculations (balance/difference)
   cout << "\tDifference"
        << setw(7) << "$"
        << setw(11) << budgetTotal
        << setw(5) << "$"
        << setw(11) << actualTotal << endl;
}
