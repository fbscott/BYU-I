/*****************
 * phone.h
 *****************/

#ifndef PHONE_H
#define PHONE_H

// TODO: Put your phone class definition here...
class Phone
{
   private:
      int areaCode;
      int prefix;
      int suffix;

   public:
      Phone() : areaCode(303), prefix(555), suffix(1234) {}
      void promptNumber();
      void display();
};

#endif
