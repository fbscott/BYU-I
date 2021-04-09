/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Create a calendar for any month of any year from 1753 forward. Prompt
*    the user for the numeric month and year to be displayed as calendar grid.
*
*    Estimated:  6 hrs   
*    Actual:     10 hrs
*
* Please describe briefly what was the most difficult part:
*
*     There were a few areas where I struggled greatly:
*
*     Updating char text[256] variables:
* 
*     In the displayHeader() function, I needed to return the name of the
*     month as entered by the user. I wanted to create a char monthName[256]
*     variable, but we never learned how to update a variable like that. I
*     tried numerous ways of updating the var once it was declared, but
*     nothing worked. I had to resort to a series of if/else statements
*     based on the month number. This is not ideal. I wish we would have
*     learned how to update this data type prior to this project. It would
*     have saved me hours of trial and error.
*
*     Determining the leap year:
*
*     It's common knowledge that a leap year is every year that is perfectly
*     divisible by four. It is NOT common knowledge, however, that a leap year
*     is not calculated on century years that are divisible by 100 and not by
*     400. The only mention of this rule was on page 145 of the text in
*     problem set #10. That's a sneaky place to "hide" that critical piece of
*     information. I'm glad my classmates pointed that out in the Slack forum.
*     I would have been VERY upset to learn of that rule after hours or days
*     of debugging. That was pretty underhanded for an intro to CS course.
************************************************************************/

#include <iostream>
#include <iomanip> // we will use setw() in this example
using namespace std;

// prototypes
int getMonth();
int getYear();
int computeOffset(int year, int month);
int numDaysInYear(int year);
int numDaysInMonth(int year, int month);
bool isLeapYear(int year);
void displayHeader(int year, int month);
void displayTable(int numDays, int offset);
void display(int year, int month, int offset);

/**************************************************************
* CALENDAR
* Display a calendar based on the month and year entered by the user
*    INPUT: none
*    OUTPUT: none
*************************************************************/
int main()
{
   // prompt for month
   int month = getMonth();
   // prompt for year
   int year = getYear();
   // offset (starting position of first day of the month)
   int offset = computeOffset(year, month);
   // display the final calendar
   display(year, month, offset);
   
   return 0;
}

/**************************************************************
* GET MONTH
* Get a user-defined month
*    INPUT: month (from user in integer-format only from and including 1 to 12)
*    OUTPUT: month
*************************************************************/
int getMonth()
{
   int month;
   
   // prompt for month
   do
   {
      cout << "Enter a month number: ";
      cin >> month;

      if (month < 1 || month > 12)
      {
         // error message if invalid month is provided
         cout << "Month must be between 1 and 12.\n";
      }
   }

   // keep prompting until proper input is given (month from and including
   // 1 to 12)
   while (month < 1 || month > 12);

   return month;
}

/**************************************************************
* GET YEAR
* Get a user-defined year
*    INPUT: year (from user in integer-format only greater than 1752)
*    OUTPUT: year
*************************************************************/
int getYear()
{
   int year;
   
   // prompt for year
   do
   {
      cout << "Enter year: ";
      cin >> year;

      if (year < 1753)
      {
         // error message if invalid year is provided
         cout << "Year must be 1753 or later.\n";
      }
   }

   // keep prompting until proper input is given (year greater than 1752)
   while (year < 1753);

   return year;
}

/**************************************************************
* COMPUTE OFFSET
* Determine the starting position (offset) of the first day of the month
* I.e., Su, Mo, Tu, etc.
*    INPUT: year, month
*    OUTPUT: offset
*************************************************************/
int computeOffset(int year, int month)
{
   int totalNumDays = 0;

   // year must be greater than 1752
   for (int i = year - 1; i > 1752; i--)
   {
      // increment the total number of days based on the provided year
      totalNumDays += numDaysInYear(i);
   }

   // month must be between and including 1 and 12
   for (int j = month - 1; j > 0; j--)
   {
      // increment the total number of days based on the provided month
      totalNumDays += numDaysInMonth((year), j);
   }

   // the number of spaces (skipped days) at the beginning of the calendar
   int offset = totalNumDays % 7;

   return offset;
}

/**************************************************************
* NUMBER OF DAYS IN YEAR
* Determine the number of days in a give year
*    INPUT: year
*    OUTPUT: daysInYear (number of days in year)
*************************************************************/
int numDaysInYear(int year)
{
   bool leapYear = isLeapYear(year);
   // normal (non-leap year number of days)
   int daysInYear = 365;

   if (leapYear)
   {
      // if leap year
      daysInYear = 366;
   }

   return daysInYear;
}

