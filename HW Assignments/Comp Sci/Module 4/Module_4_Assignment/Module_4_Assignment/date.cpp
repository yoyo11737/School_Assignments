#include <iostream>
#include <string>
#include <iomanip>
#include "date.h"

using namespace std;

Date::Date()
{
	cout << "Default constructor has been called" << endl;
	myMonth = 01;
	myDay = 01;
	myYear = 0001;
	display();
	cout << endl;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
	if (d == 29 && m == 2) {
		cout << "Explicit-value constructor has been called" << endl;
		myMonth = m;
		myDay = d;
		myYear = y;
		display();
		cout << "This is a leap year!" << endl << endl;
	}
	else if (d > 29 && m == 2) {
		cout << "Explicit-value constructor has been called" << endl;
		
		cout << "Day = " << d << " is incorrect . . . " << endl;
		cout << endl;
	}
	else if ((m > 12 || m < 1) && (d > 31 || d < 1) && (y < 1)) {
		cout << "Explicit-value constructor has been called" << endl;
		
		cout << "Month = " << m << " is incorrect . . . " << endl;

		cout << "Day = " << d << " is incorrect . . . " << endl;

		cout << fixed << setfill('0') << setw(4) << "Year = " << y << " is incorrect . . . " << endl << endl;
	}
	else if (m > 12 || m < 1) {
		cout << "\nExplicit-value constructor has been called" << endl;
		cout << "Month = " << m << " is incorrect . . . " << endl;
		cout << endl;
	}
	else if (y < 1) {
		cout << "Explicit-value constructor has been called" << endl;
		cout << fixed << setfill('0') << setw(4) << "Year = " << y << " is incorrect . . . " << endl << endl;
	}
	else if (d > 31 || d < 1) {
		cout << "\nExplicit-value constructor has been called" << endl;
		cout << "Day = " << d << " is incorrect . . . " << endl;
		cout << endl;
	}
	else { 
		cout << "Explicit-value constructor has been called" << endl;
		myMonth = m;
		myDay = d;
		myYear = y;
		display();
	}

}

void Date::display()
{
	cout << fixed << setfill('0') << setw(2) << myMonth << "/" << setw(2) << myDay << "/" << setw(4) << myYear << endl;
}

int Date::getMonth()
{
	cout << endl;
	return myMonth;
}

int Date::getDay()
{
	return myDay;
}

int Date::getYear()
{
	return myYear;
}

void Date::setMonth(unsigned m)
{
	myMonth = m;
}

void Date::setDay(unsigned d)
{
	myDay = d;
}

void Date::setYear(unsigned y)
{
	myYear = y;
}

ostream & operator<<(ostream & out, const Date & dateObj)
{

	out << dateObj.myMonth << "/" << dateObj.myDay << "/" << dateObj.myYear;
	
	return out;

}
