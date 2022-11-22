#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// This header is for declaring the Student class and its constituent objects and functions.
class Student
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
public:
	Student();
	void GetData(ifstream&);
	void AssignGrades();
	int FindHighScore(Student students[]);
	string HighScoreStudents(int highestScore, Student students[]);
	void PrintName(ofstream&);
};