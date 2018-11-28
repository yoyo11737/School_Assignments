/****PROGRAM HEADER*******************************************************
Dalton McClain           Total Points:  10
Due Date:  10/25/18
Course:  C0P3014
Assignment:  Assignment 9
Professor: Dr. Lofton Bullard
Description: The program uses a dynamic array to add and remove members of a database. The program does this by the user created ADT class.
*************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


class call_record
{
public:
	string firstname;
	string lastname;
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};

class call_class
{
public:
	call_class();
	~call_class();
	bool is_empty();
	bool is_full();
	int search(const string key);
	void add();
	void remove(const string key);
	void double_size();
	void process();
	void print();
private:
	int count = 0;
	int size = 5;
	call_record *call_DB;
};





call_class::call_class()
{
	call_DB = new call_record[size];

	ifstream in;

	in.open("callstats_data.txt");

	if (in.fail()) {
		cout << "Input file did not open correctly" << endl;
	}
	else {

		while (!in.eof()) {

			for (int i = count; i < size; i++) {
				in >> call_DB[i].firstname;
				in >> call_DB[i].lastname;
				in >> call_DB[i].cell_number;
				in >> call_DB[i].relays;
				in >> call_DB[i].call_length;

				process();

				count++;
			}
			if (is_full()) {
				if (count == size) {
					double_size();
				}

			}
		}
	}

	in.close();
}

bool call_class::is_empty()
{
	return count == 0;
}


bool call_class::is_full()
{
	return count == size;
}


int call_class::search(const string key)
{
	
	for (int i = 0; i < count; i++) {

		if (call_DB[i].cell_number == key) {
			return i;
		}

	}
	return -1;

}


void call_class::add()
{
	cout << "Enter the first name: ";
	cin >> call_DB[count - 1].firstname;
	cout << "Enter the last name: ";
	cin >> call_DB[count - 1].lastname;
	cout << "Enter the cell number: ";
	cin >> call_DB[count - 1].cell_number;
	cout << "Enter the the number of relays: ";
	cin >> call_DB[count - 1].relays;
	cout << "Enter the call length(minutes): ";
	cin >> call_DB[count - 1].call_length;

	if (count - 1 == size) {
		double_size();
	}
	count++;

	if (call_DB[count - 2].relays >= 0 && call_DB[count - 2].relays <= 5) {
		call_DB[count - 2].tax_rate = 0.01;
	}
	else if (call_DB[count - 2].relays >= 6 && call_DB[count - 2].relays <= 11) {
		call_DB[count - 2].tax_rate = 0.03;
	}
	else if (call_DB[count - 2].relays >= 12 && call_DB[count - 2].relays <= 20) {
		call_DB[count - 2].tax_rate = 0.05;
	}
	else if (call_DB[count - 2].relays >= 21 && call_DB[count - 2].relays <= 50) {
		call_DB[count - 2].tax_rate = 0.08;
	}
	else if (call_DB[count - 2].relays > 50) {
		call_DB[count - 2].tax_rate = 0.12;
	}

	call_DB[count - 2].net_cost = call_DB[count - 2].relays / 50.0 * 0.4 * call_DB[count - 2].call_length;
	call_DB[count - 2].call_tax = call_DB[count - 2].net_cost * call_DB[count - 2].tax_rate;
	call_DB[count - 2].total_cost = call_DB[count - 2].net_cost + call_DB[count - 2].call_tax;




}


void call_class::remove(const string key)
{

	int location = search(key);

	if (location != -1) {

		for (int j = location; j < count - 1; j++) {
			call_DB[j] = call_DB[j + 1];
		}
		count--;

	}


}


void call_class::double_size()
{
	size *= 2;
	call_record *temp = new call_record[size];

	for (int i = 0; i<count; i++)
	{
		temp[i] = call_DB[i];
	}

	delete[] call_DB;
	call_DB = temp;
}



void call_class::process()
{

	if (call_DB[count].relays >= 0 && call_DB[count].relays <= 5) {
		call_DB[count].tax_rate = 0.01;
	}
	else if (call_DB[count].relays >= 6 && call_DB[count].relays <= 11) {
		call_DB[count].tax_rate = 0.03;
	}
	else if (call_DB[count].relays >= 12 && call_DB[count].relays <= 20) {
		call_DB[count].tax_rate = 0.05;
	}
	else if (call_DB[count].relays >= 21 && call_DB[count].relays <= 50) {
		call_DB[count].tax_rate = 0.08;
	}
	else if (call_DB[count].relays > 50) {
		call_DB[count].tax_rate = 0.12;
	}

	call_DB[count].net_cost = call_DB[count].relays / 50.0 * 0.4 * call_DB[count].call_length;
	call_DB[count].call_tax = call_DB[count].net_cost * call_DB[count].tax_rate;
	call_DB[count].total_cost = call_DB[count].net_cost + call_DB[count].call_tax;


}



void call_class::print()
{
	
	cout << setw(10) << right << "First Name\tLast Name\tNumber\t\tRelays\tLength\tCost\tRate\tTax\tCost" << endl << endl;
	for (int i = 0; i < count - 1; i++) {
		cout << setw(10) << left << call_DB[i].firstname << "\t";
		cout << setw(10) << left << call_DB[i].lastname << "\t";
		cout << call_DB[i].cell_number << "\t";
		cout << fixed << setprecision(0) << call_DB[i].relays << "\t";
		cout << fixed << setprecision(0) << call_DB[i].call_length << "\t";
		cout << fixed << setprecision(2) << call_DB[i].net_cost << "\t";
		cout << fixed << setprecision(2) << call_DB[i].tax_rate << "\t";
		cout << fixed << setprecision(2) << call_DB[i].call_tax << "\t";
		cout << fixed << setprecision(2) << call_DB[i].total_cost << endl;
	}
	
}

call_class::~call_class()
{

	delete[] call_DB;
	call_DB = 0;

}


//driver to test the functionality of your class.
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
			MyClass.print();
		}
		else if (userInput == 2) {
			MyClass.add();
		}
		else if (userInput == 3) {
			cout << "Please enter the number of the person you would like to remove: ";
			cin >> key;
			MyClass.remove(key);
		}
		else {
			cout << "I don't know what you did... But it was wrong!";
			flag = false;
		}

	} while (flag);



	return 0;
}
