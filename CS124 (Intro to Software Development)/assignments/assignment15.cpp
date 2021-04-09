/***********************************************************************
* Program:
*    Assignment 15, Full Tithe Payer
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    This program will compute if a user is a full tithe payer using
*    the complicated formula provided in the scriptures:
*        And after that, those who have thus been tithed shall 
*        pay one-tenth of all their interest annually; and this 
*        shall be a standard law unto them forever, for my holy 
*        priesthood, saith the Lord.  D&C 119:4
*
*    Estimated:  0.75 hrs   
*    Actual:     0.25 hrs
*
* Please describe briefly what was the most difficult part
*
*    I got lucky. This assignment was a piece of cake! I'm trying to not feel
*    cocky, though. I'm sure tougher work is yet to come . . .  
************************************************************************/

#include <iostream>
using namespace std;

// prototypes
bool isFullTithePayer(float income, float tithe);

/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   float income;
   float tithe;

   // prompt user for income
   cout << "Income: ";
   cin  >> income;

   // prompt user for tithe
   cout << "Tithe: ";
   cin  >> tithe;

   // give the user his tithing report
   if (isFullTithePayer(income, tithe))
      cout << "You are a full tithe payer.\n";
   else
      cout << "Will a man rob God?  Yet ye have robbed me.\n"
           << "But ye say, Wherein have we robbed thee?\n"
           << "In tithes and offerings.  Malachi 3:8\n";

   return 0;
}

/*****************************************************
 * CALCULATE THE PERCENTAGE PAID IN TITHES
 * Divide income by 10 and determine if the result is equal to or greater than
 * tithes paid.
 *****************************************************/
bool isFullTithePayer(float income, float tithe)
{
   // are tithes paid equal to or greater than income?
   bool percentTithe ((float)(tithe >= income / 10));

   return percentTithe;
}
