/*****************
 * check08b.cpp
 *****************/

#include "phone.h"
#include "smartphone.h"

#include <iostream>
#include <string>
// using namespace std;

/***************************************************
 * Function: main
 * Purpose: Tests a phone and a smart phone object.
 ***************************************************/
int main()
{
   std::cout << "Phone:\n";
   // TODO: Create your Phone object here and call its promptNumber method
   Phone phone;
   phone.promptNumber();

   std::cout << "\nPhone info:\n";
   // TODO: Call your Phone's display method here
   phone.display();

   std::cout << "\nSmart phone:\n";
   // TODO: Create your SmartPhone object here and call its prompt method
   SmartPhone smartphone;
   smartphone.prompt();

   std::cout << "\nPhone info:\n";
   // TODO: Call your SmartHpone's display method here
   smartphone.display();

   return 0;
}
