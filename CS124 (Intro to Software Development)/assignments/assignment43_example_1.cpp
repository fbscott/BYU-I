/***********************************************************************
* Program:
*    Assignment 43 demo 1
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    This program will display the words to the song Dem Bones by
*    using the string class
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/****************************************** 
* MAIN: Reflect back to the user what he 
* typed on the command prompt 
******************************************/ 
int main(int argc, char ** argv) // again, MAIN really takes two parameters
{
   // name of the program
   cout << "The name of the program is: "
        << argv[0] // the first item in the list is always
        << endl;   // the command the user typed

   // number of parameters
   cout << "There are "
        << argc - 1                    // don’t forget to subtract one due to
        << " additional parameters\n"; // the first being the program name

   // show each parameter
   for (int iArg = 1; iArg < argc; iArg++) // standard command line loop
   {
      cout << "\tParameter" << iArg
           << ": " << argv[iArg] << endl; // each argv[i] is a c-string
   }

   return 0;
}
