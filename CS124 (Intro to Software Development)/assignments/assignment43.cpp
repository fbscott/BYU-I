/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    This program will display the words to the song Dem Bones by
*    using the string class
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib> // for atof()
using namespace std;

/**********************************************************************
 * MAIN
 * Parse the command line and call functions to do the hard work...
 ***********************************************************************/
int main(int argc, char ** argv) // recieve args from command line
{

   char meters[] = "0.3048";  // meters per foot

   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(1);         // two decimals for cents
   
   for (int i = 1; i < argc; i++) // standard command line loop
   {
      cout << atof(argv[i])                // string to double
           << " feet is "
           << atof(meters) * atof(argv[i]) // string to double
           << " meters\n";
   }

   return 0;
}
