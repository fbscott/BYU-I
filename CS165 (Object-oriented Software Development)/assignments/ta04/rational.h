/***************************************************************
 * File: rational.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Rational class
 ***************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
using namespace std;

// put your class definition here
class Rational
{
   private:
      int top;
      int bottom;
      int top2;
      int bottom2;

   public:
      void prompt();
      void display();
      void displayDecimal();
      void multiplyBy();
      void reduce();
};

#endif
