/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // vectors
   std::vector <int> numbers;
   std::vector <std::string> strings;

   // user-provided input (next two lines)
   int userProvidedValue;
   std::string userProvidedText;

   // update the int vector with user-provided values
   do
   {
      cout << "Enter int: ";
      cin >> userProvidedValue;

      if (userProvidedValue) // not zero
      {
         numbers.push_back(userProvidedValue);
      }
   }
   while (userProvidedValue); // not zero

   cout << "Your list is:\n";

   // print numbers to screen
   // iterator method
   // for (std::vector <int> :: iterator it = numbers.begin(); it != numbers.end();)
   // {
   //    cout << *it << endl;
   //    it++;
   // }

   // for loop w/size() method
   for (int i = 0; i < numbers.size(); i++)
   {
      cout << numbers[i] << endl;
   }

   cout << endl;

   // update the string vector with user-provided text
   do
   {
      cout << "Enter string: ";
      cin >> userProvidedText;
      if (userProvidedText != "quit")
      {
         strings.push_back(userProvidedText);
      }
   }
   while (userProvidedText != "quit");

   cout << "Your list is:\n";

   // print strings to screen
   for (std::vector <string> :: iterator it = strings.begin();
        it != strings.end();
        it++)
   {
      cout << *it << endl;
   }

   return 0;
}
