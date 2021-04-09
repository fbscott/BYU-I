/***********************************************************************
* Program:
*    Checkpoint 01b, review
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// prototypes
int getSize();
void getList(int list[], int size);
void displayMultiples(int list[], int size);

/**
 * MAIN
 * This is the entry point and driver for the program
 */
int main()
{
   int list[256];

   int size = getSize();

   getList(list, size);
   displayMultiples(list, size);

   return 0;
}

/**
 * GET SIZE OF LIST
 * Prompt user for an integer
 */
int getSize()
{
   // prompt user
   cout << "Enter the size of the list: ";

   // user-provided number
   int size;

   // update size var
   cin >> size;

   // return the size
   return size;
}

/**
 * GET ARRAY OF NUMBERS
 * @return [description]
 */
void getList(int list[], int size)
{
   // populate the array with the list of user-provided numbers
   for(int i = 0; i < size; i++)
   {
      // prompt for number
      cout << "Enter number for index " << i << ": ";
      // update array
      cin >> list[i];
   }

   return;
}

void displayMultiples(int list[], int size)
{
   // display multiples
   cout << "\nThe following are divisible by 3:\n";

   // check each item to see if it's divisible by 3
   for(int i = 0; i < size; i++)
   {
      if(list[i] % 3 == 0)
      {
         cout << list[i] << endl;
      }
   }
}
