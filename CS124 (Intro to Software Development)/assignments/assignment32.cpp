/***********************************************************************
* Program:
*    Assignment 32, Files
*    Brother Schwieder, CS124
*    
* Author:
*    Scott Currell
*    
* Summary: 
*    Prompt the user for 10 grades, calculate the average, and print the
*    results to the screen.
*
*    Estimated:  2 hrs   
*    Actual:     1 hrs
*
* Please describe briefly what was the most difficult part:
*
*    Not bad. I got this pretty easily for once :)
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

int countLetters(const char letter, const char text[]);

/**
 * MAIN
 * Determine the number of given letters are in a given text string.
 *    INPUT: letter (from user), text (string from user)
 */
int main()
{
   char text[256];
   char letter;

   cout << "Enter a letter: ";
   cin >> letter;

   // See page 247 for info on this line of code. It doesn't make sense to me.
   // Basically, it forces the code to prompt for text (getline), but I don't
   // know why.
   cin.ignore();

   cout << "Enter text: ";
   cin.getline(text, 256);

   int numLetters = countLetters(letter, text);

   cout << "Number of '" << letter << "'s: " << numLetters << endl;

   return 0;
}

/**
 * COUNT LETTERS
 * Determine the number of occurances of a given letter in a given text
 * string.
 *    INPUT: letter (for comparison), text (string)
 *    OUTPUT: number of letters in text
 */
int countLetters(const char letter, const char text[])
{
   int numLetters = 0;

   for(int i = 0; text[i]; i++)
   {
      if(letter == text[i])
      {
         numLetters++;
      }
   }

   return numLetters;
}
