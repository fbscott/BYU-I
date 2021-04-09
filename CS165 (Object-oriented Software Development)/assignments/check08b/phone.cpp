/*****************
 * phone.cpp
 *****************/

#include <iostream>
#include "phone.h"

// TODO: Put your phone class methods here...
/**
 * PROMPT NUMBER
 * Get the user's phone number.
 */
void Phone :: promptNumber()
{
   std::cout << "Area Code: ";
   std::cin >> areaCode;

   std::cout << "Prefix: ";
   std::cin >> prefix;

   std::cout << "Suffix: ";
   std::cin >> suffix;
   std::cin.ignore();
}

/**
 * DISPLAY
 * Display the number in this format "(areaCode)prefix-suffix."
 */
void Phone :: display()
{
   std::cout << '(' << areaCode << ')' << prefix << '-' << suffix << std::endl;
}
