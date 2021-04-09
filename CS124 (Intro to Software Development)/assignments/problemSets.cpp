/**********************************************************************
* PROBLEM SETS
***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* FUNCTION CALLS
***********************************************************************/
double getNumberOne()
{
   double number = 0;
   cout << "Number One: ";
   cin >> number;
   return number;
}

double getNumberTwo()
{
   double number = 0;
   cout << "Number Two: ";
   cin >> number;
   return number;
}

double multiply(double num1, double num2 )
{
   return (float)(num1 * num2);
}

int main()
{
   double numberOne = getNumberOne();
   double numberTwo = getNumberTwo();
   double product = multiply(numberOne, numberTwo);
   cout << product;
   return 0;
}

/**********************************************************************
* CALL/PASS BY REFERENCE
***********************************************************************/
// void weird(int a, int &b) // a = 3, b = 4 (from main)
// {
//    a = 1;
//    b = 2;
// }

// int main()
// {
//    int a = 3;
//    int b = 4; // "2" updated from weird

//    weird(a, b); // updates "b" from weird because of the "&" in the function

//    cout << a * b << endl; // a = 3, b = 2 (b updated from weird)
//    return 0;
// }

/**********************************************************************
* MODULO
***********************************************************************/
// int main()
// {

//    int totalDays = 0;

//    cout << "How many days: ";
//    cin >> totalDays;

//    int weeks = totalDays / 7;
//    int days = totalDays % 7;
   
//    cout << "\tweeks: " << weeks << endl;
//    cout << "\tdays:  " << days << endl;
   
//    return 0;
// }

// int main()
// {

//    int   f = 34;
//    float c = (f - 32) * 5 / 9;
   
//    return 0;
// }
