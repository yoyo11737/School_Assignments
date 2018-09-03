/****PROGRAM HEADER*******************************************************
Dalton McClain           Total Points:  20
Due Date:  9/6/18
Course:  C0P3014
Assignment:  Assignment 2
Professor: Dr. Lofton Bullard
Description: My program calculates the amount of money it costs to make a call, dependent on the amount of relays and the duration of the call.
The program takes the users input and prints the calculations to the screen. It has three primary functions:
Input - Takes the users input and saves the input to the address of the variables passed through the function parameters.
Process - Takes the users input values and performs the required calculations on the data.
Output - Prints the calculated data to the screen.

The main function calls each of the primary functions and then after it goes through the functions it asks if the user wants to perform another calculation.
*************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Function prototypes
void Input(string& cell_num, double& relays, double& call_length, double& net_cost, double& call_tax, double& total_cost);
void Process(double& relays, double& call_length, double& net_cost, double& call_tax, double& total_cost);
void Output(string cell_num, double relays, double call_length, double net_cost, double call_tax, double total_cost);

//Main function (No calculations, or printing, just define the variables
int main() {
	//Initial variables
	string cell_num = "";
	double relays, call_length, net_cost, call_tax, total_cost = 0.0;
	

	//Greeting Message
	cout << setw(10) << "Welcome to the cost call calculator!\n";
	cout << setw(10) << "Follow the instructions below:\n\n";

	//Variables for user input on wanting to make another calculation
	string userInput = "";
	bool flag = true;
	bool errorCheck = true;

	//Ask if the user wants to make another calculation
	do {
		//Functions
		Input(cell_num, relays, call_length, net_cost, call_tax, total_cost);
		Process(relays, call_length, net_cost, call_tax, total_cost);
		Output(cell_num, relays, call_length, net_cost, call_tax, total_cost);
		
		//User correction
		do {
			//Ask for user input
			cout << "\n\nDo you want to make another calculation? (Y/N): ";
			cin >> userInput;
			cout << endl;

			if (userInput == "Y" || userInput == "y") {
				flag = true;
				errorCheck = false;
			}
			else if (userInput == "N" || userInput == "n") {
				flag = false;
				errorCheck = false;
			}
			else {
				cout << "\n\nPlease enter either a Y or N . . .\n\n";

				errorCheck = true;
			}
		} while (errorCheck);

	} while (flag);

	return 0;
}

void Input(string & cell_num, double & relays, double & call_length, double & net_cost, double & call_tax, double & total_cost)
{
	//Ask for phone number
	cout << "What is your phone number?: ";
	cin >> cell_num;
	cout << endl << endl;

	//Ask for relay count, as if the user should know this
	cout << "How many relays were used?: ";
	cin >> relays;
	cout << endl << endl;

	//Ask for the duration of time on the phone
	cout << "How long were you talking for? (minutes): ";
	cin >> call_length;
	cout << endl << endl;
}

void Process(double & relays, double & call_length, double & net_cost, double & call_tax, double & total_cost)
{
	//Tax rate calculations
	double tax_rate = 0.0;

	if (relays <= 0 || relays <= 5) {
		tax_rate = .01;
	}
	else if (relays <= 6 || relays <= 11) {
		tax_rate = .03;
	}
	else if (relays <= 12 || relays <= 20) {
		tax_rate = .05;
	}
	else if (relays <= 21 || relays <= 50) {
		tax_rate = .08;
	}
	else if (relays > 50) {
		tax_rate = .12;
	}

	//Final calculations
	net_cost = relays / 50 * .40 * call_length;
	call_tax = net_cost * tax_rate;
	total_cost = net_cost + call_tax;
}

void Output(string cell_num, double relays, double call_length, double net_cost, double call_tax, double total_cost)
{
	//Make a box
	cout << "=========================================\n";
	cout << "================ OUTPUT =================" << endl;
	cout << "=========================================\n";

	cout << "=  Cell Phone #\t\t" << cell_num << "\t=" << endl;
	cout << fixed << setprecision(0) << "=  Number of Relays\t" << relays << "\t\t=" << endl;
	cout << fixed << setprecision(0) << "=  Minutes used\t\t" << call_length << "\t\t=" << endl;
	cout << fixed << setprecision(2) << "=  Net Cost\t\t$" << net_cost << "\t\t=" << endl;
	cout << fixed << setprecision(2) << "=  Call Tax\t\t$" << call_tax << "\t\t=" << endl;
	cout << fixed << setprecision(2) << "=  Total Cost\t\t$" << total_cost << "\t\t=" << endl;

	//Finish box
	cout << "=========================================\n";
	cout << "=========================================\n\n";
}