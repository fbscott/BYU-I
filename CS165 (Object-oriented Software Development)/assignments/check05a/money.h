/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;

public:
   void prompt();
   void display() const;
   float getDollars() const;
   float getCents() const;
   void setDollars(float);
   void setCents(float);
};

#endif
