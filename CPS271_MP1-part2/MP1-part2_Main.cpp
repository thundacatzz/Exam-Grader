#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include "student.h"
using namespace std;

// This block declares the i/o variables and the prototype functions for accessing them.
ofstream outputFile;
ifstream studentData;
void OpenOutputFile();
void OpenInputFile();

int main()
{
	// This block calls the file opening functions and declares the array of students.
	OpenOutputFile();
	OpenInputFile();
	Student students[20];

	// This loop iterates through each member of the array and performs the functions within, assigning values to their variables, calculating their grade,
	// and printing the relevant information.
	for(int i = 0; i <= 19; i++)
	{
		students[i].GetData(studentData);
		students[i].AssignGrades();
		students[i].PrintName(outputFile);
	}

	// These couple blocks output the highest score from the entire array and the names of which students had the highest score.
	cout << endl << "The high score is: " << students->FindHighScore(students) << endl;
	cout << students->HighScoreStudents(students->FindHighScore(students), students);
	
	outputFile << endl << "The high score is: " << students->FindHighScore(students) << endl;
	outputFile << students->HighScoreStudents(students->FindHighScore(students), students);
	
	// This block closes the i/o files.
	outputFile.close();
	studentData.close();
}

// This function opens the output file and returns an error message if it's unsuccessful.
void OpenOutputFile()
{
	outputFile.open("MP1-part2_Output.txt");
	if (outputFile.fail())
	{
		cout << "Failed to open output file";
		return;
	}
}

// This function opens the input file and returns an error message if it's unsuccessful.
void OpenInputFile()
{
	studentData.open("studentData.txt");
	if (studentData.fail())
	{
		cout << "Failed to open input file";
		return;
	}
}
