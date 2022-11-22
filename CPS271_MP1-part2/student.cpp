#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "student.h"
using namespace std;

// This is the class constructor which initializes the class data members.
Student::Student()
{
	studentFName = "";
	studentLName = "";
	testScore = 0;
	grade = 'Z';
}

// This function is for receiving data from an input file and assigning it to the designated data members.
void Student::GetData(ifstream& inputFile)
{
	inputFile >> studentFName >> studentLName >> testScore;
}

// This functions checks the testScore data member and assigns the correct letter grade based on the test score.
void Student::AssignGrades()
{
	if (testScore >= 90)
		grade = 'A';
	else if (testScore >= 80 && testScore < 90)
		grade = 'B';
	else if (testScore >= 70 && testScore < 80)
		grade = 'C';
	else if (testScore >= 60 && testScore < 70)
		grade = 'D';
	else
		grade = 'F';
}

// This function linearlly searches the array of students to find the highest score achieved and returns it as an int.
int Student::FindHighScore(Student students[])
{
	int highScore = 0;
	for (int i = 0; i <= 19; i++)
	{
		if (highScore < students[i].testScore)
			highScore = students[i].testScore;
	}
	return highScore;
}

// This function linearlly scans the array of students to find which students have a testScore that matches the highScore, then concatenates them onto a string
// and returns the string with a message at the end announcing them as the top scorers.
string Student::HighScoreStudents(int highestScore, Student students[])
{
	int highScore = highestScore;
	string topStudents = "";
	for (int i = 0; i <= 19; i++)
	{
		if (students[i].testScore == highestScore)
		{
			topStudents += students[i].studentFName + " " + students[i].studentLName + ", ";
		}
	}
	topStudents += "are the top scorers.";
	return topStudents;
}

// This function prints all of the data of a memeber of the Student class to the console, but only the names to the output file. 
// A teacher could use this to check everyone's grades but still post a print out from the file without showing the students each other's grades.
void Student::PrintName(ofstream& outputFile)
{
	cout << left << studentLName << ", " << studentFName << "   " << testScore << " '" << grade << "'" << endl;
	outputFile << left << studentLName << ", " << studentFName << endl;
}