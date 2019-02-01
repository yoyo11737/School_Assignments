#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//#include "dynamic_array_driver.h"
using namespace std;


class Tlist {

public:
	Tlist();
	~Tlist();
	bool Is_Full();
	bool Is_Empty();
	int Search(const string key);
	void Insert(const string &key);
	void Remove(const string &key);
	void Display();

private:
	int count;
	int capacity;
	string * DB;

};

Tlist::Tlist()
{
	count = 0;
	capacity = 12;
	DB = new string[capacity];

	cout << "Default Constructor Invoked" << endl;

	string n;
	ifstream in;
	in.open("data.txt");
	if (in.fail()) {
		cout << "Input file did not open correctly" << endl;
	}
	else {
		while (!in.eof()) {
			in >> n;
			Insert(n);
		}
		in.close();
	}
}

Tlist::~Tlist()
{
	cout << "Destructor Invoked" << endl;
	delete[] DB;
	DB = 0;

}

bool Tlist::Is_Full()
{
	cout << "Is_Full Invoked" << endl;
	return count == capacity;
}


bool Tlist::Is_Empty()
{
	cout << "Is_Empty Invoked" << endl;
	return count == 0;
}

int Tlist::Search(const string key)
{
	cout << "Search Invoked" << endl;
	for (int i = 0; i < count; i++) {
		if (DB[i] == key) {
			return i;
		}
	}
	return -1;
}

void Tlist::Insert(const string &key)
{
	cout << "Insert Invoked" << endl;
	if (!Is_Full()) {
		DB[count] = key;
		count++;
	}
}

void Tlist::Remove(const string &key)
{
	cout << "Remove Invoked" << endl;
	int n = Search(key);
	if (n != -1) {
		for (int i = n; i < count - 1; i++) {
			DB[i] = DB[i + 1];
		}
		count--;
	}
}

void Tlist::Display()
{

	for (int i = 0; i < count; i++) {
		cout << "DB[ " << i << " ] = " << DB[i] << endl;
	}
}

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