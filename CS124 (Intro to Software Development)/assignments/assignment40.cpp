/***********************************************************************
* Program:
*    Assignment 40, Files
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Write a program to read a game data file, print game board to the screen,
*    and put the data back to another file.
*
*    Estimated:  2 hrs   
*    Actual:     4 hrs
*
* Please describe briefly what was the most difficult part:
*
*    I kept getting error with the write function. But I figured it out.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void getSourceFileName(char fileName[]);
void getDestinationFileName(char destinationFileName[]);
bool readGameData(char grid[][3], int numOfRows, const char * fileName);
bool writeGameData(char grid[][3], int numOfRows, const char * fileName);
void displayGrid(char grid[][3], int numOfRows);

/*********************************************************************
 * TIC-TAC-TOE GAME BOARD
 * Prompt the user for a file containing game data, format and display that
 * data to the screen, then write the data to another file.
 *********************************************************************/
int main()
{

   // game data
   char grid[3][3];
   // max num of rows in game
   int numOfRows = 3;
   // file where game data is stored
   char sourceFileName[256];
   // file where game data will be written
   char destinationFileName[256];

   // get the source filename
   getSourceFileName(sourceFileName);

   // fetch the game data
   readGameData(grid, 3, sourceFileName);

   // display the completed game board
   displayGrid(grid, numOfRows);

   // prompt for file where game data will be written
   getDestinationFileName(destinationFileName);

   // put game data
   writeGameData(grid, 3, destinationFileName);

   return 0;
}

/**
 * GET FILE NAME
 * Get filename where game data is stored
 *    INPUT:   sourceFileName (file containing game data)
 */
void getSourceFileName(char sourceFileName[])
{
   // prompt the user
   cout << "Enter source filename: ";
   cin >> sourceFileName;

   return;
}

/**
 * PUT FILE NAME
 * Get filename where game data will be written
 *    INPUT:   destinationFileName (file where game data will be written)
 */
void getDestinationFileName(char destinationFileName[])
{
   // prompt the user
   cout << "Enter destination filename: ";
   cin >> destinationFileName;

   return;
}

/**
 * READ GAME DATA
 */
bool readGameData(char grid[][3], int numOfRows, const char * fileName)
{
   // declare the input stream
   ifstream fin(fileName);
   
   // error condition
   if (fin.fail())
   {
      return false;
   }

   // read the data from the file, one row at a time
   for (int iRow = 0; iRow < numOfRows; iRow++)
   { 
      // read the data from the file, one column at a time
      for (int iCol = 0; iCol < 3; iCol++)
      {
         // read from the file
         fin >> grid[iRow][iCol];
      }

      // error condition
      if (fin.fail())
      { 
         fin.close();
         return false;
      } 
   }

   // close
   fin.close();

   return true;
}

/**
 * WRITE GAME DATA TO FILE
 * Take game board and write it to a user-provided file
 */
bool writeGameData(char grid[][3], int numOfRows, const char * fileName)
{
   // declare the output stream
   ofstream fout(fileName);

   // error condition
   if (fout.fail())
   {
      return false;
   }

   // read the data from the array, one row at a time
   for (int iRow = 0; iRow < numOfRows; iRow++)
   { 
      // read the data from the array, one column at a time
      for (int iCol = 0; iCol < 3; iCol++)
      {
         // write to the file
         fout << grid[iRow][iCol];
      }

      // error condition
      if (fout.fail())
      { 
         fout.close();
         return false;
      } 
   }

   // close the stream
   fout.close();

   // success verbiage
   cout << "File written\n";

   return true;
}

/**
 * DISPLAY GAME BOARD/GRID
 * Take game data and display in on screen
 */
void displayGrid(char grid[][3], int numOfRows)
{
   char spaceChar = ' ';

   // read the data from the array, one row at a time
   for (int row = 0; row < numOfRows; row++)
   {
      // read the data from the array, one column at a time
      for (int col = 0; col < 3; col++)
      {
         // output for end of row: "X", "O", or " "
         if (col == 2)
         {
            grid[row][col] == '.' ?
               cout << "   " << endl :
                  cout << ' ' << grid[row][col] << ' ' << endl;
         }
         // normal output: "X", "O", " ", or "|"
         else
         {
            grid[row][col] == '.' ?
               cout << "   " << '|' :
                  cout << ' ' << grid[row][col] << ' ' << '|';
         }
      }
      // horizontal grid separator
      if (row < 2)
      {
         cout << "---+---+---\n";
      }
   }
}
