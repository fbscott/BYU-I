/***********************************************************************
* Program:
*    Checkpoint 04a, classes
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// classes
class Book
{
   // member variables
   private:
      string title;
      string author;

   // member functions (methods)
   public:
      void prompt();
      void display();
};

/**
 * MAIN
 * This is the entry point and driver for the program.
 */
int main()
{
   // instantiate a Book object
   Book book;

   book.prompt();
   book.display();
   
   return 0;
}

/**
 * BOOK :: PROMPT
 * Prompt the user for a title and author
 */
void Book :: prompt()
{
   cout << "Title: ";
   getline(cin, title);
   cout << "Author: ";
   getline(cin, author);

   return;
}

/**
 * BOOK :: DISPLAY
 * Display the results from user input
 */
void Book :: display()
{
   cout << "\"" << title << "\" by " << author << endl;

   return;
}
