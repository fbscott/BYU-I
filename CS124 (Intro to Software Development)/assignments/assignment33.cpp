/***********************************************************************
* Program:
*    Assignment 33, Files
*    Brother Schwieder, CS124
*    
* Author:
*    Scott Currell
*    
* Summary: 
*    Ask two people for their account balance. Then, based on who has the most
*    money, all subsequent purchases will be charged to his or her account.
*
*    Estimated:  1 hrs
*    Actual:     0.5 hrs
*
* Please describe briefly what was the most difficult part:
*
*    Not bad. I got this pretty easily for once :)
************************************************************************/

#include <iostream>
using namespace std;

int main()
{
   double balanceSam;
   double balanceSue;
   double dinner;
   double movie;
   double iceCream;

   double * pAccountBalance;

   cout << "What is Sam's balance? ";
   cin >> balanceSam;
   cout << "What is Sue's balance? ";
   cin >> balanceSue;
   cout << "Cost of the date:\n";
   cout << "\tDinner:    ";
   cin >> dinner;
   cout << "\tMovie:     ";
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;

   if(balanceSam > balanceSue)
   {
      pAccountBalance = &balanceSam;
   }
   else
   {
      pAccountBalance = &balanceSue;
   }

   *pAccountBalance -= (dinner + movie + iceCream);

   cout << "Sam's balance: $" << balanceSam << endl;
   cout << "Sue's balance: $" << balanceSue << endl;
}
