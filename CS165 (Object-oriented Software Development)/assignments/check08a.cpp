/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
   private:
      string title;
      string author;
      int publicationYear;
   
   public:
      void promptBookInfo()
      {
         cout << "Title: ";
         getline(cin, title);

         cout << "Author: ";
         getline(cin, author);

         cout << "Publication Year: ";
         cin >> publicationYear;
         cin.ignore(256, '\n');
      }

      void displayBookInfo() const
      {
         cout << title << " (" << publicationYear << ") by " << author << endl;
      }
};

// TODO: Define your TextBook class here
class TextBook : public Book
{
   private:
      string subject;

   public:
      void promptSubject()
      {
         // called from the Book class
         promptBookInfo();

         cout << "Subject: ";
         getline(cin, subject);
      }

      void displaySubject() const
      {
         displayBookInfo();

         cout << "Subject: " << subject << endl;
      }
};

// TODO: Add your PictureBook class here
class PictureBook : public Book
{
   private:
      string illustrator;

   public:
      void promptIllustrator()
      {
         // called from the Book class
         promptBookInfo();

         cout << "Illustrator: ";
         getline(cin, illustrator);
      }

      void displayIllustrator() const
      {
         displayBookInfo();

         cout << "Illustrated by " << illustrator << endl;
      }
};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;

   book.promptBookInfo();
   cout << endl;
   book.displayBookInfo();
   cout << endl;


   // Declare a TextBook object here and call its methods
   TextBook textBook;

   textBook.promptSubject();
   cout << endl;
   textBook.displaySubject();
   cout << endl;

   // Declare a PictureBook object here and call its methods
   PictureBook pictureBook;

   pictureBook.promptIllustrator();
   cout << endl;
   pictureBook.displayIllustrator();

   return 0;
}


