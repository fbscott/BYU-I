/*****************************************************************************
* Program:
*    Assignment 41, Files
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Allocating memory exorcise.
*
*    Estimated:  2 hrs   
*    Actual:     3 hrs
*
* Please describe briefly what was the most difficult part:
*
*    Just the newness of pointers and memory allocation. Getting used to it.
*****************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

int getNumChars();
int * allocate(const int numItems);
char promptForString(char userProvidedString[]);
void displayString(char string[], int numChars);

/**
 * MAIN
 * Call subroutines
 */
int main()
{

   // prompt the user for the number of characters in a string
   int numChars = getNumChars();
   // allocated memory for the list array
   int * list = allocate(numChars);

   // end program if list NULL
   if (list == NULL)
   {
      return 0;
   }

   // prompt the user for the string using getline()
   char userString[256];
   promptForString(userString);

   // display the string back to the user, but only the length provided
   displayString(userString, numChars);

   // release the memory and check for allocation failures
   delete [] list;
   list = NULL;

   return 0;
}

/**
 * GET NUMBER OF CHARACTERS
 * Prompt the user for the number of characters
 */
int getNumChars()
{
   int numChars;

   cout << "Number of characters: ";
   cin >> numChars;

   return numChars;
}

/**
 * ALLOCATE MEMORY
 * Allocate memory for an array with of a specific size
 */
int * allocate(const int numItems)
{

   // allocate the necessary memory
   int * p = new(nothrow) int[numItems];

   // failed to allocate if p == NULL
   if (!p)
   {
      cout << "Allocation failure!\n";
   }

   return p;
}

/**
 * PROMPT FOR STRING
 * Ask the user for a string for comparison
 */
char promptForString(char userProvidedString[])
{
   cout << "Enter Text: ";
   cin.ignore();
   cin.getline(userProvidedString, 256);

   return * userProvidedString;
}

/**
 * DISPLAY STRING
 * Display string back to the user
 */
void displayString(char string[], int numChars)
{
   cout << "Text: ";

   for (int i = 0; i < numChars; i++)
   {
      cout << string[i];
   }

   cout << '\n';

   return;
}
