/***********************************************************************
* Program:
*    Checkpoint 03a, exceptions
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
int promptForNumber() throw(string);
// void displayNumber(const int * number);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{

   try
   {
      int number = promptForNumber();
      int * pNumber = &number;

      cout << "The number is " << number << '.' << endl;
   }
   catch (string text)
   {
      cout << "Error: " << text;
   }

   return 0;
}

int promptForNumber() throw(string)
{
   int number;

   cout << "Enter a number: ";
   cin >> number;

   if (number < 0)
   {
      throw string("The number cannot be negative.\n");
   }
   else if (number > 100)
   {
      throw string("The number cannot be greater than 100.\n");
   }
   else if (number % 2 == 1)
   {
      throw string("The number cannot be odd.\n");
   }

   return number;
}
