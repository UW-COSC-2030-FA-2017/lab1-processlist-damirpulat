// Lab01.cpp
// Damir Pulatov
// 09/13/2017
// COSC 2030
// I received help from TA

#include<fstream>
using std::ifstream;

#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include<string>
using std::string;


int main()
{
	string fileName;
	double buffer[4];
	int count(0);

	// Ask for file name
	cout << "Print name of text file: " << endl;
	cin >> fileName;

	// Open text file
	ifstream inFile;
	inFile.open(fileName);

	// Print error if can't open text file
	if (!inFile)
	{
		cout << "Could not open " << fileName << endl;
		inFile.close();
		inFile.clear();
		return 1;
	}

	// Read in first and second numbers
	inFile >> buffer[0];
	count++;

	inFile >> buffer[1];
	count++;

	// Count number of numbers
	while (!inFile.eof() && !inFile.fail())
	{
		int temp;
		inFile >> temp;
		count++;
	}

	// Go back to beginning of file
	inFile.seekg(0, ios::beg);

	// Iterate through file
	for (int i = 0; i < count - 2; i++)
	{
		int temp;
		inFile >> temp;
	}

	// Read last two numbers
	inFile >> buffer[2];
	inFile >> buffer[3];


	// Print numbers
	cout << "The numbers are: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << buffer[i] << endl;
	}

	cout << "Number of numbers: " << count << endl;

	inFile.close();
	return 0;
}