/**************************************************************
* NUMBER OF DAYS IN MONTH
* Determine the number of days in a give month
*    INPUT: year, month
*    OUTPUT: daysInmonth (number of days in month)
*************************************************************/
int numDaysInMonth(int year, int month)
{
   bool leapYear = isLeapYear(year);
   // start with 0 and update based on month provided
   int daysInMonth = 0;

   // April, June, September, or November
   if (month == 4 || month == 6 || month == 9 || month == 11)
   {
      daysInMonth = 30;
   }
   // February
   else if (month == 2)
   {
      if (leapYear)
      {
         // leap year
         daysInMonth = 29;
      }
      else
      {
         // non-leap year
         daysInMonth = 28;
      }
   }
   // January, March, May, July, August, October, December
   else
   {
      daysInMonth = 31;
   }

   return daysInMonth;
}

/**************************************************************
* DETERMINE LEAP YEAR
* Determine whether a give year is a leap year or not
*    INPUT: year
*    OUTPUT: bool value
*************************************************************/
bool isLeapYear(int year)
{
   // if century year (perfectly divisible by 100 by not 400)
   // this would NOT be a leap year
   if (year % 100 == 0 && year % 400 != 0)
   {
      return false;
   }
   // if standard leap year (perfectly divisible by 4)
   // this would be a leap year
   else if (year % 4 == 0)
   {
      return true;
   }
   else
   {
      // not a leap year (default)
      return false;
   }
}

/**************************************************************
* DISPLAY CALENDAR HEADER
* Display the header of the calendar. Like so:
* 
* January, 1753
*   Su  Mo  Tu  We  Th  Fr  Sa
*
*    INPUT: year, month
*    OUTPUT: calendar header as cout statements
*************************************************************/
void displayHeader(int year, int month)
{
   cout << endl;

   // print the month to the screen
   // I don't like this. I wish I could declare a char monthName[256] variable
   // and update it based on the month number. I noted this in my comments
   // above.
   if (month == 1)
   {
      cout << "January, ";
   }
   else if (month == 2)
   {
      cout << "February, ";
   }
   else if (month == 3)
   {
      cout << "March, ";
   }
   else if (month == 4)
   {
      cout << "April, ";
   }
   else if (month == 5)
   {
      cout << "May, ";
   }
   else if (month == 6)
   {
      cout << "June, ";
   }
   else if (month == 7)
   {
      cout << "July, ";
   }
   else if (month == 8)
   {
      cout << "August, ";
   }
   else if (month == 9)
   {
      cout << "September, ";
   }
   else if (month == 10)
   {
      cout << "October, ";
   }
   else if (month == 11)
   {
      cout << "November, ";
   }
   else
   {
      cout << "December, ";
   }

   // print the year to the screen
   cout << year
        << endl;

   // calendar header
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   return;
}

/**************************************************************
* DISPLAY CALENDAR TABLE
* Display the calendar grid. Like so:
*
*        1   2   3   4   5   6
*   7   8   9  10  11  12  13
*  14  15  16  17  18  19  20
*  21  22  23  24  25  26  27
*  28  29  30  31
*
*    INPUT: numDays, offset
*    OUTPUT: calendar grid as cout statements
*************************************************************/
void displayTable(int numDays, int offset)
{
   // number of days per week (row)
   int fullWeek = offset + 1;

   // position the first date based on the offset
   for (int i = offset; i >= 0; i--)
   {

      // add 4 spaces (placeholder days) if week is not full
      if (fullWeek < 7)
      {
         cout << setw(4) << "  ";
      }

   }

   // reset the week once the max number of days (7) is reached
   if (fullWeek == 7)
   {
      fullWeek = 0;
   }

   // print calendar days to screen
   for (int i = 1; i <= numDays; i++)
   {

      // new row when max number of days is reached and reset the week
      if (fullWeek == 7)
      {
         cout << endl;
         fullWeek = 0;
      }

      cout << setw(4) << i;

      // increment count
      fullWeek++;
   }

   // final line return to end calendar
   cout << endl;

}

/**************************************************************
* DISPLAY CALENDAR
* Call the appropriate header and body for the calendar
*    INPUT: year, month, offset
*    OUTPUT: none
*************************************************************/
void display(int year, int month, int offset)
{
   int numDays = numDaysInMonth(year, month);

   // render the calendar header
   displayHeader(year, month);
   // render the calendar
   displayTable(numDays, offset);

   return;
}
