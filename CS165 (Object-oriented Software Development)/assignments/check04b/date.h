/********************************************************************
 * File: date.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef DATE_H
#define DATE_H

// put your class definition here
// along with the data members, and method prototypes

// classes
class Date
{
   // member variables
   private:
      int month;
      int day;
      int year;

   // member functions (methods)
   public:
      void set();
      void displayAmerican();
      void displayEuropean();
      void displayISO();
};

#endif
