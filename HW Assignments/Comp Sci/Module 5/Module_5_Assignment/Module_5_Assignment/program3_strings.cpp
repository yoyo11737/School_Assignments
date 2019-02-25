/*
Name: Dalton McClain
Course: COP3530
Professor: Dr. Lofton Bullard
Due Date: 2/14/19
Total Points: 25
Assignment #5: String Manipulation

Description: This program does two things, 1: It allows a user to check if a string is a palindrome or not.
										   2: It allows users to enter a string and then find and replace certain parts of said string.

*/
#include <iostream>
#include <string>

using namespace std;

bool palindrome(const string & s);
string replace_all(string & original_string, const string & old_substring, const string & new_substring);


int main() {

	string pal = " ";
	string rep_org = " ";
	string rep_old = " ";
	string rep_new = " ";
	bool flag = true;
	int userInput = 0;


	do {
		cout << "\nEnter one of the following numbers . . . \n";
		cout << "1) Do you want to check if a word is a palindrome?\n";
		cout << "2) Do you want replace a certain word with something else?\n";
		cout << "3) Quit\n";
		cout << "Your number choice here: ";
		cin >> userInput;
		cout << endl;
	
		if (userInput == 1) {
			cout << "What string would you like to test?: ";
			cin >> pal;
			cout << endl;
			palindrome(pal);
		}
		else if (userInput == 2) {
			cout << "What is the string you would like replaced?: ";
			cin >> rep_org;
			cout << endl;
			cout << "What are you looking to replace?: ";
			cin >> rep_old;
			cout << endl;
			cout << "What do you want to replace it with?: ";
			cin >> rep_new;
			cout << endl;
			cout << replace_all(rep_org, rep_old, rep_new);
		}
		else if (userInput == 3) {
			break;
		}
		else {
			cout << "I don't know what you did... But it was wrong!";
			flag = false;
		}

	} while (flag);


	return 0;

}

//This function takes a string that the user enters and checks the string to see if it is a palindrome or not.
bool palindrome(const string & s)
{
	
	string s1, s2;

	for (int i = 0; i < s.length(); i++) {
		s1 += s[i];
	}

	for (int j = s.length() - 1; j >= 0; j--) {
		s2 += s[j];
	}

	if (s1 == s2) {
		cout << s << " is a palindrome!" << endl;
		return true;
	}
	else {
		cout << s << " is not a palindrome!" << endl;
		return false;
	}

}

//This function takes three variables that the user enters. The function finds and replaces user defined data.
string replace_all(string & original_string, const string & old_substring, const string & new_substring)
{
	int pos = 0;
	int old_substring_length = old_substring.length();
	//string finalString = original_string;

	while (original_string.find(old_substring) != -1) {
		
		pos = original_string.find(old_substring);

		original_string.replace(pos, old_substring_length, new_substring);

	}
	
	return original_string;
	
}
