/***********************************************************************
* Program:
*    Checkpoint 03b, exceptions
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// prototypes
int promptForNumber();
// void displayNumber(const int * number);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{

   int number = promptForNumber();

   cout << "The number is " << number << '.' << endl;

   return 0;
}

int promptForNumber()
{
   int number;

   cout << "Enter a number: ";
   cin >> number;

   while (cin.fail())
   {
      cin.clear();
      // skip over up to 256 characters
      // or until a newline char '\n' is encountered
      cin.ignore(256, '\n');
      cout << "Invalid input." << endl << "Enter a number: ";
      cin >> number;
   }

   return number;
}
