/***************************************************************
 * File: ta04.cpp
 * Author: (your name here)
 * Purpose: Contains the main function to test the Rational class.
 ***************************************************************/

#include "rational.h"

int main()
{
   // Declare your Rational object here
   Rational rational;
   Rational multiple;

   // Call your prompt function here
   rational.prompt();

   // Call your display functions here
   rational.display();
   rational.displayDecimal();

   rational.multiplyBy();
   rational.display();

   rational.reduce();
   rational.display();
   return 0;
}
