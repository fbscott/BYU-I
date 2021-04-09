/*****************
 * smartphone.cpp
 *****************/

#include <iostream>
#include "smartphone.h"

// TODO: Put your SmartPhone class methods here...
/**
 * PROMPT
 * Get the user's phone number and email address.
 */
void SmartPhone ::  prompt()
{
   // call base class (Phone) prompt function
   promptNumber();

   std::cout << "Email: ";
   std::cin >> email;
}

/**
 * DISPLAY
 * Display the number in the format "(areaCode)prefix-suffix" followed by the
 * email address.
 */
void SmartPhone ::  display()
{
   Phone :: display();
   std::cout << email << std::endl;
}
