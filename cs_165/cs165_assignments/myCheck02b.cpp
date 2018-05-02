/***********************************************************************
* Program:
*    Checkpoint 02b, structs
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex
{
   double real;
   double imaginary;
};

// TODO: Add your prompt function here
void prompt(Complex & num);

// TODO: Add your display function here
void display(const Complex & num);

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{
   // TODO: Fill in the body of the add function

   // new structure var
   // Note: this new var can be named anything (sum, z, derp, etc.)
   Complex sumOfNums;

   sumOfNums.real = x.real + y.real;
   sumOfNums.imaginary = x.imaginary + y.imaginary;

   return sumOfNums;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex c1;
   Complex c2;

   // Call your prompt function twice to fill in c1, and c2 
   prompt(c1);
   prompt(c2);

   // Declare another Complex for the sum
   Complex sum;

   // Call the addComplex function, putting the result in sum;
   sum = addComplex(c1, c2);
   
   cout << "\nThe sum is: ";
   display(sum);
 
   return 0;
}

void prompt(Complex & num)
{
   cout << "Real: ";
   cin >> num.real;
   cout << "Imaginary: ";
   cin >> num.imaginary;
}

void display(const Complex & num)
{
   cout << num.real
        << " + "
        << num.imaginary
        << "i\n";
}
