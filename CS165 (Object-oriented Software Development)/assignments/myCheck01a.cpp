/***********************************************************************
* Program:
*    Checkpoint 01a, review
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // greeting
   cout << "Hello CS 165 World!\n";
   // prompt for name
   cout << "Please enter your first name: ";

   // first name var
   char firstName[256];

   // update firstName var
   cin.getline(firstName, 256);

   // prompt for age
   cout << "Please enter your age: ";

   // age var
   int age;

   // update age var
   cin >> age;

   // concatenated line
   cout << endl << "Hello " << firstName << ", you are " << age << " years old.\n";

   return 0;
}
