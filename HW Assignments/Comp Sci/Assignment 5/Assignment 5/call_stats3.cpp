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

void Input(ifstream &, call_record &);
void Output(const call_record &);
void Process(call_record &);



int main() {
	//Greeting Message
	cout << setw(10) << "Welcome to the cost call calculator!\n";
	cout << setw(10) << "Follow the instructions below:\n\n";

	//File manipulation
	call_record customer_record;
	ifstream in;

	in.open("call_data.txt");

	if (in.fail()) {
		cout << "Input file did not open correctly" << endl;
	}
	else {
		cout << "Phone Number\tRelays\tCall Length\tNet Cost\tTax Rate\tCall Tax\tTotal Cost" << endl;
		while (!in.eof()) {
			Input(in, customer_record);
			Process(customer_record);
			Output(customer_record);
		}
	}

	in.close();

	return 0;

}

void Input(ifstream & in, call_record & customer_record) {

	in >> customer_record.cell_number;
	in >> customer_record.relays;
	in >> customer_record.call_length;

}

void Process(call_record & customer_record) {
	//Tax rate calculations
	customer_record.tax_rate = 0.0;

	if (customer_record.relays <= 0 || customer_record.relays <= 5) {
		customer_record.tax_rate = .01;
	}
	else if (customer_record.relays <= 6 || customer_record.relays <= 11) {
		customer_record.tax_rate = .03;
	}
	else if (customer_record.relays <= 12 || customer_record.relays <= 20) {
		customer_record.tax_rate = .05;
	}
	else if (customer_record.relays <= 21 || customer_record.relays <= 50) {
		customer_record.tax_rate = .08;
	}
	else if (customer_record.relays > 50) {
		customer_record.tax_rate = .12;
	}

	//Final calculations
	customer_record.net_cost = customer_record.relays / 50 * .40 * customer_record.call_length;
	customer_record.call_tax = customer_record.net_cost * customer_record.tax_rate;
	customer_record.total_cost = customer_record.net_cost + customer_record.call_tax;
}

void Output(const call_record & customer_record) {
	ofstream myFile("weekly_call_info.txt");
	if (myFile.is_open()) {
		
		myFile << customer_record.cell_number << "\t";
		myFile << fixed << setprecision(0) << customer_record.relays << "\t";
		myFile << fixed << setprecision(0) << customer_record.call_length << "\t\t";
		myFile << fixed << setprecision(2) << "$" << customer_record.net_cost << "\t\t";
		myFile << fixed << setprecision(2) << "$" << customer_record.tax_rate << "\t\t";
		myFile << fixed << setprecision(2) << "$" << customer_record.call_tax << "\t\t";
		myFile << fixed << setprecision(2) << "$" << customer_record.total_cost << endl;

		myFile.close();
	}
	else {
		cout << "Error!";
	}
	
	cout << customer_record.cell_number << "\t";
	cout << fixed << setprecision(0) << customer_record.relays << "\t";
	cout << fixed << setprecision(0) << customer_record.call_length << "\t\t";
	cout << fixed << setprecision(2) << "$" << customer_record.net_cost << "\t\t";
	cout << fixed << setprecision(2) << "$" << customer_record.tax_rate << "\t\t";
	cout << fixed << setprecision(2) << "$" << customer_record.call_tax << "\t\t";
	cout << fixed << setprecision(2) << "$" << customer_record.total_cost << endl;
	
}