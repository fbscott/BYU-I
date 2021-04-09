/***********************************************************************
* Program:
*    Project 10, Mad Lib Pt 2
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    The second part of the Mad Lib project: read the Mad Lib from a file and
*    prompt the user.
*
*    Estimated:  6 hrs   
*    Actual:     18 hrs
*
* Please describe briefly what was the most difficult part:
*    I struggled with the multiple, nested if statements to get my program
*    to display the story correctly. I don't like it. I feel there's got to
*    be a better solution out there, but I made due with what I know.
************************************************************************/

#include <iostream>  // cin/cout statements
#include <fstream>   // to read from files
#include <cctype>    // for toupper and tolower
#include <cassert>   // use asserts
using namespace std;

// styleChecker doesn't like this formatting, but it's consistent with the
// book.
#define MAXWORDS 256
#define MAXLETTERS 33

int readFile(char story[][MAXLETTERS]);
void askQuestions(char word[]);
void getFilename(char fileName[]);
void displayStory(char story[][MAXLETTERS], int numOfWordsRead);
bool playAgain();
void isPunct(char word[], int doublePunct);

/**********************************************************************
 * MAIN
 * Read words from a user-provided file and extract token phrases.
 ***********************************************************************/
int main()
{

   // start off true so the game plays at least once
   bool playGame = true;

   // play the game at least once, then loop back if the user wants to replay
   do
   {
      // the Mad Lib story
      char story[MAXWORDS][MAXLETTERS];
      // number of words in the story
      int numOfWordsRead = readFile(story);
      // display the updated story (with tokens replaced) on screen
      displayStory(story, numOfWordsRead);
      // ask the user if s/he wants to replay
      playGame = playAgain();
   }
   // continue loop if parameter == true
   while (playGame);

   return 0;
}

/**********************************************************************
 * READ FILE
 * Read the words from the file.  Make sure there is no more words in the
 * file than we have room in our array!
 *    INPUT:   filename, word array (story)
 *    OUTPUT:  updated word array (story) via pass-by-reference
 ***********************************************************************/
int readFile(char story[][MAXLETTERS])
{
   // fetch the filename via user prompt
   char fileName[256];
   // get the file name
   getFilename(fileName);
   // open the file for reading
   // open the input stream to fileName
   ifstream fin(fileName);
   // check for read errors
   if (fin.fail())
   {
      cout << "ERROR: Unable to read file "
           // display the filename we tried to read
           << fileName
           << endl;
      // return the error condition: none read
      return 0;
   }

   // no words read at the start
   int numOfWordsRead = 0;
   // loop through the file, reading
   // the elements one at a time
   // don't read more than the list holds
   while (numOfWordsRead < MAXWORDS &&
          // read and check for errors
          fin >> story[numOfWordsRead])
   {
      // prompt the user for a token
      askQuestions(story[numOfWordsRead]);
      // increment the index by one
      numOfWordsRead++;
   }
   
   // close the file and return
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

   // print the first letter of the token phrase to the screen and capitalize
   cout << "\t" << (char)toupper(word[1]);

   // then every other letter that is not a closing angle bracket (>)
   for (int i = 2; word[i] != '>'; i++)
   {
      // replace underscores
      if (word[i] == '_')
      {
         // with a space
         cout << ' ';
      }
      else
      {
         // make sure the rest is lowercase
         cout << (char)tolower(word[i]);
      }
   }

   // close question with a colon
   cout << ": ";

   // collect the users answer
   cin.getline(word, MAXLETTERS);

   return;
}

/*********************************************************************
 * GET FILENAME
 * Prompt the user for the name of the file and return it.
 *    OUTPUT: fileName (name of the file where Mad Lib is stored)
 *********************************************************************/
void getFilename(char fileName[])
{
   // prompt for a filename
   cout << "Please enter the filename of the Mad Lib: ";
   // write the filename back to the pointer
   cin >> fileName;
   // ignore new line characters
   cin.ignore();
   return;
}

/*********************************************************************
 * DISPLAY
 * Display the completed Mad Lib
 *    INPUT: story array
 *********************************************************************/
