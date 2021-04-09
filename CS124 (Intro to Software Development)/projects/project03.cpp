/***********************************************************************
* Program:
*    Project 03, Monthly Budget
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a program that prompts the user for his or her income, taxes,
*    expenses, etc. and display the results on the screen in a table.
*
*    Estimated:  2.0 hrs   
*    Actual:     5.0 hrs
*
* Please describe briefly what was the most difficult part:
*
*    The instructions in the book and assignment description online are VERY
*    poor. It was exceedingly difficult to figure out what to do on this
*    portion of the project. All I had to go on was basically, "fix what went
*    wrong from last week and refactor into functions." Those are TERRIBLE
*    instructions. We haven't learned enough by this point to go off of such
*    little detail. I was beyond frustrated with this project. I had to resort
*    to many developer forum threads and two online sessions with instructors
*    during office hours to get a handle on the project. I hope future projects
*    have better instruction.
************************************************************************/

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
void display(double income,
             double budgetLiving, double actualLiving,
             double budgetTax, double actualTax,
             double budgetTithing, double actualTithing,
             double budgetOther, double actualOther,
             double budgetTotal, double actualTotal);

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

   // User instructions
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";

   // use "double" to account for decimals
   // income
   double income        = getIncome();
   // budgeted
   double budgetLiving  = getBudgetLiving();
   double budgetTax     = 0;
   double budgetTithing = (float)(income * 0.1);
   double budgetOther   = (float)(income - budgetTax - budgetTithing - 
                                  budgetLiving);
   double budgetTotal   = 0;
   // actual
   double actualLiving  = getActualLiving();
   double actualTax     = getActualTax();
   double actualTithing = getActualTithing();
   double actualOther   = getActualOther();
   double actualTotal   = (float)(income - actualLiving - actualTax -
                                  actualTithing - actualOther);

   display(income,
           budgetLiving, actualLiving,
           budgetTax, actualTax,
           budgetTithing, actualTithing,
           budgetOther, actualOther,
           budgetTotal, actualTotal);

   return 0;

}

/**********************************************************************
* GET INCOME
* Prompt the user for his/her monthly income.
*    INPUT:    User's monthly income.
*    RETURN:   User's monthly income.
***********************************************************************/
double getIncome()
{

   double income;

   // prompt the user for his/her monthly income
   cout << "\t" // tab before prompt
        << "Your monthly income: ";

   // write user-submitted value to "income" variable
   cin >> income;

   return income;
}

/**********************************************************************
* GET BUDGETED LIVING EXPENSES
* Prompt the user for his/her budgeted living expenses.
*    INPUT:    User's budgeted living expenses.
*    RETURN:   User's budgeted living expenses.
***********************************************************************/
double getBudgetLiving()
{

   double bLiving;

   // prompt the user for his or her monthly income
   cout << "\t" // tab before prompt
        << "Your budgeted living expenses: ";

   // write user-submitted value to "income" variable
   cin >> bLiving;

   return bLiving;
}

/**********************************************************************
* GET INCOME
* Prompt the user for his/her actual living expenses.
*    INPUT:    User's actual living expenses.
*    RETURN:   User's actual living expenses.
***********************************************************************/
double getActualLiving()
{

   double aLiving;

   // prompt the user for his or her monthly income
   cout << "\t" // tab before prompt
        << "Your actual living expenses: ";

   // write user-submitted value to "income" variable
   cin >> aLiving;

   return aLiving;
}

/**********************************************************************
* GET INCOME
* Prompt the user for his/her actual taxes withheld.
*    INPUT:    User's actual taxes withheld.
*    RETURN:   User's actual taxes withheld.
***********************************************************************/
double getActualTax()
{

   double aTaxes;

   // prompt the user for his or her monthly income
   cout << "\t" // tab before prompt
        << "Your actual taxes withheld: ";

   // write user-submitted value to "income" variable
   cin >> aTaxes;

   return aTaxes;
}

/**********************************************************************
* GET INCOME
* Prompt the user for his/her actual tithe offerings.
*    INPUT:    User's actual tithe offerings.
*    RETURN:   User's actual tithe offerings.
***********************************************************************/
double getActualTithing()
{

   double aTithing;

   // prompt the user for his or her monthly income
   cout << "\t" // tab before prompt
        << "Your actual tithe offerings: ";

   // write user-submitted value to "income" variable
   cin >> aTithing;

   return aTithing;
}

/**********************************************************************
* GET INCOME
* Prompt the user for his/her actual other expenses.
*    INPUT:    User's actual other expenses.
*    RETURN:   User's actual other expenses.
***********************************************************************/
double getActualOther()
{

   double expenses;

   // prompt the user for his or her monthly income
   cout << "\t" // tab before prompt
        << "Your actual other expenses: ";

   // write user-submitted value to "income" variable
   cin >> expenses;

   return expenses;
}

/**********************************************************************
* DISPLAY MONTHLY BUDGET
* Display the results as a table.
*    INPUT:    Income, taxes, tithes, etc. passed from main()
*    OUTPUT:   Income, taxes, tithes, etc. passed from main()
***********************************************************************/
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
