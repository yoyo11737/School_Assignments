/*
Name: Dalton McClain
Course: COP3530
Professor: Dr. Lofton Bullard
Due Date: 1/31/19
Total Points: 25
Assignment #3: Dynamic Array

Description: This program creates a database that the user can add and remove from at will. The database is created using a dynamic array.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include "tlist.h"

using namespace std;

int main() {
	Tlist MyClass;

	string key = " ";
	bool flag = true;
	int userInput = 0;


	do {
		cout << "\nEnter one of the following numbers . . . \n";
		cout << "1) Do you want to see the database?\n";
		cout << "2) Do you want to add something to the database?\n";
		cout << "3) Do you want to remove something from the database?\n";
		cout << "4) Do you want to quit?\n";
		cout << "Your number choice here: ";
		cin >> userInput;
		cout << endl;
		if (userInput > 4 || userInput < 1) {
			cout << "You entered the wrong number . . . ";
		}
		else if (userInput == 4) {
			cout << "\nThe program is now dead :'(\n\n";
			flag = false;
		}
		else if (userInput == 1) {
			MyClass.Display();
		}
		else if (userInput == 2) {
			cout << "What would you like to insert?: ";
			cin >> key;
			cout << endl;
			MyClass.Insert(key);
		}
		else if (userInput == 3) {
			cout << "Please enter what you would like to remove: ";
			cin >> key;
			MyClass.Remove(key);
		}
		else {
			cout << "I don't know what you did... But it was wrong!";
			flag = false;
		}

	} while (flag);



	return 0;
}