/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

// #include <iostream>

/******************************************************
 * Class: Money
 * Description: Holds a value of dollars and cents.
 ******************************************************/
class Money
{
private:
   int dollars;
   int cents;

public:
   /************************
    * Constructors
    ************************/
   Money()
   {
      setDollars(0);
      setCents(0);
   }

   Money(int dollars, int cents)
   {
      setDollars(dollars);
      setCents(cents);
   }

   /************************
    * Getters and Setters
    ************************/
   int getDollars() const { return dollars; }
   int getCents()   const { return cents;   }
   
   // These could be done in a smarter way to add cents to dollars if more than 100 etc.
   // but we're trying to keep it simple for this assignment...
   void setDollars(int dollars) { this -> dollars = dollars; }
   void setCents(int cents)     { this -> cents = cents;     }

   /************************
    * Other public methods
    ************************/
   void prompt();
   void display() const;


   /************************
    * Member operators
    ************************/



   // TODO: Put your protoypes here!
   Money operator + (const Money & rhs) const;
   Money & operator += (const Money & rhs);
   Money & operator ++ ();
   
   /*************************
    * Private helper methods
    *************************/
   void handleOverflow();

};

#endif
