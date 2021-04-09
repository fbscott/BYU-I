/***********************************************************************
* Program:
*    Project 09, Mad Lib Pt 1
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    The second part of the Mad Lib project: read the Mad Lib from a file and
*    prompt the user.
*
*    Estimated:  6 hrs   
*    Actual:     12 hrs
*
* Please describe briefly what was the most difficult part:
*    This one was brutal. What DIDN'T I have trouble with :)
*    Thank you so much for your help, Brother Schwieder!
*
************************************************************************/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// styleChecker doesn't like this formatting, but it's consistent with the
// book.
#define MAX_NUM_WORDS 256
#define MAX_NUM_LETTERS 33

// use const because it will not change
// the output of the function
int readFile(const char fileName[], char wordsArray[][MAX_NUM_LETTERS]);
void askQuestions(char word[]);

/**********************************************************************
 * MAIN
 * Read words from a user-provided file and extract token phrases.
 ***********************************************************************/
int main()
{
   // fetch the filename via user prompt
   char fileName[256];
   cout << "Please enter the filename of the Mad Lib: ";
   cin  >> fileName;

   // I don't know what this is for???
   cin.ignore();
   
   // read the words from the file
   char wordsArray[MAX_NUM_WORDS][MAX_NUM_LETTERS];
   int numOfWordsRead = readFile(fileName, wordsArray);

   cout << "Thank you for playing.\n";

   return 0;
}

/**********************************************************************
 * READ FILE
 * Read the words from the file.  Make sure there is no more words in the
 * file than we have room in our array!
 *    INPUT:   filename, word array (story)
 *    OUTPUT:  updated word array (story) via pass-by-reference
 ***********************************************************************/
int readFile(const char fileName[], char wordsArray[][MAX_NUM_LETTERS])   
{
   // open the file for reading
   // open the input stream to fileName
   ifstream fin(fileName);                         
   // never forget the error checking
   if (fin.fail())                                 
   {
      cout << "ERROR: Unable to read file "
           // display the filename we tried to read
           << fileName                             
           << endl;
      // return the error condition: none read
      return 0;                                    
   }

   // loop through the file, reading
   // the elements one at a time
   // initially none were read
   int numOfWordsRead = 0;                         
   // don't read more than the list holds
   while (numOfWordsRead < MAX_NUM_WORDS &&        
          // read and check for errors
          fin >> wordsArray[numOfWordsRead])       
   {
      // prompt the user for a token
      askQuestions(wordsArray[numOfWordsRead]);
      // increment the index by one
      numOfWordsRead++;                            
   }
   
   // close the file and return
   // never forget to close the file
   fin.close();                                    
   // report the number successfully read
   return numOfWordsRead;                          
}

/**********************************************************************
 * ASK QUESTIONS
 * Prompt the user for a question from the tokens in the Mad Lib file.
 *    INPUT:   word
 *    OUTPUT:  token phrase
 ***********************************************************************/
void askQuestions(char word[])
{
   // if word is not a token
   if (word[0] != '<' || !isalpha(word[1]))
   {
      return;
   }

   // print the token phrase to the screen and capitalize
   cout << "\t" << (char)toupper(word[1]);

   // remove angle brackets
   for (int iLetters = 2; word[iLetters] != '>'; iLetters++)
   {
      // replace underscores
      if (word[iLetters] == '_')
      {
         // with a space
         cout << ' ';
      }
      else
      {
         // make sure the rest is lowercase
         cout << (char)tolower(word[iLetters]);
      }
   }

   // close question with a colon
   cout << ": ";

   // collect the users answer
   cin.getline(word, MAX_NUM_LETTERS);

   return;
}
