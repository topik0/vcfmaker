// vcfmaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "windows.h"
using namespace std;

int YesOrNo(string yesno);
int i = 0;
int q = 0;

string aSpace = " ";
string firstName;
string lastName;
string yesnos = "[Yes/No]";
string yesno;
string fileNamePromt;


string temp;
string tempOne;
string tempTwo;
vector <string> phonenum;
vector <string> phoneName;
vector <string> emailAdrs;
vector <string> emailName;

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
	transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
	if (lastName == "skip") {
		cout << "Last Name Skipped." << endl;
		lastName = "";
		goto phonenumgoto;
	}
	else {
		lastName[0] = toupper(lastName[0]);
		cout << lastName << aSpace << "Registered." << endl;
		goto phonenumgoto;
	}
phonenumgoto:
anothaNumba:
	cout << "Please enter a phone number for contact (Note: separate the number by dashes, like this, XXX-XXX-XXXX):" << aSpace;
	getline(cin, temp);
	phonenum.push_back(temp);
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	if (temp == "skip") {
		cout << "Skipped Phone Number." << endl;
		temp = "";
		goto emailgoto;
	}
	else {
		cout << "Please enter a name for the phone number (ex. Home, Work):" << aSpace;
		getline(cin, tempOne);
		phoneName.push_back(tempOne);
		tempOne[0] = toupper(tempOne[0]);
		cout << tempOne << aSpace << "phone" << aSpace << temp << aSpace << "Registered.  Would you like to add another number?" << aSpace << yesnos << aSpace;
		reAnswer:
		getline(cin, yesno);
		transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
		if (YesOrNo(yesno) == 1) {
			goto anothaNumba;
		}
		if (YesOrNo(yesno) == 2) {
			goto emailgoto;
		}
		if (YesOrNo(yesno) == 3) {
			cout << "Please say yes or no." << aSpace;
			goto reAnswer;
		}

	}
emailgoto:
	cout << "Please enter an email address for the contact:" << aSpace;
	getline(cin, temp);
	emailAdrs.push_back(temp);
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	if (temp == "skip") {
		cout << "Skipped Email Address." << endl;
		goto cardMakergoto;
	}
	else {
		cout << "Please enter a name for the email address (ex. Personal, Work):" << aSpace;
		getline(cin, tempTwo);
		emailName.push_back(tempTwo);
		tempTwo[0] = toupper(tempTwo[0]);
		cout << tempTwo << aSpace << "email" << aSpace << temp << aSpace << "Registered.  Would you like to add another email?" << aSpace << yesnos << aSpace;
	reAnswere:
		getline(cin, yesno);
		transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
		if (YesOrNo(yesno) == 1) {
			goto emailgoto;
		}
		if (YesOrNo(yesno) == 2) {
			goto cardMakergoto;
		}
		if (YesOrNo(yesno) == 3) {
			cout << "Please say yes or no." << aSpace;
			goto reAnswere;
		}

	}
cardMakergoto:
	cout << endl << "Enter a file name for the contact card:" << aSpace;
	getline(cin, fileNamePromt);
	ofstream fout(fileNamePromt + ".vcf");
	fout << "BEGIN:VCARD" << endl << "VERSION:2.1" << endl << "N:" << lastName << ";" << firstName << ";;;" << endl << "FN:" << firstName << aSpace << lastName << endl;
	while (i < phonenum.size() && i < phoneName.size()) {
		phonenum[i];
		fout << "TEL;" << phoneName[i] << ":" << phonenum[i] << endl;
		i++;
	}
	while (q < emailAdrs.size() && emailName.size()) {
		fout << "EMAIL;" << emailName[q] << ":" << emailAdrs[q] << endl;
		q++;
	}
	fout << endl << "END:VCARD";
	cout << "Success!  The contact card was created in the folder where the program is located.";
	return 0;
}

int YesOrNo(string yesno) {
	transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
	if (yesno == "yes") {
		return 1;
	}
	if (yesno == "no") {
		return 2;
	}
	else {
		return 3;
	}
}