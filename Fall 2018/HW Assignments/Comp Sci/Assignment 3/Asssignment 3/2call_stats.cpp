/************************************************************************************************************************

Name: Daniel Leach                     Z#:Z23495991
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 9/13/2018                 Due Time:11:59pm
Total Points: 100
Assignment #: call_stats.cpp

Description: This program reads a text file called "call_data.txt" as user input, then calculates the tax rate, net cost, 
call tax, and total cost, then outputs all the data into a table format. 

*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

class call_record {
	public:
		string cell_num;
		int relays;
		int call_length;
		double net_cost;
		double tax_rate;
		double call_tax;
		double total_cost;
};

void input(ifstream&, call_record&);
void process(call_record&);
void output(const call_record& );



int main() {

	string user_input = "";
	
	
	call_record customer_record;
	do {
		ifstream in;    //declaring an input file stream
		in.open("call_data.txt");

		if (in.fail())
		{
			cout << "Input file did not open correctly" << endl;
		}
		else
		{
			while (!in.eof())
			{
				input(in, customer_record);
				process(customer_record);
				output(customer_record);
			}
		}

		in.close();

		cout << endl;
		cout << "would you like to run the program again (Y or N) " << endl;
		cin >> user_input;

	} while (user_input == "y" || user_input == "Y");
	

	return 0;
}


void input(ifstream& in, call_record& customer_record) {
	
	
	in >> customer_record.cell_num;
	in >> customer_record.relays;
	in >> customer_record.call_length;
}

void output (const call_record& customer_record) {
	
	/*
	cout << endl;
	cout << "****************************************************" << endl;
	cout << "Cell Number: " << customer_record.cell_num << endl;
	cout << "****************************************************" << endl;
	cout << endl;

	cout.setf(ios::fixed);
	cout << setprecision(2) << "Number or relays: " << customer_record.relays << endl;
	cout << setprecision(2) << "Call Length: " << customer_record.call_length << endl;
	cout << setprecision(2) << "Net Cost: " << customer_record.net_cost << endl;
	cout << setprecision(2) << "Tax Rate: " << customer_record.tax_rate << endl;
	cout << setprecision(2) << "Call Tax: " << customer_record.call_tax << endl;
	cout << setprecision(2) << "Total Cost: " << customer_record.total_cost << endl;
	cout << endl;
	*/

	cout.setf(ios::fixed);
	cout << customer_record.cell_num << "\t";
	cout << customer_record.relays << "\t";
	cout << customer_record.call_length << "\t";
	cout << setprecision(2) << customer_record.net_cost << "\t";
	cout << setprecision(2) << customer_record.tax_rate << "\t";
	cout << setprecision(2) << customer_record.call_tax << "\t";
	cout << setprecision(2) << customer_record.total_cost << endl;
}

void process(call_record& customer_record) {

	customer_record.tax_rate = 0;

	if (customer_record.relays >= 0 && customer_record.relays <= 5) {
		customer_record.tax_rate = 0.01;
	}
	else if (customer_record.relays >= 6 && customer_record.relays <= 11) {
		customer_record.tax_rate = 0.03;
	}
	else if (customer_record.relays >= 12 && customer_record.relays <= 20) {
		customer_record.tax_rate = 0.05;
	}
	else if (customer_record.relays >= 21 && customer_record.relays <= 50) {
		customer_record.tax_rate = 0.08;
	}
	else if (customer_record.relays > 50) {
		customer_record.tax_rate = 0.12;
	}



	customer_record.net_cost = customer_record.relays / 50.0 * 0.4 * customer_record.call_length;
	customer_record.call_tax = customer_record.net_cost * customer_record.tax_rate;
	customer_record.total_cost = customer_record.net_cost + customer_record.call_tax;



}