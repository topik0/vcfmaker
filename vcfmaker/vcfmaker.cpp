// vcfmaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string aSpace = " ";
string firstName = "null";
string lastName = "null";

int main()
{
	cout << "Welcome to the Contact Card Maker!" << endl << "Please enter the first name of the contact:" << aSpace;
	getline(cin, firstName);
	firstName[0] = toupper(firstName[0]);
	cout << firstName << aSpace << "registered." << aSpace;
	cout << "Please enter the last name of the contact: " << aSpace;
	getline(cin, lastName);
	lastName[0] = toupper(lastName[0]);
	return 0;
}

