/***********************************************************************
* Program:
*    Assignment 25, Loop Design
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a function (displayTable()) to display a calendar on the screen.
*
*    Estimated:  2 hrs
*    Actual:     5 hrs
*
* Please describe briefly what was the most difficult part:
*
*    I kept getting an extra line at the top of the calendar when the offset
*    was equal to 6. It took a great deal of time to figure out how to resolve
*    that issue.
************************************************************************/

#include <iostream>
#include <iomanip>   // we will use setw() in this example
#include <cassert>   // use asserts
using namespace std;

// #define DEBUG

void displayTable(int numDays, int offset);

/***************************************************************************
 * MAIN
 * @return [description]
 **************************************************************************/
int main()
{
   int numDays;
   int offset;

   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;

   displayTable(numDays, offset);
   
   return 0;
}

/***************************************************************************
 * DISPLAY TABLE
 * @return [description]
 **************************************************************************/
void displayTable(int numDays, int offset)
{
   // max number of days per week (row)
   int fullWeek = offset + 1;

   // calendar header
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   /********************DEBUG********************/
   #ifdef DEBUG
      cout << "/*******************DEBUG********************"
           << endl << endl
           << "fullWeek: " << fullWeek
           << endl << endl
           << "********************DEBUG*******************/"
           << endl;
   #endif
   /********************DEBUG********************/

   // position the first date based on the offset
   for (int i = offset; i >= 0; i--)
   {

      // add 4 spaces for each iteration and if week is not full
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
         fullWeek = 0;
         cout << endl;
      }

      cout << setw(4) << i;

      fullWeek++;
   }

   // final line return to end calendar
   cout << endl;

}
