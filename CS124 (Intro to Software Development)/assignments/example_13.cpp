/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate how to compute change using the modulus operator
 ************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * main(): Just one function for this demo
 ***********************************************************************/
int main()
{
   // get user input
   cout << "Please enter a positive dollar amount (ex: 4.23): ";
   double dollars;
   cin >> dollars;
   
   // convert it from dollars to cents
   int cents = (int)(dollars * 100.00);

   // as a challenge, do the same for $5, $10, $20, and $50
   
   // DOLLARS
   cout << "\tDollars:   " << cents / 100 << endl;
   cents %= 100;

   // QUARTERS
   cout << "\tQuarters:  " << cents / 25 << endl;
   cents %= 25;

   // DIMES
   cout << "\tDimes:     " << cents / 10 << endl;
   cents %= 10;
   
   // NICKLES
   cout << "\tNickles:   " << cents / 5 << endl;
   cents %= 5;
   
   // PENNIES
   cout << "\tPennies:   " << cents << endl;
   
   return 0;
}