void displayStory(char story[][MAXLETTERS], int numOfWordsRead)
{

   // identify when a new line is required
   bool newLine = false;

   // put some space above the story
   cout << endl;

   // print each word of the story to the screen
   for (int i = 0; i < numOfWordsRead; i++)
   {
      // replace token placeholder for actual punctuation
      if (story[i][0] == '<' ||
          story[i][0] == '.' ||
          story[i][0] == ',' ||
          story[i][0] == '!' ||
          story[i][0] == '?')
      {
         // don't add spaces if new line
         if (newLine && (story[i][1] == '{' || story[i][1] == '['))
         {
            isPunct(story[i], 1);
            cout << story[i];
            newLine = false;
         }
         // don't add spaces if double punctuation (" ")
         else if (story[i + 1][0] == '<' ||
             story[i + 1][0] == '.' ||
             story[i + 1][0] == ',' ||
             story[i + 1][0] == '!' ||
             story[i + 1][0] == '?')
         {
            if (story[i][1] == '#' &&
               (story[i + 1][1] == '{' || story[i + 1][1] == '['))
            {
               newLine = true;
            }
            isPunct(story[i], 2);
            cout << story[i];
         }
         // normal output (spaces, words, punct, etc.)
         else
         {
            if (story[i][1] == '#' &&
               (story[i + 1][1] == '{' || story[i + 1][1] == '['))
            {
               newLine = true;
            }
            isPunct(story[i], 3);
            cout << story[i];
         }
      }
      // check if next character is punctuation
      else
      {
         if (story[i + 1][0] == '<' ||
             story[i + 1][0] == '.' ||
             story[i + 1][0] == ',' ||
             story[i + 1][0] == '!' ||
             story[i + 1][0] == '?')
         {
            cout << story[i];
         }
         else
         {
            cout << story[i] << ' ';
         }
      }
   }

   // put some space below the story
   cout << endl;

   return;
}

/*********************************************************************
 * IS PUNCTUATION
 * Determin which punctuation to use based on token and/or inline value.
 *    INPUT: word array
 *********************************************************************/
void isPunct(char word[], int doublePunct)
{
   // tokens
   switch (word[1])
   {
      case '#':
         word[0] = '\n';
         word[1] = '\0';
         word[2] = '\0';
         break;
      case '{':
         if (doublePunct != 1)
         {
            word[0] = ' ';
            word[1] = '\"';
            word[2] = '\0';
         }
         else if (doublePunct == 1)
         {
            word[0] = '\"';
            word[1] = '\0';
            word[2] = '\0';
         }
         break;
      case '}':
         if (doublePunct == 3)
         {
            word[0] = '\"';
            word[1] = ' ';
            word[2] = '\0';
         }
         else
         {
            word[0] = '\"';
            word[1] = '\0';
            word[2] = '\0';
         }
         break;
      case '[':
         if (doublePunct != 1)
         {
            word[0] = ' ';
            word[1] = '\'';
            word[2] = '\0';
         }
         else if (doublePunct == 1)
         {
            word[0] = '\'';
            word[1] = '\0';
            word[2] = '\0';
         }
         break;
      case ']':
         if (doublePunct == 3)
         {
            word[0] = '\'';
            word[1] = ' ';
            word[2] = '\0';
         }
         else
         {
            word[0] = '\'';
            word[1] = '\0';
            word[2] = '\0';
         }
         break;
   }
   // standard punctuation
   switch (word[0])
   {
      case '.':
         word[0] = '.';
         if (doublePunct == 3)
         {
            word[1] = ' ';
            word[2] = '\0';
         }
         break;
      case ',':
         word[0] = ',';
         if (doublePunct == 3)
         {
            word[1] = ' ';
            word[2] = '\0';
         }
         break;
      case '!':
         word[0] = '!';
         if (doublePunct == 3)
         {
            word[1] = ' ';
            word[2] = '\0';
         }
         break;
      case '?':
         word[0] = '?';
         if (doublePunct == 3)
         {
            word[1] = ' ';
            word[2] = '\0';
         }
         break;
   }

   return;
}

/*********************************************************************
 * PLAY AGAIN
 * Ask the user if s/he wants to play again.
 *    INPUT: user input (y/n)
 *********************************************************************/
bool playAgain()
{
   // assume user doesn't want to play again (no one can play forever)
   bool replay = false;
   // y/n || Y/N
   char response;

   // ask the user if s/he wants to play again
   cout << "Do you want to play again (y/n)? ";
   // record the response
   cin >> response;
   
   // if y || Y, replay
   // if n || N, thank the user and quit
   switch (response)
   {
      case 'y':
      case 'Y':
         replay = true;
         break;
      case 'n':
      case 'N':
         replay = false;
         cout << "Thank you for playing.\n";
   }

   return replay;
}
