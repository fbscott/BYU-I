/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate how asserts help us find bugs
 ************************************************************************/

#include <iostream>
#include <cassert>   // necessary to use asserts.  
using namespace std;

/*************************************************
 * GET INCOME
 * Prompt for income
 *************************************************/
float getIncome()
{
   float income;
   cout << "What is the income? ";
   cin  >> income;
   return income;
}

/***********************************************************
 * COMPUTE TITHING
 * Return how much tithing should be paid for a given income
 ***********************************************************/
float computeTithing(float income)
{
   assert(income >= 0.00);       // this only works for positive income
   
   // compute the tithing
   float tithe = income * 0.10;
   assert(tithe >= 0.00);        // The Lord doesn't owe us, right?
   assert(income > tithe);       // 10% should be less than 100%, right?

   // return the answer
   return tithe;
}

/**********************************************
 * MAIN
 * Simple driver program for computeTithe
 **********************************************/
int main()
{
   float income = getIncome();
   assert(income >= 0.00);                // getIncome() should be positive

   float tithe = computeTithing(income);
   assert(tithe >= 0.0);                  // tithe better be positive
   assert(tithe <= income);               // what is this, the IRS?
   
   cout << "Tithe for $" << income
        << " is $" << tithe << endl;

   return 0;
}

