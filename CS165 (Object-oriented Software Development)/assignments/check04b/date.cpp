/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

// Put your method bodies here...

/**
 * DATE :: PROMPT
 * Prompt the user for a month, day, and year
 */
void Date :: set()
{
   cout << "Month: ";
   cin >> month;
   cout << "Day: ";
   cin >> day;
   cout << "Year: ";
   cin >> year;
   cout << endl;

   return;
}

/**
 * DATE :: DISPLAYAMERICAN
 * Display the date in American format
 */
void Date :: displayAmerican()
{
   cout << month << '/' << day << '/' << year << endl;
}

/**
 * DATE :: DISPLAYEUROPEAN
 * Display the date in Eruropean format
 */
void Date :: displayEuropean()
{
   cout << day << '/' << month << '/' << year << endl;
}

/**
 * DATE :: DISPLAYISO
 * Display the date in ISO format
 */
void Date :: displayISO()
{
   cout << year << '-' << month << '-' << day << endl;
}
