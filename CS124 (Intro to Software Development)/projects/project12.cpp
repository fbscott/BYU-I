/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    Sudoku game
*
*    Estimated:  4 hrs   
*    Actual:     8 hrs
*
* Please describe briefly what was the most difficult part:
*
*    I had trouble with spacing and line breaks, but otherwise, this project
*    was WAY easier than the Mad Lib. We'll see how next week goes.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cctype>    // for toupper and tolower
using namespace std;

void getSourceFileName(char fileName[]);
void displayMenu();
void getDestinationFileName(char destinationFileName[]);
bool readGameData(char grid[][9],
                  int numOfRowsAndColumns,
                  const char * fileName);
bool writeGameData(char grid[][9],
                   int numOfRowsAndColumns,
                   const char * fileName);
void displayGrid(char grid[][9],
                 int numOfRowsAndColumns);
void interact(char grid[][9],
              int numOfRowsAndColumns);
void editCell(char grid[][9],
              char coords[]);

/**
 * MAIN
 * Print, display, and edit Sudoku grid
 */
int main()
{

   // game data
   char grid[9][9];
   // max num of rows in game
   int numOfRowsAndColumns = 9;
   // file where game data is stored
   char sourceFileName[256];
   // file where game data will be written
   char destinationFileName[256];

   // get the source file name
   getSourceFileName(sourceFileName);
   // fetch the game data
   readGameData(grid, 9, sourceFileName);
   // display the game menu to the user
   displayMenu();
   // display the completed game board
   displayGrid(grid, numOfRowsAndColumns);
   // update game board
   interact(grid, numOfRowsAndColumns);
   // prompt for file where game data will be written
   getDestinationFileName(destinationFileName);
   // put game data
   writeGameData(grid, 9, destinationFileName);

   return 0;
}

/**
 * GET SOURCE FILE NAME
 * Prompt user for file containing Sudoku game data
 *    INPUT: source file
 */
void getSourceFileName(char sourceFileName[])
{
   // prompt the user
   cout << "Where is your board located? ";
   cin >> sourceFileName;

   return;
}

/**
 * DISPLAY MENU
 * Give user choices for gamer interaction
 */
void displayMenu()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n\n";

   return;
}

/**
 * GET DESTINATION FILE NAME
 * Prompt user for file where game can be saved
 *    INPUT: destination file
 */
void getDestinationFileName(char destinationFileName[])
{
   // prompt the user
   cout << "What file would you like to write your board to: ";
   cin >> destinationFileName;

   return;
}

/**
 * READ GAME DATA
 * Read game data from source file
 *    INPUT: game data, number of rows/columns, source file
 */
bool readGameData(char grid[][9],
                  int numOfRowsAndColumns,
                  const char * fileName)
{
   // declare the input stream
   ifstream fin(fileName);
   
   // error condition
   if (fin.fail())
   {
      return false;
   }

   // read the data from the file, one row at a time
   for (int iRow = 0; iRow < numOfRowsAndColumns; iRow++)
   { 
      // read the data from the file, one column at a time
      for (int iCol = 0; iCol < 9; iCol++)
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
 * Take game data and write it to a user-provided file
 *    INPUT: game data, number of rows/columns, source file
 */
bool writeGameData(char grid[][9],
                   int numOfRowsAndColumns,
                   const char * fileName)
{
   // declare the output stream
   ofstream fout(fileName);

   // error condition
   if (fout.fail())
   {
      return false;
   }

   // read the data from the array, one row at a time
   for (int iRow = 0; iRow < numOfRowsAndColumns; iRow++)
   { 
      // read the data from the array, one column at a time
      for (int iCol = 0; iCol < 9; iCol++)
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
   cout << "Board written successfully\n";

   return true;
}

/**
 * DISPLAY GAME BOARD/GRID
 * Take game data and display it on screen
 *    INPUT: game data, number of rows/columns
 */
void displayGrid(char grid[][9], int numOfRowsAndColumns)
{
   // column headers
   cout << "   A B C D E F G H I\n";

   // read data from the array one row at a time
   for (int row = 0; row < numOfRowsAndColumns; row++)
   {
      // row numbers
      cout << row + 1 << "  ";

      // read data from the array one column at a time
      for (int col = 0; col < numOfRowsAndColumns; col++)
      {
         // print number with vertical separator after
         // every 3rd number (except for last number in row)
         if (col % 3 == 2 && col < 8)
         {
            grid[row][col] == '0' ?
               cout << " |" :
                  cout << grid[row][col] << '|';
         }
         // put a space after remaining numbers
         else if (col < 8)
         {
            grid[row][col] == '0' ?
               cout << "  " :
                  cout << grid[row][col] << ' ';
         }
         // no space after last number in row
         else
         {
            grid[row][col] == '0' ?
               cout << " \n" :
                  cout << grid[row][col] << endl;
         }
      }
      // horizontal grid separator (every 3rd row)
      if (row % 3 == 2 && row < 8)
      {
         cout << "   -----+-----+-----\n";
      }
   }
   // space after board is displayed
   cout << endl;
}

/**
 * INTERACT
 * Allow user to choose which squares to update
 *    INPUT: game data, number of rows/columns
 */
void interact(char grid[][9], int numOfRowsAndColumns)
{
   // menu selection
   char menuSelection;
   // quit asking for info
   bool quit = false;
   // user-defined coordinates
   char coords[2];
   // value to be entered into game board
   // char destinationFileName[256];

   do
   {
      cout << "> ";
      cin >> menuSelection;

      switch (toupper(menuSelection))
      {
         case '?':
            displayMenu();
            cout << endl;
            break;
         case 'D':
            displayGrid(grid, numOfRowsAndColumns);
            break;
         case 'E':
            cout << "What are the coordinates of the square: ";
            cin >> coords;
            editCell(grid, coords);
            break;
         case 'S':
            // TO DO: add save logic
            break;
         case 'Q':
            quit = true;
            break;
      }
   }
   while (!quit);

   return;
}

/**
 * EDIT CELL
 * Allow user to edit/update incomplete cells
 *    INPUT: game data, coordinates of cell to be updated
 */
void editCell(char grid[][9], char coords[])
{
   // row index (ASCII value converted to numeric)
   int xCoord = (int)(toupper(coords[0])) - 65;
   // col index (ASCII value converted to numeric)
   int yCoord = coords[1] - 49;
   // user-provided cell value
   int cellValue;

   if (grid[yCoord][xCoord] > 48)
   {
      cout << "ERROR: Square '"
           << coords[0]
           << coords[1]
           << "' is filled"
           << endl << endl;
   }
   else
   {
      cout << "What is the value at '"
           << coords[0]
           << coords[1]
           << "': ";
      cin >> cellValue;
      cout << '\n';
      grid[yCoord][xCoord] = cellValue + 48;
   }

   return;
}
