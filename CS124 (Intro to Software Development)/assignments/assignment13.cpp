/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a program to convert Fahrenheit to Celsius. This program will prompt
*    the user for the Fahrenheit number and convert it to Celsius.
*
*    Estimated:  0.75 hrs   
*    Actual:     1.0 hrs
*
* Please describe briefly what was the most difficult part:
*
*    I continue to struggle with emacs. Also, finding the correct casting
*    operator was a bit of a challenge. Otherwise, this assignment wasn't
*    too bad. I think 1.2 was harder.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* TEMPERATURE CONVERSION
* The program will prompt the user for the temperature, compute the Celsius
* value, and display the results.
*    INPUT: Fahrenheit temperature
*    OUTPUT: Celsius temperature
***********************************************************************/
int main()
{
   // get user input
   cout << "Please enter Fahrenheit degrees: ";

   int fahrenheitTemp = 0;
   cin >> fahrenheitTemp;  // store Fahrenheit temp
   
   // convert temp from Fahrenheit to Celsius: C = 5 / 9 (F - 32)
   float celsiusTemperature = (double)((5.0 / 9.0) * (fahrenheitTemp - 32));

   cout.setf(ios::fixed);  // no scientific notation
   cout.precision(0);      // two decimals for cents
   
   // write result (temp in Celsius) to screen
   cout << "Celsius: "  << celsiusTemperature << endl;
   
   return 0;
}
