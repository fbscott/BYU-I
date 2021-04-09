/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Schwieder, CS124
*    
* Author:
*    Scott Currell
*    
* Summary: 
*    Write a program to read 10 grades from a file and display the average.
*
*    Estimated:  2 hrs   
*    Actual:     4 hrs
*
* Please describe briefly what was the most difficult part:
*
*    Poor instructions made this assignment difficult.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void getFileName(char fileName[]);
float readFile(char fileName[]);
void display(float average);

/*********************************************************************
 * FIND GRADE AVERAGE
 * Prompt the user for a file containing grades and calculate the average.
 *********************************************************************/
int main()
{
   char fileName[256];
   
   getFileName(fileName);

   float average = readFile(fileName);

   display(average);
   return 0;
}

/*********************************************************************
 * GET FILE NAME
 * Prompt the user for the name of the file and return it.
 *    OUTPUT: fileName (name of the file where grades are stored)
 *********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
   return;
}

/*********************************************************************
 * READ FILE
 * Read the file and return the average score.
 *    INPUT: fileName (name of the file where grades are stored)
 *    OUTPUT: the average grade
 *********************************************************************/
float readFile(char fileName[])
{
   // declare the output stream
   ifstream fin(fileName);

   // print failed fileName to screen
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"\n";
      return false;
   }
   
   int currentGrade  = 0;
   float sum         = 0;
   int i             = 0;
   float average     = 0;

   for(i; fin >> currentGrade; i++)
   {
      // add each grade in fileName to sum
      sum += currentGrade;
   }

   // fail if there are not exactly 10 grades in a file
   if (i != 10)
   {
      cout << "Error reading file \"" << fileName << "\"\n";
      return false;
   }

   // find the average
   average = sum / i;

   // close the stream
   fin.close();

   return average;
}

/*********************************************************************
 * DISPLAY
 * Display the average score to zero decimals of accuracy (rounded).
 *    INPUT: the average grade
 *********************************************************************/
void display(float average)
{
   // configure the output to display money for monthly income
   cout.setf(ios::fixed); // no scientific notation
   cout.precision(0); // no decimals

   if(average != 0)
   {
      cout << "Average Grade: " << average << "%" << endl;
   }
   return;
}
