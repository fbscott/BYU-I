/******************************************************************************
* Program:
*    Lab 05, Homographs
*    Brother Wilson, CSE453
* Summary:
*   This program allows the user to compare two files to see if they
*   are homographs of eachother. The canon function uses the
*   secondFile passed in, to simulate doing actual commands on
*   the file system, in order to modify the 'working directory' file path.
*   If the file path we are modifying, and the 'secret' file path are the same,
*   then we know that the two file are homographs.
*
******************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

// methods and file variables
bool endsWith(string str, const char endingCharacter)              { return str[str.length() - 1] == endingCharacter;    }
bool containsString(const string filePath, const string toFind) { return filePath.find(toFind) != std::string::npos;  }
bool menu();
bool isHomograph(const string firstFile, const string secondFile);
string canonicalization(string runningFilePath, string secondFile, bool isConvertingForbiddenFile);
string canonon(string str);
void displayResults(bool areHomographs) { cout << (areHomographs ? "Yes - " : "NO - ") << "These paths are " << (areHomographs ? "" : "NOT ") << "homographs\n" << endl; }
void removeFolderFromEnd(string &filePath, bool isConvertingForbiddenFile);
void runManualTests();
void runAutomatedTests();
void testCaseLoop(const char **testPaths, int size, string forbiddenPath);

const string WORKING_DIRECTORY = "/home/user/cse453/week05/";

int main()
{
    bool runTests = true;

    // continue showing the menu until the user quits (option 3)
    do
    {
        runTests = menu();
    } while (runTests);

    return 0;
}

/******************************************************************************
 * REMOVE FOLDER FROM END
 * This will simulate going 'up' a directory by removing the current file path
 * from the end.
 *****************************************************************************/
void removeFolderFromEnd(string &filePath, bool isConvertingForbiddenFile)
{
    bool endsWithFile = containsString(filePath, ".txt");
    for (int i = filePath.length(); i >= 0; i--)
    {
        if (filePath[i] == '/')
        {
            // remove the folder from the end
            filePath.erase(i--, filePath.length() - 1);
            
            // need to do this again, to completely get out of the current folder
            if (endsWithFile && !isConvertingForbiddenFile)
               endsWithFile = false;
            else
                return;
        }
    }
}

/******************************************************************************
 * CANON
 * Convert all file paths to a consistent format.
 *****************************************************************************/
string canon(string str) 
{
    
    transform(str.begin(), str.end(), str.begin(),
    [](unsigned char c)
    {
         // make everything follow the '/' format (sorry windows)
        if (c == '\\')
            c = '/';
        
        // convert to lower case
        return tolower(c);
    });
   
    // remove all './' since those don't matter
    while (str[0] == '.' && str[1] == '/') 
    {
        
        if (str[2] == '.')
            str.erase(0,2); // remove the './'
        else 
        {
            bool isFile = false;
            // 2 different cases to check for:
            // 1. './' is in front of an actual file, so remove the './' (ex. ./test.txt => test.txt)
            // 2. It is in front of a folder, so keep the '/' (ex ./home/ => /home/)
            for (int i = 2; i < str.length(); i++) 
            {
                if (str[i] == '.') 
                {
                    str.erase(0,2); // remove './'
                    break;
                }
                if (str[i] == '/' && !isFile) // only remove the '.'
                {
                    str.erase(0,1);
                    break;
                }
            }
        }
    }
    
    return str;
}

/******************************************************************************
 * CANONICALIZATION
 * Loop over the second file, and use it to modfy the runningFilePath variable.
 * Compare the two at the end to see if they are homographs.
 *****************************************************************************/
string canonicalization(string runningFilePath, string secondFile, bool isConvertingForbiddenFile)
{
    string folderName = "";
    
    // clean up the file ending if need be
    if (endsWith(runningFilePath, '/'))
        runningFilePath.pop_back();
    
    for (int i = 0; i < secondFile.length(); i++)
    {
        bool haveRemovedFromEnd = false;
        
        if (secondFile[i] == '.')
        {
            if (secondFile[i + 1] == '.')
            {
                // came across a ../ so go 'up' a level
                removeFolderFromEnd(runningFilePath, isConvertingForbiddenFile);
                haveRemovedFromEnd = true;
                i += 2;
            }
        }
        // we are iterating of a folder name
        if (!haveRemovedFromEnd)
        {
            if (secondFile[i] == '/')
            {
                // this simulates doing the 'cd /somefolder' command
                runningFilePath += (endsWith(runningFilePath, '/') && !isConvertingForbiddenFile ? "" : "/") + folderName + "/";
                folderName = ""; // clear the string holding the current folder name
            }
            else // keep adding to the folder name
                folderName += secondFile[i];
        }
    }
    
    return runningFilePath += ((isConvertingForbiddenFile ? "/" : "") + folderName);
}

