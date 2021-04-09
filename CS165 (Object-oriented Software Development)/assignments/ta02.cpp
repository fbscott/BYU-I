/***********************************************************************
* Program:
*    Team Activity 02, structs
*    Brother Walker, CS165
* Author:
*    Team #1 (Scott Currell)
* Summary: 
*    Display a scripture on screen. Then prompt the user for a new scripture
*    and display that new scripture on screen.
* ***********************************************************************/

#include <iostream>
using namespace std;

// structures
struct Scripture
{
   string book;
   int chapter;
   int verse;
};

// prototypes
void displayScripture(Scripture scripture[], int size);
void promptScripture(Scripture scripture[], int size);

/**********************************************************************
 * Function: main
 * Purpose: Display a scripture on screen. Then prompt the user for a new
 *          scripture and display that new scripture on screen.
 ***********************************************************************/
int main()
{
   // new instance of Scripture
   Scripture initialScripture[3];

   // prompt for new scripture
   promptScripture(initialScripture, (sizeof(initialScripture) / sizeof(initialScripture[0])));
   // print new scripture to screen
   displayScripture(initialScripture, (sizeof(initialScripture) / sizeof(initialScripture[0])));

   return 0;
}

/**********************************************************************
 * PROMPT USER FOR SCRIPTURE
 * Ask the user to provide a scripture
 * @param scripture [Scripture]
 ***********************************************************************/
void promptScripture(Scripture scripture[], int size)
{
   for(int i = 0; i < size; i++)
   {
      // prompt for book
      cout << "Book: ";
      cin.ignore();
      // update book
      getline(cin, scripture[i].book);
      // prompt for chapter
      cout << "Chapter: ";
      // update chapter
      cin >> scripture[i].chapter;
      // prompt for verse
      cout << "Verse: ";
      // update verse
      cin >> scripture[i].verse;
   }

   cout << endl;

   return;
}

/**********************************************************************
 * DISPLAY SCRIPTURE ON SCREEN
 * Receive a scripture as a parameter and print it on screen
 * @param scripture [Scripture]
 ***********************************************************************/
void displayScripture(Scripture scripture[], int size)
{
   for(int i = 0; i < size; i++)
   {
      // print scripture to screen
      cout << scripture[i].book
           << ' '
           << scripture[i].chapter
           << ':'
           << scripture[i].verse
           << endl;
   }

   return;
}
