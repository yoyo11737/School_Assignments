/****PROGRAM HEADER*******************************************************
Dalton McClain           Total Points:  20
Due Date:  11/29/18
Course:  C0P3014
Assignment:  Assignment 11
Professor: Dr. Lofton Bullard
Description: The program uses a dynamic array to add and remove members of a database. The program does this by the user created ADT class. While using operator and function overloading. Copy Constrctr and .h files.
*************************************************************/

#include "call_class.h"

int main()
{
	call_class MyClass;

	//Greeting Message
	cout << setw(10) << "Welcome to the cost call calculator!\n";
	cout << setw(10) << "Follow the instructions below:\n\n";

	string key = " ";
	int size = 5;
	int count = 0;
	int i = 0;
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
			cout << MyClass;
		}
		else if (userInput == 2) {
			MyClass.add();
		}
		else if (userInput == 3) {
			cout << "Please enter the number of the person you would like to remove: ";
			cin >> key;
			MyClass.operator-(key);
		}
		else {
			cout << "I don't know what you did... But it was wrong!";
			flag = false;
		}

	} while (flag);



	return 0;
}



