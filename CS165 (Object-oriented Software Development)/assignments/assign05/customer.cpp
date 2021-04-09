/***************************************************************
 * File: customer.cpp
 * Author: Scott Currell
 * Purpose: Contains the method implementations for the Customer class.
 ***************************************************************/
#include "customer.h"

// constructors
Customer :: Customer()
{
   name    = "unspecified";
   // address = Address(); // the address's default constructor
}
Customer :: Customer(string name,
                     Address address)
{
   setName(name);
   setAddress(address);
}

// Put the method bodies for your customer class here

/***************************************************************
 * DISPLAY CUSTOMER AND ADDRESS
 * Display customer info (name)
 *         address info (street, city, state, and zip)
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 ***************************************************************/
void Customer :: display() const
{
   cout << getName() << endl;
   address.display();
}

/***************************************************************
 * GET CUSTOMER NAME
 * Get the customer name
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 ***************************************************************/
string Customer :: getName() const
{
   return name;
}

/***************************************************************
 * GET CUSTOMER ADDRESS
 * Get the customer address
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 ***************************************************************/
Address Customer :: getAddress() const
{
   return address;
}

/***************************************************************
 * SET CUSTOMER NAME
 * Set the customer name
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 * OUTPUT: Customer [class] - name
 ***************************************************************/
void Customer :: setName(string name)
{
   this -> name = name;
}

/***************************************************************
 * SET CUSTOMER ADDRESS
 * Set the customer address
 * INPUT: Customer [class] - name, address
 *        Address [class] - street, city, state, zip
 * OUTPUT: Address [class] - street, city, state, zip
 ***************************************************************/
void Customer :: setAddress(Address address)
{
   this -> address = address;
}
