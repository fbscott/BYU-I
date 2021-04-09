/***********************************************************************
* Program:
*    Project 06, Calendar
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Create a calendar for any month of any year from 1753 forward. Prompt
*    the user for the numeric month and year to be displayed as calendar grid.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.1 hrs
*
* Please describe briefly what was the most difficult part:
*
*    The most difficult part of this assignment was learning how to use emacs
************************************************************************/

#include <iostream>
using namespace std;

int getMonth();
int getYear();
int computeOffset(int year, int month);
int numDaysInYear(int year);
int numDaysInMonth(int year, int month);
bool isLeapYear(int year);
void displayHeader(int year, int month);
void displayTable(int numDays, int offset);
void display(int year, int month, int offset);

/**
 * HELLO WORLD
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
int main()
{
   int year = getYear();
   int month = getMonth();
   int offset = computeOffset(year, month);

   return 0;
}

/**
 * getMonth
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
int getMonth()
{
   int month;
   cout << "Month: ";
   cin >> month;

   return month;
}

/**
 * getYear
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
int getYear()
{
   int year;
   cout << "Year: ";
   cin >> year;

   return year;
}

/**
 * computeOffset
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
int computeOffset(int year, int month)
{
   int daysInYear = numDaysInYear(year);
   int daysInMonth = numDaysInMonth(year, month);

   return 0;
}

/**
 * numDaysInYear
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
int numDaysInYear(int year)
{
   bool leapYear = isLeapYear(year);
   int daysInYear;

   if(leapYear)
   {
      daysInYear == 366;
   }
   else
   {
      daysInYear == 365;
   }


   return daysInYear;
}

/**
 * numDaysInMonth
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
int numDaysInMonth(int year, int month)
{
   bool leapYear = isLeapYear(year);
   int jan = 31;
   int feb;
   int mar = 31;
   int apr = 30;
   int may = 31;
   int jun = 30;
   int jul = 31;
   int aug = 31;
   int sep = 30;
   int oct = 31;
   int nov = 30;
   int dec = 31;

   if(leapYear)
   {
      feb == 29;
   }
   else
   {
      feb == 28;
   }
   
   int daysInMonth;

   displayTable();

   return daysInMonth;
}

/**
 * isLeapYear
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
bool isLeapYear(int year)
{
   int difference = (year - 1752);

   if((difference % 4) == 0)
   {
      return true;
   }

   return false;
}

/**
 * displayHeader
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
void displayHeader(int year, int month)
{
   return;
}

/**
 * displayTable
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
void displayTable(int numDays, int offset)
{

  for (int i = 1; i <= 6; i++)
  {
     for (int j = 1; j <= 6; j++)
     {
       cout << j;
     }
       
     cout << endl;
  }

   return;
}

/**
 * display
 * Write the text "Hello World" to the screen
 *    INPUT: 
 *    OUTPUT: 
 */
void display(int year, int month, int offset)
{
   cout << "Year is: " << year << endl <<
           "Month is: " << month << endl;
   return;
}
