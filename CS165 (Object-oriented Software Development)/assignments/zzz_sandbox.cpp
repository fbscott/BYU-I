/*****************************************************************************
 * SANDBOX
 * This file is for test purposes only. Used to practice new concepts,
 * experiment, and write code samples.
 ****************************************************************************/

#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>   // for setw()
#include <cstdlib>   // for atof()
using namespace std;

// prototypes
int countLetters(string dnaSequence, char words[][11], int numRelatives);

/**
 * MAIN
 * Driver program
 */
int main()
{
   char words[4][11] = {"TTTCGACTGA",   // 90% match
                        "AAACGTCAGT",   // 50% match
                        "ATTGCAGTCA",   // 60% match
                        "ATTCGACTGA"};  // 1000% match
   string dnaSequence = "ATTCGACTGA";
   int numRelatives = 4;

   countLetters(dnaSequence, words, numRelatives);

   return 0;
}

int countLetters(string dnaSequence, char words[][11], int numRelatives)
{
   int numLetters = 0;

   for(int i = 0; i < numRelatives; i++)
   {
      for(int j = 0; j < 10; j++)
      {
         if(words[i][j] == dnaSequence[j])
         {
            numLetters++;
         }
      }
      cout << "Percent match for [name]: " << numLetters * 10 << "%\n";
      numLetters = 0;
   }

   return numLetters;
}