/******************************************************************************
 * IS HOMOGRAPH
 * Gets the full path of the secret file path, and calls the canon function.
 *****************************************************************************/
bool isHomograph(const string firstFile, const string secondFile)
{
    if (firstFile == secondFile)
        return true;

    if (firstFile == "" || secondFile == "")
        return false;

    bool isInCurrentDirectory = false;
    string secretFilePathFull = "";
    
    if (containsString(firstFile, "/home/")) // full secret file path was passed in
        secretFilePathFull = firstFile;
    else if (!containsString(firstFile, "/")) // secret file is in the current directory
    {
        secretFilePathFull = WORKING_DIRECTORY + firstFile;
        isInCurrentDirectory = true;
    }
    // Getting here means that the secret path passed in was relative to the
    // current dir, so we need to use it to modify the working directory to get
    // the actual full path by calling the Canaon function on it.
    else
        secretFilePathFull = canonicalization(WORKING_DIRECTORY, firstFile, true);
        
    if (secretFilePathFull == secondFile)
        return true;

    string runningFilePath = (isInCurrentDirectory ?
                              secretFilePathFull :// the generated one with canon function
                              WORKING_DIRECTORY);
  
    runningFilePath = canonicalization(runningFilePath, secondFile, false);
    
    return secretFilePathFull == runningFilePath;
}

/******************************************************************************
 * RUN MANUAL TESTS
 * Allow the user to manually enter test cases.
 *****************************************************************************/
void runManualTests()
{
    string forbiddenPath = "";
    string secondPath = "";

    // Add the code to let the user choose to run the automated tests or
    // manually enter in the file paths.
    cout << "\nPlease specify the first file name: ";
    cin >> forbiddenPath;

    cout << "Please specify the second file name: ";
    cin >> secondPath;

    displayResults(isHomograph(canon(forbiddenPath), canon(secondPath)));

    return;
}

/******************************************************************************
 * TEST CASE LOOP
 * Loop through an array of test case paths and apply the canonicalization
 * function.
 *****************************************************************************/
void testCaseLoop(const char **testPaths, int size, string forbiddenPath)
{
    for (unsigned int i = 0; i < size; i++)
    {
        cout << "\nComparing " << forbiddenPath << " and " << testPaths[i] << "\n" << endl;
        displayResults(isHomograph(canon(forbiddenPath), canon(testPaths[i])));
    }

    return;
}

/******************************************************************************
 * RUN AUTOMATED TESTS
 * Automatically run hardcoded test cases.
 *****************************************************************************/
void runAutomatedTests()
{
    // test case 01
    string forbiddenPath_01 = "/home/user/secret/password.txt";

    const char *testCases_01[] = {
        "./../../secret/password.txt",
        "./././././../../secret/password.txt",
        "../../secret/password.txt",
        "../secret/password.txt",
        "../cs453/password.txt"
    };

    testCaseLoop(testCases_01, (sizeof(testCases_01) / sizeof(testCases_01[0])), forbiddenPath_01);

    // test case 02
    string forbiddenPath_02 = "test.txt";

    const char *testCases_02[] = {
        "../../cSE453/wEeK05/test.txt",
        "./../../cSE453/wEeK05/test.txt",
        "../test.txt",
        "home/user/cse453/week05/test.txt",
        ""
    };

    testCaseLoop(testCases_02, (sizeof(testCases_02) / sizeof(testCases_02[0])), forbiddenPath_02);

    // test case 03
    string forbiddenPath_03 = "/home/user/documents/login/password/password.txt";

    const char *testCases_03[] = {
        "../../documents/login/password/password.txt",
        "./../../documents/LOGIN/PASSWORD/password.txt",
        "../../../user/documents/login/password/password.txt",
        "password.txt",
        "../../documents/password.txt",
        ""
    };

    testCaseLoop(testCases_03, (sizeof(testCases_03) / sizeof(testCases_03[0])), forbiddenPath_03);

    return;
}

/******************************************************************************
 * MENU
 * Present the user with menu selections.
 *****************************************************************************/
bool menu()
{
    bool retest = false;
    int selectedOption = 1;

    cout << "Do you want to execute the tests, or manually enter them in?\n"
        "1. Run tests\n"
        "2. Manually enter in\n"
        "3. Quit" << endl;

    cin >> selectedOption;

    switch (selectedOption)
    {
    case 1:
        retest = true;
        runAutomatedTests();
        break;
    case 2:
        retest = true;
        runManualTests();
        break;
    case 3:
        retest = false;
        break;
    default:
        // start again if the user selects anything other than 1, 2, or 3
        menu();
    }

    return retest;
}
