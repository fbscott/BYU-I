#include <iostream>
#include <string>

using namespace std;

// prototypes
string getFilePath();

int main()
{
	// My home dir: C:\Users\scott
	string path1 = getFilePath();
	string path2 = getFilePath();

	#ifndef compare paths
	if (path1 == path2)
	{
		cout << "The paths are homographs." << endl;
	}
	else
	{
		cout << "The paths are NOT homographs." << endl;
	}
	#endif

	cin.ignore();
}

string getFilePath()
{
	string path;

	cout << "Specify the first filename: ";

	do {
		cin >> path;
	} while (cin.fail());

	return path;
}
