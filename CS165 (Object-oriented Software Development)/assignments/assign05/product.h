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

// product details and methods
class Product {
   private:
      // member variables
      string name;
      string description;
      float basePrice;
      float weight;

   public:
      // default constructor
      Product();
      // non-default constructors
      Product(string name,
              string description,
              float basePrice,
              float weight);
      // member methods
      void prompt();
      void displayAdvertising() const;
      void displayInventory() const;
      void displayReceipt() const;
      // getters
      float getSalesTax() const;
      float getShippingCost() const;
      float getTotalPrice() const;
      string getName() const;
      string getDescription() const;
      float getBasePrice() const;
      float getWeight() const;
      // setters
      void setName(string);
      void setDescription(string);
      void setBasePrice(float);
      void setWeight(float);
};

#endif
