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
   cout << "$" << dollars << ".";
   cout << setfill('0') << setw(2) << cents;
}
 
/*****************************************************************
 * Function: insertion operator
 * Purpose: Quickly and easily view the contents of an object.
 * See page 167 in the book.
 ****************************************************************/
ostream & operator << (ostream & out, const Money & rhs)
{
   out << "$" << rhs.getDollars() << ".";
   if (rhs.getCents() < 10)
      out << "0" << rhs.getCents();
   else
      out << rhs.getCents();
     
   return out;
}

/*****************************************************************
 * Function: comparison operator
 * Purpose: Take two parameters and return a Boolean value.
 * See page 174 in the book.
 ****************************************************************/
bool operator == (const Money & lhs, const Money & rhs)
{
   return (lhs.getDollars() == rhs.getDollars() && 
           lhs.getCents() == rhs.getCents());
}
 
/*****************************************************************
 * Function: comparison operator
 * Purpose: Take two parameters and return a Boolean value.
 * See page 175 in the book.
 ****************************************************************/
bool operator != (const Money & lhs, const Money & rhs)
{
   return !(lhs == rhs);
}  
