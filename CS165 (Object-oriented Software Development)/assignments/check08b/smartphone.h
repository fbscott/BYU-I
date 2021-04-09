/*****************
 * smartphone.h
 *****************/

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <string>
#include "phone.h"

// TODO: Put your SmartPhone class definition here...
class SmartPhone : public Phone
{
   private:
      std::string email;

   public:
      SmartPhone() : email("derp@derp.com") {}
      void prompt();
      void display();
};

#endif
