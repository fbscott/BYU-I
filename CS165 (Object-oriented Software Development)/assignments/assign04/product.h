/***************************************************************
 * File: product.h
 * Author: Scott Currell
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream> // console in/out statements (cin/cout)
#include <iomanip>  // we will use setw() in this example
#include <string>   // to use string class
using namespace std;

// put your class definition here
// product details and methods
class Product {
   private:
      string name;
      float basePrice;
      float weight;
      string description;

   public:
      void prompt();
      float getSalesTax();
      float getShippingCost();
      float getTotalPrice();
      void displayAdvertising();
      void displayInventory();
      void displayReceipt();
};

#endif
