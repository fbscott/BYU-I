/***************************************************************
 * File: product.cpp
 * Author: Scott Currell
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"

// put your method bodies here

/**
 * PROMPT
 * Prompt the user for book name, description, weight, and price
 * INPUT: Product [class] - name, description, weight, and price
 */
void Product :: prompt()
{
   
   do
   {
      cout << "Enter name: ";
      getline(cin, name);
   }
   while(cin.fail());
   
   do
   {
      cout << "Enter description: ";
      getline(cin, description);
   }
   while(cin.fail());
   
   do
   {
      if (cin.fail())
      {
         cin.clear();
         // skip over up to 256 characters
         // or until a newline char '\n' is encountered
         cin.ignore(256, '\n');
      }
      cout << "Enter weight: ";
      cin >> weight;
   }
   while(weight <= 0);

   do
   {
      if (cin.fail())
      {
         cin.clear();
         // skip over up to 256 characters
         // or until a newline char '\n' is encountered
         cin.ignore(256, '\n');
      }
      cout << "Enter price: ";
      cin >> basePrice;
   }
   while(basePrice <= 0);
}

/**
 * GET SALES TAX
 * Calculate sales tax (flat 6%)
 * INPUT: Product [class] - name, description, weight, and price
 */
float Product :: getSalesTax()
{
   float tax = basePrice * 0.06;

   return tax;
}

/**
 * GET SHIPPING COST
 * Calculate shipping cost ($2.00 for 5 lbs and under. $0.1 per each
 * additional lb.)
 * INPUT: Product [class] - name, description, weight, and price
 */
float Product :: getShippingCost()
{
   if (weight < 5.0)
   {
      return 2.00;
   } else
   {
      return (( weight - 5.0 ) * 0.10) + 2.00;
   }
}

/**
 * GET TOTAL PRICE
 * Calculate total price (base + tax + shipping)
 * INPUT: Product [class] - name, description, weight, and price
 */
float Product :: getTotalPrice()
{
   float total = basePrice + getSalesTax() + getShippingCost();

   return total;
}

/**
 * DISPLAY ADVERTISING MESSAGE
 * Basic message: name, price, and description
 * INPUT: Product [class] - name, description, weight, and price
 */
void Product :: displayAdvertising()
{
   // two decimal points
   cout.precision(2);
   cout << name << " - $" << basePrice << endl;
   cout << "(" << description << ")\n";
}

/**
 * DISPLAY INVENTORY MESSAGE
 * Price, name, and weight
 * INPUT: Product [class] - name, description, weight, and price
 */
void Product :: displayInventory()
{
   // two decimal points
   cout.precision(2);
   cout << '$' << basePrice << " - " << name << " - ";
   
   // one decimal point
   cout.precision(1);
   cout << weight <<" lbs\n";
}

/**
 * DISPLAY RECEIPT MESSAGE
 * Itemized receipt
 * INPUT: Product [class] - name, description, weight, and price
 */
void Product :: displayReceipt()
{
   // two decimal points
   cout.precision(2);
   // product name
   cout << name << endl;
   // itemized table
   cout << "  Price:         $" << setw(8) << basePrice << endl
        << "  Sales tax:     $" << setw(8) << getSalesTax() << endl
        << "  Shipping cost: $" << setw(8) << getShippingCost() << endl
        << "  Total:         $" << setw(8) << getTotalPrice() << endl;
}
