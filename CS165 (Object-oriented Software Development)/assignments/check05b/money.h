/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   // member variables
   int dollars;
   int cents;

public:
   // default constructor
   Money();
   // non-default constructors
   Money(int dollars);
   Money(int dollars, int cents);
   // member methods
   void prompt();
   void display() const;
   float getDollars() const;
   float getCents() const;
   void setDollars(float);
   void setCents(float);
};

#endif
