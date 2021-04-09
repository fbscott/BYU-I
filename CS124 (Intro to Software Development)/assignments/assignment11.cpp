/***********************************************************************
* Program:
*    Assignment 11, Output (Monthly Budget)
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a program to output my monthly budget.
*
*    Estimated:  1.0 hrs   
*    Actual:     2.5 hrs
*
* Please describe briefly what was the most difficult part:
*
*    The most difficult part of this assignment was continuing to
*    learn emacs. I found it difficult highlighting, copying, and
*    pasting code from one section to another. It made more sense to
*    do that than writing the same code over and over again.
*    Additionally, it was challenging counting out the exact number
*    of characters for the setw() method for spacing. I had to do this
*    because of the one-tab-per-line requirement.
*    Lastly, it was frustrating entering and exiting edit mode
*    to compile and view what I had written.
************************************************************************/

#include <iostream> // required for COUT
#include <iomanip>  // we will use setw() in this example
using namespace std;

/**********************************************************************
* DISPLAY MONTHLY BUDGET
* Write a program to output a monthly budget
*    INPUT:        None
*    OUTPUT:       Monthly Budget
*    EXPECTATIONS: Indented with one tab only
***********************************************************************/
int main()
{

   // configure the output to display money
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // two decimals for cents

   // First Row
   cout << "\t"
        << "Item"                      // row separator (=)
        << setw(21) << "Projected\n";  // row separator and new line
   // Second Row
   cout << "\t"
        << "============="             // row separator (=)
        << setw(13) << "==========\n"; // row separator and new line
   // Rows 3-7
   cout << "\t"
        << "Income"                    // item
        << setw(10) << "$"
        << setw(9) << 1000.0           // amount
        << endl;
   cout << "\t"
        << "Taxes"                     // item
        << setw(11) << "$"
        << setw(9) << 100.0            // amount
        << endl;
   cout << "\t"
        << "Tithing"                   // item
        << setw(9) << "$"
        << setw(9) << 100.0            // amount
        << endl;
   cout << "\t"
        << "Living"                    // item
        << setw(10) << "$"
        << setw(9) << 650.0            // amount
        << endl;
   cout << "\t"
        << "Other"                     // item
        << setw(11) << "$"
        << setw(9) << 90.0             // amount
        << endl;
   // Eighth Row
   cout << "\t"
        << "============="             // row separator (=)
        << setw(13) << "==========\n"; // row separator and new line
   // Ninth Row
   cout << "\t"
        << "Delta"                     // balance
        << setw(11) << "$"
        << setw(9) << 60.0             // amount
        << endl;
   
   return 0;
}
