/***************************************************************
 * File: address.cpp
 * Author: Scott Currell
 * Purpose: Contains the method implementations for the Address class.
 ***************************************************************/
#include "address.h"

// constructors
Address :: Address()
{
   street = "unknown";
   city   = "";
   state  = "";
   zip    = "00000";
}
Address :: Address(string street,
                   string city,
                   string state,
                   string zip)
{
   setStreet(street);
   setCity(city);
   setState(state);
   setZip(zip);
}

// Put your method bodies for the address class here

/***************************************************************
 * DISPLAY ADDRESS
 * Display address info (street, city, state, and zip)
 * INPUT: Address [class] - street, city, state, zip
 ***************************************************************/
void Address :: display() const
{
   cout << street << endl
        << getCity() << ", " << getState() << " " << getZip() << endl;
}

/***************************************************************
 * GET ADDRESS STREET
 * Get the address street
 * INPUT: Address [class] - street, city, state, zip
 ***************************************************************/
string Address :: getStreet() const
{
   return street;
}

/***************************************************************
 * GET ADDRESS CITY
 * Get the address city
 * INPUT: Address [class] - street, city, state, zip
 ***************************************************************/
string Address :: getCity() const
{
   return city;
}

/***************************************************************
 * GET ADDRESS STATE
 * Get the address state
 * INPUT: Address [class] - street, city, state, zip
 ***************************************************************/
string Address :: getState() const
{
   return state;
}

/***************************************************************
 * GET ADDRESS ZIP
 * Get the address zip
 * INPUT: Address [class] - street, city, state, zip
 ***************************************************************/
string Address :: getZip() const
{
   return zip;
}

/***************************************************************
 * SET ADDRESS STREET
 * Set the address street
 * INPUT:  Address [class] - street, city, state, zip
 * OUTPUT: Address [class] - street
 ***************************************************************/
void Address :: setStreet(string street)
{
   this -> street = street;
}

/***************************************************************
 * SET ADDRESS CITY
 * Set the address city
 * INPUT:  Address [class] - street, city, state, zip
 * OUTPUT: Address [class] - city
 ***************************************************************/
void Address :: setCity(string city)
{
   this -> city = city;
}

/***************************************************************
 * SET ADDRESS STATE
 * Set the address state
 * INPUT:  Address [class] - street, city, state, zip
 * OUTPUT: Address [class] - state
 ***************************************************************/
void Address :: setState(string state)
{
   this -> state = state;
}

/***************************************************************
 * SET ADDRESS ZIP
 * Set the address zip
 * INPUT:  Address [class] - street, city, state, zip
 * OUTPUT: Address [class] - zip
 ***************************************************************/
void Address :: setZip(string zip)
{
   this -> zip = zip;
}
