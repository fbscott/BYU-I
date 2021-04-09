/***********************************************************************
* Program:
*    Assignment 42, Dem Bones
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

string generateSong(string list[], int num);

/**********************************************************************
 * MAIN
 * In this program, MAIN is a driver program.  It will feed to generateSong()
 * the list of bones and get back the complete song as a string.  MAIN will
 * then display the song
 ***********************************************************************/
int main()
{
   string list[9] =
   {
      "toe",
      "foot",
      "leg",
      "knee",
      "hip",
      "back",
      "neck",
      "jaw",
      "head"
   };

   // generate the song
   string song = generateSong(list, 9);

   // display the results
   cout << song;
   
   return 0;
}

/********************************************************************
 * GENERATE SONG
 * This function will generate one long string that constitutes the
 * complete song "Dem Bones."  Note that the list of bones is provided
 * by the parameter list
 ********************************************************************/
string generateSong(string list[], int num)
{
   string output;
   
   for (int i = 0; i < 8; i++)
   {
      output += list[i] + " bone connected to the " + list[i + 1] + " bone\n";
   }

   return output;
}
