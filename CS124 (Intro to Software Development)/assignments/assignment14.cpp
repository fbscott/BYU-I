/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*
* Please describe briefly what was the most difficult part
*
*    For the first time, this assignment wasn't too bad. It went well!  
************************************************************************/

#include <iostream>
using namespace std;

// prototypes
int main();
void questionPeter();
int responseLord();

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}

/**********************************************************************
* PETER'S QUESTION
* This is the question posed by Peter to the Lord.
***********************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, "
        << "and I forgive him?\n"
        << "Till seven times?\n";
   return;
}

/**********************************************************************
* THE LORD'S RESPONSE
* This is the Lord's response to Peter.
***********************************************************************/
int responseLord()
{
   return 490;
}
