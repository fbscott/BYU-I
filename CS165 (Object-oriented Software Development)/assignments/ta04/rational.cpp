/***************************************************************
 * File: rational.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"

// put your method bodies here
void Rational :: prompt()
{
   cout << "Top: ";
   cin >> top;
   cout << "Bottom: ";
   cin >> bottom;
}

void Rational :: display()
{
   // Change your display function so that if the value is an improper
   // fraction (larger on top than bottom), it displays it as a mixed
   // number, such as: "1 1/4", rather than "5/4".
   if(top > bottom)
   {
      cout << top / bottom << ' ' << top % bottom << '/' << bottom << endl;
   }
   else
   {
      cout << top << '/' << bottom << endl;
   }
}

void Rational :: displayDecimal()
{
   float fraction = (float)top / (float)bottom;

   cout << fraction << endl;
}

/**
 * Write a multiplyBy function that accepts another rational number and
 * changes the value of the current object (multiply the two numerators
 * to get the new numerator and the two denominators to get the new
 * denominator). Modify your main function to demonstrate it.
 */
void Rational :: multiplyBy()
{
   cout << "Top2: ";
   cin >> top2;
   cout << "Bottom2: ";
   cin >> bottom2;

   // cout << top * top2 << '/' << bottom * bottom2 << endl;

   top = top * top2;
   bottom = bottom * bottom2;

}

/**
 * Create a reduce function, that reduces rational numbers to their most basic
 * equivalent form (e.g., 2/6 becomes 1/3). Modify your main function to
 * demonstrate it.
 */
void Rational :: reduce()
{
   int factor;

   for (int i = 1; i < top; i++)
   {
      if (top % i == 0 && bottom % i == 0)
      {
         factor = i;
      }
   }

   top /= factor;
   bottom /= factor;
}
