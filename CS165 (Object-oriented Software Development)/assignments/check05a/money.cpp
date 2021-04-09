/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "money.h"

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money :: prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display() const 
{
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}

float Money :: getDollars() const
{
   return dollars;
}

float Money :: getCents() const
{
   return cents;
}

void Money :: setDollars(float dollars)
{
   if (dollars < 0)
   {
      this->dollars = dollars * -1;
   }
   else
   {
      this->dollars = dollars;
   }
}

void Money :: setCents(float cents)
{
   if (cents < 0)
   {
      this->cents = cents * -1;
   }
   else
   {
      this->cents = cents;
   }
}
