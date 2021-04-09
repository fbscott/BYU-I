/*****************************************************************************
* Program:
*    Assignment 21, Debugging: Stubs
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a program to help Sue determine how much money she is spending on
*    her car.
*
*    Estimated:  0.75 hrs   
*    Actual:     0.25 hrs
*
* Please describe briefly what was the most difficult part:
*
*    Just plodding through all the reading :)
 ****************************************************************************/

#include <iostream>
using namespace std;

// prototypes
double getPeriodicCost();
double promptDevalue();
double promptInsurance();
double promptParking();
double getUsageCost();
double promptMileage();
double promptGas();
double promptRepairs();
double promptTires();
void display();

/*****************************************************************************
 * Main will call computeTax() and display an appropriate tax bracket
 * to the user based on his/her income.
 ****************************************************************************/
int main()
{
   double periodicCost = getPeriodicCost();
   double usageCost = getUsageCost();

   display();

   return 0;
}

/*****************************************************************************
 * getPeriodicCost
 ****************************************************************************/
double getPeriodicCost()
{
   double devalue = promptDevalue();
   double insurance = promptInsurance();
   double parking = promptParking();
   return 0.00;
}

/*****************************************************************************
 * promptDevalue
 ****************************************************************************/
double promptDevalue()
{

   return 0.00;
}

/*****************************************************************************
 * promptInsurance
 ****************************************************************************/
double promptInsurance()
{

   return 0.00;
}

/*****************************************************************************
 * promptParking
 ****************************************************************************/
double promptParking()
{

   return 0.00;
}

/*****************************************************************************
 * getUsageCost
 ****************************************************************************/
double getUsageCost()
{
   double mileage = promptMileage();
   double gas = promptGas();
   double repairs = promptRepairs();
   double tires = promptTires();
   return 0.00;
}

/*****************************************************************************
 * promptMileage
 ****************************************************************************/
double promptMileage()
{

   return 0.00;
}

/*****************************************************************************
 * promptGas
 ****************************************************************************/
double promptGas()
{

   return 0.00;
}

/*****************************************************************************
 * promptRepairs
 ****************************************************************************/
double promptRepairs()
{

   return 0.00;
}

/*****************************************************************************
 * promptTires
 ****************************************************************************/
double promptTires()
{

   return 0.00;
}

/*****************************************************************************
 * display
 ****************************************************************************/
void display()
{
   cout << "Success\n";
   return;
}
