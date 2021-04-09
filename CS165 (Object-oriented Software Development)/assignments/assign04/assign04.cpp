/***************************************************************
 * File: assign04.cpp
 * Author: Scott Currell
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include "product.h"

/***********************************************************************
 * MAIN
 * This is the entry point and driver for the program.
 *    INPUT: product [clss] - methods and user-defined data: name, description
 *                            weight, and price
 ************************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);

   // Declare your Product object here
   Product product;

   // Call your prompt function here
   product.prompt();


   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;

   cout << endl;

   if (choice == 1)
   {
      // Call your display advertising profile function here
      product.displayAdvertising();
   }
   else if (choice == 2)
   {
      // Call your display inventory line item function here
      product.displayInventory();
   }
   else
   {
      // Call your display receipt function here
      product.displayReceipt();
   }

   return 0;
}
