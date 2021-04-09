/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Prompt the user for the name of a file containing user access records.
*    Prompt the user for a start and end time for comparison. Display a list
*    of all files that were accessed during that period along with the users
*    who accessed them.
*
*    Estimated:  6.0 hrs   
*    Actual:     12.0 hrs
* Please describe briefly what was the most difficult part:
*    I struggled more with last week's assignment. The only thing that
*    tripped me up this week was figuring out how to iterate through the
*    array of records. I didn't know how to find the number of lines in
*    the file. I ended up creating a counter in the read function to keep
*    track of how many lines were read. Maybe there's a better way, but this
*    worked for me
************************************************************************/

#include <iostream>
#include <iomanip>   // we will use setw() in this example
#include <string>    // to use string class
#include <fstream>   // file i/o
using namespace std;

// defines and consts
#define MAX_NUM_RECORDS 500

// structures
// access record
struct AccessRecord
{
   string filename;
   string username;
   long timestamp;
};

// user data
struct UserData
{
   string sourceFile;
   int numRecords;
   long startTime;
   long endTime;
};

// prototypes
void promptForFilename(UserData & file);
void readAccessRecords(AccessRecord logRecords[], UserData & fileSize);
void promptForStartAndEndTimes(UserData & times);
void displayAccessRecords(AccessRecord logRecords[], UserData & userData);

/***********************************************************************
 * MAIN
 * This is the entry point and driver for the program.
 *    Vars: input [struct] - user-defined data and number of records
 *          logRecords [array] - access records: filename
 *                                               username
 *                                               timestamp
 ************************************************************************/
int main()
{
   // new instance of UserData
   UserData input;
   // new instance of AccessRecord: log records
   AccessRecord logRecords[MAX_NUM_RECORDS];

   // get the source file name
   promptForFilename(input);
   // read access records from source file
   readAccessRecords(logRecords, input);
   // get start/end times
   promptForStartAndEndTimes(input);
   // display matched records on screen
   displayAccessRecords(logRecords, input);

   return 0;
}

/***********************************************************************
 * PROMPT FOR FILENAME
 * Get the source filename from the user. The file that contains the user
 * logs.
 *    OUTPUT: sourceFile [string]
 ************************************************************************/
void promptForFilename(UserData & file)
{
   cout << "Enter the access record file: ";
   cin >> file.sourceFile;
   cout << endl;

   return;
}

/***********************************************************************
 * READ ACCESS RECORDS
 * Read the data from the source file and build an array of records.
 *    INPUT: sourceFile [string]
 *    OUTPUT: logRecords [array]
 ************************************************************************/
void readAccessRecords(AccessRecord logRecords[], UserData & userData)
{
   // number of lines in file
   int lineNumber = 0;

   // open the source file (convert string to c-string)
   ifstream fin(userData.sourceFile.c_str());

   // check for read errors
   if (fin.fail())
   {
      // tell user there's something wrong with the file
      cout << "invalid file: " << userData.sourceFile << endl;

      return;
   }

   // read content to the end of the file
   while (!fin.eof())
   {
      // build an array of records
      fin >> logRecords[lineNumber].filename
          >> logRecords[lineNumber].username
          >> logRecords[lineNumber].timestamp;

      // increment the count so we know how many records there are
      lineNumber++;
   }

   // update structure with number of user records
   // minus 1 since array is zero-indexed
   userData.numRecords = lineNumber - 1;

   // close the read file
   fin.close();

   return;
}

/***********************************************************************
 * PROMPT FOR START AND END TIMES
 * Get the start and end times from the user. Used to get a range of logs.
 *    OUTPUT: input.startTime [long]
 *            input.endTime [long]
 ************************************************************************/
void promptForStartAndEndTimes(UserData & times)
{
   cout << "Enter the start time: ";
   cin >> times.startTime;
   cout << "Enter the end time: ";
   cin >> times.endTime;

   return;
}

/***********************************************************************
 * DISPLAY ACCESS RECORDS
 * Display a table of access records within a given time range.
 *    INPUT: input [struct]
 *           logRecords [array]
 ************************************************************************/
void displayAccessRecords(AccessRecord logRecords[], UserData & userData)
{
   cout << endl
        << "The following records match your criteria:"
        << endl
        << endl;

   // header
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(20) << "User" 
        << endl;
   // separator
   cout << "--------------- ------------------- -------------------" << endl;

   // write each record to the screen
   for (int i = 0; i < userData.numRecords; i++)
   {
      // only if they're within the specified time range
      if (logRecords[i].timestamp >= userData.startTime &&
          logRecords[i].timestamp <= userData.endTime)
      {
         cout << setw(15) << logRecords[i].timestamp
              << setw(20) << logRecords[i].filename
              << setw(20) << logRecords[i].username << endl;
      }
   }

   cout << "End of records\n";

   return;
}
