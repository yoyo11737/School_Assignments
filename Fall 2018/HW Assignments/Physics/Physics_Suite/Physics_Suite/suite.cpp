#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

//Func. Prototypes
void coulombs();
bool userChoice();

int main() {
	//Vars
	int main_menu_choice = 0;

	do {
		cout << "\nWelcome to the physics suite!";
		cout << "What would you like to do?\n1. Coulomb's Law Calculator\n";
		cout << "Your answer?: ";
		cin >> main_menu_choice;
		if (main_menu_choice == 1) {
			coulombs();
		}
		else {
			cout << "\n\nYou need to choose from the main menu list . . .\n\n";
		}


	} while (userChoice());



	return 0;
}

//First choice, coulombs.
void coulombs()
{
	//Vars
	double q1, q2, distance = 0.0;
	double calculation = 0.0;

	const double k = 9 * pow(10, 9);

	char large_number = ' ';
	double base0, power0, base1, power1, distance_base, distance_power = 0.0;

	cout << "\nDo you have any large numbers?(y or n): ";
	cin >> large_number;
	if (large_number == 'y' || large_number == 'Y') {
		cout << "\nWhat is the base of the first large number?: ";
		cin >> base0;
		cout << "\nWhat is the power of the first large number?: ";
		cin >> power0;
		cout << "\nWhat is the base of the second large number?: ";
		cin >> base1;
		cout << "\nWhat is the power of the second large number?: ";
		cin >> power1;
		cout << "\nWhat is the base of the distance?(in meters): ";
		cin >> distance_base;
		cout << "\nWhat is the power of the distance?: ";
		cin >> distance_power;

		q1 = pow(base0, power0);
		q2 = pow(base1, power1);
		distance = pow(distance_base, distance_power);
		calculation = k * ((q1 * q2) / pow(distance, 2));
		
		cout << fixed << setprecision(2) << calculation;

	}
	else if (large_number == 'n' || large_number == 'N') {
		cout << "\nWhat is the first charge?: ";
		cin >> q1;
		cout << "\nWhat is the second charge?: ";
		cin >> q2;
		cout << "\nWhat is the distance between the two charges?(in meters): ";
		cin >> distance;
		cout << endl;

		calculation = k * ((q1 * q2) / pow(distance, 2));
		cout << fixed << setprecision(1) << calculation / 10000;
	}
	else {
		cout << "\n\nYou did not enter the correct input . . .\n\n";
	}
	

}

bool userChoice()
{
	int choice = 0;
	cout << endl << "\nDo you want to return to the main menu or quit?" << endl;
	cout << "Press 1 for menu.\nPress 2 for quit.\nYour answer?: ";
	cin >> choice;
	switch (choice) {
	case 1:
		return true;
		break;
	case 2:
		return false;
		break;
	}
}
