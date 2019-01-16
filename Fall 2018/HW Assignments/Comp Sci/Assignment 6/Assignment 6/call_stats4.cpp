/*
Name: Dalton McClain
Course: COP3014
Professor: Dr. Lofton Bullard
Due Date: 10/4/18
Total Points: 20

Description: This program uses arrays to store the information from an input file and then prints it to an output file.

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class call_record {
public:
	string cell_number;
	double relays;
	double call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};

void Input(call_record call_DB[], int & count);
void Process(call_record call_DB[], int & count);
void Output(call_record call_DB[], int & count);

const int SIZE = 200;



int main() {
	//Greeting Message
	cout << setw(10) << "Welcome to the cost call calculator!\n";
	cout << setw(10) << "\nYour file has been generated!\n\n";

	//File manipulation
	call_record call_DB[SIZE];
	int count = 0;

	Input(call_DB, count);
	Process(call_DB, count);
	Output(call_DB, count);

	return 0;

}

void Input(call_record call_DB[], int & count) {
	ifstream in;
	in.open("call_data.txt");
	count = 0;

	if (in.fail()) {
		cout << "Input file did not open correctly" << endl;
	}
	else {
		while (!in.eof()) {
			in >> call_DB[count].cell_number;
			in >> call_DB[count].relays;
			in >> call_DB[count].call_length;
			count++;
		}
	}

	in.close();
}

void Process(call_record call_DB[], int & count) {
	for (int i = 0; i < count; i++) {
		//Tax rate
		if (call_DB[i].relays <= 0 || call_DB[i].relays <= 5) {
			call_DB[i].tax_rate = .01;
		}
		else if (call_DB[i].relays <= 6 || call_DB[i].relays <= 11) {
			call_DB[i].tax_rate = .03;
		}
		else if (call_DB[i].relays <= 12 || call_DB[i].relays <= 20) {
			call_DB[i].tax_rate = .05;
		}
		else if (call_DB[i].relays <= 21 || call_DB[i].relays <= 50) {
			call_DB[i].tax_rate = .08;
		}
		else if (call_DB[i].relays > 50) {
			call_DB[i].tax_rate = .12;
		}
		
		call_DB[i].net_cost = call_DB[i].relays / 50 * .40 * call_DB[i].call_length;
		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
	}

}

void Output(call_record call_DB[], int & count) {
	ofstream myFile;
	myFile.open("weekly6_call_info.txt");

	if (myFile.fail()) {
		cout << "Input file did not open correctly" << endl;
	}
	else {

		for (int i = 0; i < count; i++) {
			myFile << call_DB[i].cell_number << "\t";
			myFile << fixed << setprecision(0) << call_DB[i].relays << "\t";
			myFile << fixed << setprecision(0) << call_DB[i].call_length << "\t\t";
			myFile << fixed << setprecision(2) << call_DB[i].net_cost << "\t\t";
			myFile << fixed << setprecision(2) << call_DB[i].tax_rate << "\t\t";
			myFile << fixed << setprecision(2) << call_DB[i].call_tax << "\t\t";
			myFile << fixed << setprecision(2) << call_DB[i].total_cost << endl;
		}

	}


	myFile.close();
}