/***********************************************************************
* Program:
*    Assignment 34, Files
*    Brother Schwieder, CS124
*    
* Author:
*    Scott Currell
*    
* Summary: 
*    Start with Assignment 3.2. Modify countLetters() so that it walks through
*    the string using pointers instead of array indexes. The output should be
*    exactly the same as with Assignment 3.2.
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

int countLetters(const char letter, char * text);

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
int countLetters(const char letter, char * text)
{
   int numLetters = 0;

   // char * pLetter = text; points to the first letter in text (see page 263
   // in the manual)
   for(char * pLetter = text; *pLetter; pLetter++)
   {
      if(letter == *pLetter)
      {
         numLetters++;
      }
   }

   return numLetters;
}
