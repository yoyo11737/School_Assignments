/****SAMPLE PROGRAM HEADER*******************************************************
Dalton McClain           Total Points:  10
Due Date:  8/30/18
Course:  C0P3014
Assignment:  Assignment 1
Professor: Dr. Lofton Bullard
Description: My program calculates the amount of money it costs to make a call, dependent on the amount of relays and the duration of the call.
			 The program takes the users input and prints the calculations to the screen.
			 I added a few functions to make the main function a little less overwhelmed, unnecessary but I felt up to the challenge.
			 I added some graphics to make it more fun for the user to see and to direct the eyes to what I want the user to see.


*************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Initialize functions

//Function for checking if user wants to run another calculation
bool yesOrNo();

//Calculate the tax rate 
double taxRate(int relay);

//Print the output to the screen
void finalMessage(string cell, double relay, double length, double netCost, double tax, double totalCost);

int main() {
	//Variables
	string cell_num = "";
	double relays = 0;
	double call_length = 0;
	double net_cost = 0;
	double call_tax = 0;
	double total_cost = 0;

	//This is to check the users input on the phone number to make sure they enter the correct number of digits
	int cell_check = 0;

	//Greeting Message
	cout << setw(10) << "Welcome to the cost call calculator!\n";
	cout << setw(10) << "Follow the instructions below:\n\n";


	//Main loop
	do {
		//Ask for phone number
		cout << "What is your phone number?: ";
		cin >> cell_num;
		cout << endl << endl;

		//Check the user entered 10 digits
		cell_check = cell_num.length();

		if (cell_check > 10 || cell_check < 10) {//could have dont this with a not, but I like it this way
			cout << "\n\nYou need to put a valid 10 digit phone number!\n\n";
			continue;
		}

		//Ask for relay count, as if the user should know this
		cout << "How many relays were used?: ";
		cin >> relays;
		cout << endl << endl;

		//Ask for the duration of time on the phone
		cout << "How long were you talking for? (minutes): ";
		cin >> call_length;
		cout << endl << endl;
		
		//Calculations
		net_cost = relays / 50 * .40 * call_length;
		call_tax = net_cost * taxRate(relays);
		total_cost = net_cost + call_tax;

		//Output
		finalMessage(cell_num, relays, call_length, net_cost, call_tax, total_cost);

		
	} while (yesOrNo());//I call the yesOrNo function to check if the user wants to do another calculation
						//I kept it out of the main code because why not, when I got to the output I got bored



	return 0;
}


//Function for checking if user wants to run another calculation
bool yesOrNo() {

	string userInput = "";

	//Ask for user input
	cout << "\n\nDo you want to make another calculation? (Y/N): ";
	cin >> userInput;
	cout << endl;

	if (userInput == "Y" || userInput == "y") {
		return true;
	}
	else {
		return false;
	}


}

//Calculate the tax rate 
double taxRate(int relay)
{
	//I return the value straight from the conditional because I didn't want to use more variables

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

//Print the output to the screen
void finalMessage(string cell, double relay, double length, double netCost, double tax, double totalCost)
{
	//Make a box
	cout << "=========================================\n";
	cout << "================ OUTPUT =================" << endl;
	cout << "=========================================\n";
	
	cout << "=  Cell Phone #\t\t" << cell << "\t=" << endl;
	cout << fixed << setprecision(0) << "=  Number of Relays\t" << relay << "\t\t=" << endl;
	cout << fixed << setprecision(0) << "=  Minutes used\t\t" << length << "\t\t=" << endl;
	cout << fixed << setprecision(2) << "=  Net Cost\t\t$" << netCost << "\t\t=" << endl;
	cout << fixed << setprecision(2) << "=  Call Tax\t\t$" << tax << "\t\t=" << endl;
	cout << fixed << setprecision(2) << "=  Total Cost\t\t$" << totalCost << "\t\t=" << endl;

	//Finish box
	cout << "=========================================\n";
	cout << "=========================================\n\n";
}

//I love comments, so fun!
