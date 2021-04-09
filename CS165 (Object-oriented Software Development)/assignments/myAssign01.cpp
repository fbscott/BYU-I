/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Prompt the user for his/her DNA sequence, a number of relatives, their
*    names and respective DNA sequences, then compare each sequence to the
*    researcher's sequence. Return a percentage "match" score for each
*    relative.
*
*    Estimated:  3.0 hrs   
*    Actual:     6.0 hrs
* Please describe briefly what was the most difficult part:
*    I struggled with matching the letter of each DNA sequence to the
*    comparison sequence. My nested for loops had transposed boolean
*    variables. It took me quite a lot of time to find the error.
*
*    Note about loops: The Week 2 Hint (April 30) states, "Non-standard,
*    start at 1 and go <= size, instead of start at 0 to < size." Based
*    on the wording, I couldn't tell if that meant I should or shouldn't
*    start a loop with "1." I started at "0" since that's the way I learned
*    to do it. Please let me know if that is incorrect.
************************************************************************/

#include <iostream>
#include <string> // to use string class
using namespace std;

// prototypes
string getDNASequence();
int getNumRelatives();
void getRelativesNames(char relatives[][256],
                       int numRelatives);
void getRelativesDNASequences(char relatives[][256],
                              char dnaSequences[][11],
                              int numRelatives);
void matchDNASequences(char relatives[][256],
                       char dnaSequences[][11],
                       int numRelatives,
                       string dnaSequence);
void displayResult(string relativeName, int percentMatch);

/***********************************************************************
 * Prompt the user for a 10-character DNA marker sequence, a number of
 * potential relatives, the names of each of these potential relatives, and
 * a 10-character DNA marker sequence of each of the potential relatives.
 * Display each potential relative along with the percentage that their
 * sequence matched the target user.
 ************************************************************************/
int main()
{
   // base DNA sequence
   string dnaSequence = getDNASequence();
   // number of relatives
   int numRelatives = getNumRelatives();
   // names of relatives [max num possible relatives][names]
   char relatives[50][256];
   // relatives' DNA sequences [max num possible relatives][DNA sequences]
   char relativesDNASequences[50][11];

   // prompt for relatives' names
   getRelativesNames(relatives,
                     numRelatives);
   // prompt for relatives' DNA sequences
   getRelativesDNASequences(relatives,
                            relativesDNASequences,
                            numRelatives);
   // match DNA sequences
   matchDNASequences(relatives,
                     relativesDNASequences,
                     numRelatives,
                     dnaSequence);

   // end function
   return 0;
}

/***********************************************************************
 * GET DNA SEQUENCE
 * Prompt user for a DNA sequence as a base for comparison.
 *    OUTPUT: dnaSequence [String]
 ************************************************************************/
string getDNASequence()
{
   // DNA sequence
   string dnaSequence;

   // prompt user for DNA sequence
   cout << "Enter your DNA sequence: ";
   // update DNA sequence with user-provided entry
   cin >> dnaSequence;

   // return DNA sequence
   return dnaSequence;
}

/***********************************************************************
 * GET NUMBER OF RELATIVES
 * Prompt user for a number of relatives.
 *    OUTPUT: numRelatives[Int]
 ************************************************************************/
int getNumRelatives()
{
   // number of relatives
   int numRelatives;

   // prompt user for number of relatives
   cout << "Enter the number of potential relatives: ";
   // update number of relatives
   cin >> numRelatives;

   // return number of relatives
   return numRelatives;
}

/***********************************************************************
 * GET RELATIVES' NAMES
 * Prompt user for relatives' names
 *    INPUT: relatives[Array],
 *           numRelatives[Int]
 ************************************************************************/
void getRelativesNames(char relatives[][256],
                       int numRelatives)
{
   // start with a new line return
   cout << endl;

   // prompt user for a number of names (based on what s/he provided) as a
   // number of relatives
   for (int i = 0; i < numRelatives; i++) // see note about loops in header
   {
      // prompt user for relatives' names
      cout << "Please enter the name of relative #" << i + 1 << ": ";
      // update array of names
      cin >> relatives[i];
   }

   // end function
   return;
}

/***********************************************************************
 * GET RELATIVES' DNA SEQUENCES
 * Prompt user for relatives' DNA sequences
 *    INPUT: relatives[Array],
 *           dnaSequences[Array],
 *           numRelatives[Int]
 ************************************************************************/
void getRelativesDNASequences(char relatives[][256],
                              char dnaSequences[][11],
                              int numRelatives)
{
   // start with a new line return
   cout << endl;

   // prompt user for a number of DNA sequences (based on what s/he
   // provided) as a number of relatives
   for (int i = 0; i < numRelatives; i++) // see note about loops in header
   {
      // prompt user for relatives' DNA sequences
      cout << "Please enter the DNA sequence for " << relatives[i] << ": ";
      // update array of names
      cin >> dnaSequences[i];
   }

   // end function
   return;
}

/***********************************************************************
 * MATCH DNA SEQUENCES
 * Compare each relatives' DNA sequence against the one provided by the user
 * and pass a percent match to the display function.
 *    INPUT: relatives[Array],
 *           dnaSequences[Array],
 *           numRelatives[Int],
 *           dnaSequence[String]
 ************************************************************************/
void matchDNASequences(char relatives[][256],
                       char dnaSequences[][11],
                       int numRelatives,
                       string dnaSequence)
{
   // start with a new line return
   cout << endl;

   // starting percentage
   int percentMatch = 0;
   // name of relative after each iteration
   string relativeName;

   // iterate over each relative
   for (int i = 0; i < numRelatives; i++) // see note about loops in header
   {
      // iterate over each letter in each relatives' DNA sequence
      for (int j = 0; j < 10; j++) // see note about loops in header
      {
         // if letter from sequence is a match
         if (dnaSequences[i][j] == dnaSequence[j])
         {
            // increment the percentage
            percentMatch++;
         }
      }

      // update relatives' names
      relativeName = relatives[i];
      // print the resultant relatives' match percentage to the screen
      displayResult(relativeName, percentMatch);
      // reset the count
      percentMatch = 0;
   }

   // end function
   return;
}

/***********************************************************************
 * DISPLAY RESULT
 * Print each relative's name and match percentage to the screen
 *    INPUT: relativeName[String],
 *           percentMatch[Int]
 ************************************************************************/
void displayResult(string relativeName, int percentMatch)
{
   cout << "Percent match for "
        << relativeName
        << ": "
        << percentMatch * 10
        << "%\n";
}
