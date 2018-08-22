#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Initialize functions
bool yesOrNo();
double taxRate(int relay);

int main() {
	//Variables
	string cell_num = "";
	double relays = 0;
	int call_length = 0;
	double net_cost = 0;
	double call_tax = 0;
	double total_cost = 0;

	//Greeting Message
	cout << setw(10) << "Welcome to the cost call calculator!\n";
	cout << setw(10) << "Follow the instructions below:\n\n";


	//Main loop
	do {
		cout << "What is your phone number?: ";
		cin >> cell_num;
		cout << endl << endl;

		cout << "How many relays were used?: ";
		cin >> relays;
		cout << endl << endl;

		cout << "How long were you talking for? (minutes): ";
		cin >> call_length;
		cout << endl << endl;

		net_cost = relays / 50 * .40 * call_length;
		call_tax = net_cost * taxRate(relays);
		total_cost = net_cost + call_tax;

		//make a box
		cout << "=========================================\n";
		cout << "================ OUTPUT =================" << endl;
		cout << "=========================================\n";

		//Output
		cout << "=  Cell Phone #\t\t" << cell_num << "\t\t=" << endl;
		cout << "=  Number of Relays\t" << relays << "\t\t=" << endl;
		cout << "=  Minutes used\t\t" << call_length << "\t\t=" << endl;
		cout << fixed << setprecision(2) << "=  Net Cost\t\t$" << net_cost << "\t\t=" << endl;
		cout << fixed << setprecision(2) << "=  Call Tax\t\t$" << call_tax << "\t\t=" << endl;
		cout << fixed << setprecision(2) << "=  Total Cost\t\t$" << total_cost << "\t\t=" << endl;

		//Finish box
		cout << "=========================================\n";
		cout << "=========================================\n\n";
	} while (yesOrNo());



	return 0;
}

bool yesOrNo() {

	string userInput = "";

	//Ask for user input
	cout << "\n\nDo you want to make another calculation? (Y/N): ";
	cin >> userInput;
	cout << endl;
	cin.ignore();

	if (userInput == "Y" || userInput == "y") {
		return true;
	}
	else {
		return false;
	}


}

double taxRate(int relay)
{

	if (relay <= 0 || relay <= 5) {
		return .01;
	}
	else if (relay <= 6 || relay <= 11) {
		return .03;
	}
	else if (relay <= 12 || relay <= 20) {
		return .05;
	}
	else if (relay <= 21 || relay <= 50) {
		return .08;
	}
	else if (relay > 50) {
		return .12;
	}
}
