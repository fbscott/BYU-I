/***********************************************************************
* Program:
*    Assignment 41, Files
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a program to read a game data file, print game board to the screen,
*    and put the data back to another file.
*
*    Estimated:  2 hrs   
*    Actual:     4 hrs
*
* Please describe briefly what was the most difficult part:
*
*    I kept getting error with the write function. But I figured it out.
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

int   getNumItems(                              );
int * allocate(                     int numItems);
void  fillList(         int * list, int numItems);
void  displayList(const int * list, int numItems);

/**********************************************************************
 * MAIN
 * Call the functions and hold the data
 ***********************************************************************/
int main()
{
   // get the number of items in the array from the user
   int numItems = getNumItems();

   // allocate the memory
   int * list = allocate(numItems);   // allocated arrays go into pointers

   // do something with it
   fillList(list, numItems);         // we will need to pass the array
   displayList(list, numItems);      //   size here

   // make like a tree
   delete [] list;                   // never forget to release the memory
   list = NULL;
   return 0;
}

/*****************************************************
 * GET NUM ITEMS
 * Prompt the user for the number of items in the list
 *****************************************************/
int getNumItems()
{
   int num;
   do
   {
      cout << "How many items? ";
      cin  >> num;
   }
   while (num <= 0);   // better be greater than zero!

   return num;
}

/***************************************************
 * ALLOCATE
 * allocate the necessary memory
 ***************************************************/
int * allocate(int numItems)
{
   assert(numItems > 0);

   // allocate the necessary memory
   int * p = new(nothrow) int[numItems];

   // if p == NULL, we failed to allocate
   if (!p)
   {
      cout << "Unable to allocate "
           << numItems * sizeof(int)
           << " bytes\n";
   }

   return p;
}

/******************************************************
 * FILL LIST
 * Prompt the user for the values in the list
 ******************************************************/
void fillList(int * list, int numItems)
{
   // paranoia
   assert(list != NULL);
   assert(numItems > 0);

   // fill the data
   cout << "Please enter " << numItems << " values\n";
   for (int i = 0; i < numItems; i++)
   {
      cout << "\t#" << i + 1 << ": ";
      cin  >> list[i];
   }
}

/*****************************************
 * DISPLAY LIST
 * Show the user all the data in the list
 ****************************************/
void displayList(const int * list, int numItems)
{
   // paranoia
   assert(list != NULL);
   assert(numItems > 0);

   cout << "A display of the list:\n";
   for (int i = 0; i < numItems; i++)
      cout << "\t" << list[i] << endl;
}
