// vcfmaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string aSpace = " ";
string firstName;
string lastName;

int main()
{
	cout << "Welcome to the Contact Card Maker!  If you would like to skip an entry, (ex. nickname), type skip." << endl << "Please enter the first name of the contact:" << aSpace;
	// First name && welcome
	getline(cin, firstName);
	transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
	if (firstName == "skip") {
		cout << "First Name Skipped." << endl;
		firstName = "";
		goto lastnamegoto;
	}
	else {
		firstName[0] = toupper(firstName[0]);
		cout << firstName << aSpace << "Registered." << endl;
		goto lastnamegoto;
	}
	// Last Name
	lastnamegoto:
	cout << "Please enter the last name of the contact: " << aSpace;
	getline(cin, lastName);
	if (lastName == "skip") {
		cout << "Last Name Skipped." << endl;
		lastName = "";
		// goto phonenumgoto;
		// random
		// another
	}
	else {
		lastName[0] = toupper(lastName[0]);
		cout << lastName << aSpace << "Registered." << endl;
		// goto phonenumgoto;
	}
	return 0;
}
