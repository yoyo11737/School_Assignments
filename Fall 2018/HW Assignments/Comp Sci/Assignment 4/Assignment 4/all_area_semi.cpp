/***********************************************************
Dalton McClain           Total Points:  10
Due Date:  9/20/18
Course:  C0P3014
Assignment:  Assignment 4
Professor: Dr. Lofton Bullard
Description: My program takes a users inputs for 3 sides of a triangle and calculates the correct semi-permieter and area.

*************************************************************/


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Function prototypes
void compute(double a, double b, double c, double& area, double& semiPerimeter);

int main() {
	double a, b, c, area, semiPerimeter = 0.0;
	bool flag = true;
	int userInput = 0;

	cout << "Welcome to the semiperimeter caluclator!" << endl;
	cout << "Please answer the following questions." << endl;

	do {
		cout << "\nPlease input side a of the triangle: ";
		cin >> a;
		cout << endl;

		cout << "\nPlease input side b of the triangle: ";
		cin >> b;
		cout << endl;

		cout << "\nPlease enter side c of the triangle: ";
		cin >> c;
		cout << endl;

		if (a <= 0 || b <= 0 || c <= 0) {
			cout << "\nYou need to enter a number greater than 0 . . .\n";
			continue;
		}
		else if ((a + b > c) && (b + c > a) && (a + c > b)) {
			compute(a, b, c, area, semiPerimeter);
			
		}
		else {
			cout << "\n\nThe sum of any two sides needs to be greater than the third . . .\n\n";
			cout << "\nWould you like to start over?\n(1) Yes\n(2) No\nAnswer(1 or 2): ";
			cin >> userInput;
			if (userInput == 1) {
				continue;
			}
			else break;
			
		}



		compute(a, b, c, area, semiPerimeter);

		cout << "Side a" << "\tSide b" << "\tSide c" << "\tSemi" << "\tArea\n";
		cout << fixed << setprecision(0) << a << "\t" << b << "\t" << c << "\t" << setprecision(2) << semiPerimeter << "\t" << area << endl;

		cout << "\n\nWould you like to make another calculation?\n(1) Yes\n(2) No\nAnswer(1 or 2): ";
		cin >> userInput;
		cout << endl;

		if (userInput == 1) {
			continue;
		}
		else {
			break;
		}

	} while (flag);



	return 0;
}

void compute(double a, double b, double c, double & area, double & semiPerimeter)
{
	semiPerimeter = (a + b + c) / 2;
	double aMinus = semiPerimeter - a;
	double bMinus = semiPerimeter - b;
	double cMinus = semiPerimeter - c;
	area = sqrt(semiPerimeter * aMinus * bMinus * cMinus);
			
	
	
	/* Robust - strong and healthy; vigorous.
					____            __                     __ 
				   / __ \  ____    / /_   __  __   _____  / /_
				  / /_/ / / __ \  / __ \ / / / /  / ___/ / __/
				 / _, _/ / /_/ / / /_/ // /_/ /  (__  ) / /_  
				/_/ |_|  \____/ /_.___/ \__,_/  /____/  \__/  
                                              
						  ,#####,
						  #_   _#
						  |e` `e|
						  |  u  |
						  \  =  /
						  |\___/|
				 ___ ____/:     :\____ ___
			   .'   `.-===-\   /-===-.`   '.
			  /      .-"""""-.-"""""-.      \
			 /'             =:=             '\
		   .'  ' .:    o   -=:=-   o    :. '  `.
		   (.'   /'. '-.....-'-.....-' .'\   '.)
		   /' ._/   ".     --:--     ."   \_. '\
		  |  .'|      ".  ---:---  ."      |'.  |
		  |  : |       |  ---:---  |       | :  |
		   \ : |       |_____._____|       | : /
		   /   (       |----|------|       )   \ 
		  /... .|      |    |      |      |. ...\
		 |::::/''     /     |       \     ''\::::|
		 '""""       /'    .L_      `\       """"'
					/'-.,__/` `\__..-'\
				   ;      /     \      ;
				   :     /       \     |
				   |    /         \.   |
				   |`../           |  ,/
				   ( _ )           |  _)
				   |   |           |   |
				   |___|           \___|
				   :===|            |==|
					\  /            |__|
					/\/\           /"""`8.__
					|oo|           \__.//___)
					|==|
					\__/*/

}
