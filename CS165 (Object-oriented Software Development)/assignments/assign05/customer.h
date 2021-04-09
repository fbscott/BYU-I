/***************************************************************
 * File: customer.h
 * Author: Scott Currell
 * Purpose: Contains the definition of the Customer class
 ***************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>  // console in/out statements (cin/cout)
#include <iomanip>   // we will use setw() in this example
#include <string>    // to use string class
#include "address.h" // Address class
using namespace std;

// customer details and methods
class Customer {
   private:
      // member variables
      string name;
      Address address;

   public:
      // default constructor
      Customer();
      // non-default constructors
      Customer(string name,
               Address address);
      // member methods
      void display() const;
      // getters
      string getName() const;
      Address getAddress() const;
      // setters
      void setName(string);
      void setAddress(Address);
};

#endif
