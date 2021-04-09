/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics with Corrupt Files
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Prompt the user for the name of a file containing user access records.
*    Prompt the user for a start and end time for comparison. Display a list
*    of all files that were accessed during that period along with the users
*    who accessed them. Validate data: check start/end times, missing
*    parameters, and corrupt data.
*
*    Estimated:  6.0 hrs   
*    Actual:     4.0 hrs
* Please describe briefly what was the most difficult part:
*    I thought I'd be able to plop in the logic to validate the data. That
*    ended up being more difficult than I thought; mostly because it was hard
*    for me to keep track of all the moving pieces while refactoring last
*    week's assignment. I ended up starting from scratch and copy/pasting my
*    code from last week, one function at a time, so I could keep it all
*    straight. Other that that, it went pretty well. I also included
*    suggestions from last week's feedback.
************************************************************************/

#include <cassert>  // assert lib
#include <iostream> // console in/out statements (cin/cout)
#include <iomanip>  // we will use setw() in this example
#include <fstream>  // file in/out statements (fin/fout)
#include <string>   // to use string class
#include <sstream>  // used to parse a line
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
void promptForFilename(UserData &file);
bool parseFile(AccessRecord logRecords[],
               UserData &userData);
void parseLine(string line,
               AccessRecord logRecords[],
               int recordNumber) throw(string);
void promptForStartAndEndTimes(UserData &times);
void displayAccessRecords(AccessRecord logRecords[],
                          UserData &userData);

/***********************************************************************
 * MAIN
 * This is the entry point and driver for the program.
 *    Vars: input      [struct] - user-defined data and number of records
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

   // valid source file: true/false
   bool isGoodFile;

   // re-prompt if invalid file
   do
   {
      // get the source file name
      promptForFilename(input);
      // check if source file is good
      isGoodFile = parseFile(logRecords, input);
   }
   while (!isGoodFile);

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
void promptForFilename(UserData &file)
{
   cout << "Enter the access record file: ";
   cin >> file.sourceFile;

   return;
}

/***********************************************************************
 * PARSE FILE
 * Parse the file, extracting data one line at a time. Pass extracted lines
 * to parseLine() for validation.
 *    INPUT: numRecords  [int]
 *    OUTPUT: logRecords [array]
 ************************************************************************/
bool parseFile(AccessRecord logRecords[],
               UserData &userData)
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

      return false;
   }

   // line retrieved from file
   string line;

   // read content to the end of the file one line at a time
   while (getline(fin, line))
   {
      try
      {
         // check for corrupt data and update logs array with valid data
         parseLine(line, logRecords, lineNumber);
      }
      catch (string text)
      {
         // tell user there's something wrong with the data
         cout << "Error parsing line: " << text << endl;
      }

      // increment the count so we know how many records there are
      lineNumber++;
   }

   // update structure with number of user records
   // minus 1 since array is zero-indexed
   userData.numRecords = lineNumber - 1;

   // close the read file
   fin.close();

   return true;
}

/***********************************************************************
 * PARSE LINE
 * Parse each line to check for errors and/or corrupt data. Update the logs
 * array with valid data.
 *    INPUT: line         [string]
 *    INPUT: logRecords   [array]
 *    INPUT: recordNumber [int]
 ************************************************************************/
void parseLine(string line,
               AccessRecord logRecords[],
               int recordNumber) throw(string)
{

   // read data one line at a time
   stringstream buffer(line);

   // update logs array
   buffer >> logRecords[recordNumber].filename
          >> logRecords[recordNumber].username
          >> logRecords[recordNumber].timestamp;

   // validate timestamps
   if (logRecords[recordNumber].timestamp < 1000000000 ||
       logRecords[recordNumber].timestamp > 10000000000)
   {
      // failed or corrupted data
      throw line;
   }
}

/***********************************************************************
 * PROMPT FOR START AND END TIMES
 * Get the start and end times from the user. Used to get a range of logs.
 *    OUTPUT: input.startTime [long]
 *            input.endTime   [long]
 ************************************************************************/
void promptForStartAndEndTimes(UserData &times)
{
   cout << "\nEnter the start time: ";
   cin >> times.startTime;

   while (cin.fail())
   {
      cin.clear();
      // skip over up to 256 characters
      // or until a newline char '\n' is encountered
      cin.ignore(256, '\n');
      cout << "Invalid input.\nEnter the start time: ";
      cin >> times.startTime;
   }

   cout << "Enter the end time: ";
   cin >> times.endTime;

   // I'm sure there's a better way to do this while loop (since it's
   // duplicated from lines 213 - 221) but I couldn't figure out how to make
   // it a modular. Could you provide insight when you grade this, please?
   while (cin.fail())
   {
      cin.clear();
      // skip over up to 256 characters
      // or until a newline char '\n' is encountered
      cin.ignore(256, '\n');
      cout << "Invalid input.\nEnter the end time: ";
      cin >> times.endTime;
   }

   return;
}

/***********************************************************************
 * DISPLAY ACCESS RECORDS
 * Display a table of access records within a given time range.
 *    INPUT: input [struct]
 *           logRecords [array]
 ************************************************************************/
void displayAccessRecords(AccessRecord logRecords[], UserData &userData)
{
   cout << endl
        << "The following records match your criteria:"
        << endl << endl;

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
