/***********************************************************************
* Program:
*    Assignment 43 demo 2
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    This program will display the words to the song Dem Bones by
*    using the string class
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/***************************************
 * GET FILENAME
 * Prompt the user for the filename
 **************************************/
string getFilename()
{
   string fileName;
   cout << "Please enter the filename: ";
   cin  >> fileName;
   return fileName;
}

/**********************************************************************
 * MAIN
 * Parse the command line and call functions to do the hard work...
 ***********************************************************************/
int main(int argc, char **argv)
{
   // ensure the correct number of parameters was specified (two or fewer)
   // one for the name of the program, one for the filename
   // example: a.out [filename]
   if (argc > 2)
   {
      cout << "Unexpected number of parameters.\nUsage:\n";
      cout << "\t" << argv[0] << " [filename]\n";

      return 1;
   }

   // parse the command line
   string fileName;

   if (argc == 1) // only the program name was specified
   {
      fileName = getFilename();
   }
   else
   {
      fileName = argv[1];
   }

   // display the results
   cout << "The filename is \"" << fileName << "\"\n";

   return 0;
}
