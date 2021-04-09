/***********************************************************************
 * This demo program is designed to
 *    Compute pay taking into account time-and-a-half overtime.
 *
 * To compile the code without asserts or debug code for the client:
 *    g++ 2-1-debugOutput.cpp -DNDEBUG
 * To compile with only asserts and no other debug code, try:
 *    g++ 2-1-debugOutput.cpp
 * To turn on debug output statements and leave asserts in, try:
 *    g++ 2-1-debugOutput.cpp -DDEBUG
 ************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

float getHourlyWage();             
float getHoursWorked();            
float computePay(float hourlyWage, float hoursWorked);

#define OVERTIME 1.5   // overtime rate is 1 1/2 that of regular
#define CAP      40    // only 40 hours are at the normal rate

#ifdef DEBUG
#define Debug(x) x
#else // !DEBUG
#define Debug(x) 
#endif // !DEBUG

/**********************************************************************
 * main(): Call the getter functions and display the pay
 ***********************************************************************/
int main()
{
   // get the data
   float hourlyWage  = getHourlyWage();
   float hoursWorked = getHoursWorked();
   assert(hourlyWage  >= 0.0);
   assert(hoursWorked >= 0.0);

   Debug(cout << "main: hourlyWage:  " << hourlyWage  << endl);
   Debug(cout << "main: hoursWorked: " << hoursWorked << endl);
   
   // display the results
   cout.setf(ios::fixed);
   cout.precision(2);
   float pay = computePay(hourlyWage, hoursWorked);
   assert(pay >= 0.0);
   cout << "Pay: $ " << pay << endl;
   
   return 0;
}

/*****************************************
 * GET HOURLY WAGE
 *   Prompt the user for his wage.  Kinda personal.  A
 *   FLOAT is just fine here because few make more
 *   than $100,00.00 an hour!
 *****************************************/
float getHourlyWage()
{
   // Prompt
   cout << "What is your hourly wage? ";

   // get data
   float wage;
   cin >> wage;

   // don't use an assert to catch this case.  We should handle user input
   if (wage < 0.0)
   {
      cout << "Negative wage?  Definitely don't show up to work!\n";
      wage = 0.0;
   }

   Debug(cout << "getHourlyWage: wage: " << wage << endl);
   
   assert(wage >= 0.0);
   return wage;
}

/************************************
 * GET HOURS WORKED
 *    Note that we could work part of an hour
 *    so this needs to be a FLOAT
 ************************************/
float getHoursWorked()
{
   // prompt
   cout << "How many hours did you work? ";

   // get data
   float hours;
   cin >> hours;

   // again, user errors are handled with IF statements.
   if (hours < 0.0)
   {
      cout << "Negative hours worked?  How is that possible?\n";
      hours = 0.0;
   }

   Debug(cout << "getHoursWorked: hours: " << hours << endl);
   
   assert(hours >= 0.0);
   return hours;
}

/*****************************************
 * COMPUTE PAY
 *   Compute the user's pay using time-and-a-half
 *   overtime.
 ****************************************/
float computePay(float hourlyWage, float hoursWorked)
{
   float pay;
   assert(hourlyWage  >= 0.0);
   assert(hoursWorked >= 0.0);

   Debug(cout << "computePay(hourlyWage = " << hourlyWage
         << ", hoursWorked = " << hoursWorked << ")\n");
   
   // regular rate
   if (hoursWorked < CAP)
   {
      Debug(cout << "computePay : regular rate\n");
      pay = hoursWorked * hourlyWage;                   // regular rate
   }

   // overtime rate
   else
   {
      Debug(cout << "computePay: Overtime\n");
      pay = (CAP * hourlyWage) +                        // first 40 normal
         ((hoursWorked - CAP) * (hourlyWage * OVERTIME)); 
   }

   assert(pay >= 0.0);
   return pay;
}
   
