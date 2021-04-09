/****************************
 * File: icecream.h
 ****************************/
#ifndef ICECREAM_H
#define ICECREAM_H

#include <string>

class IceCream
{
private:
   std::string flavor;
   float price;

public:
   IceCream();
   IceCream(std::string flavor, float price);

   // TODO: Add public static variable named salesTax
   static float salesTax; // pg 157

   float getTotalPrice() const;
   void prompt();
   void display() const;
};


#endif
