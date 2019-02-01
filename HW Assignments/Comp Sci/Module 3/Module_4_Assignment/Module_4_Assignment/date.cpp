/****PROGRAM HEADER*******************************************************
Dalton McClain           Total Points:  25
Due Date:  2/7/19
Course:  C0P3014
Assignment:  Module 4
Professor: Dr. Lofton Bullard
Description: This program allows a user to create, add, and manage dates.
*************************************************************/

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
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
	
	if (m > 12 || m < 1) {
		cout << "Explicit-value constructor has been called" << endl;
		cout << setfill('0') << setw(2) << "Month = " << m << " is incorrect . . . " << endl << endl;
		myMonth = 01;
	}
	else {
		myMonth = m;
	}
	if (d == 29 && m == 2) {
		display();
		cout << "This is a leap year!" << endl;
		myDay = d;
	}
	else if (d > 31 || d < 1) {
		cout << "Explicit-value constructor has been called" << endl;
		cout << setfill('0') << setw(2) << "Day = " << d << " is incorrect . . . " << endl;
		myDay = 01;
		cout << endl;
	}
	else {
		myDay = d;
		cout << endl;
	}
	if (y < 1) {
		cout << "Explicit-value constructor has been called" << endl;
		cout << setfill('0') << setw(4) << "Year = " << y << " is incorrect . . . " << endl << endl;
		myYear = 0001;
	}
	else {
		myYear = y;
	}

}

void Date::display()
{
	cout << fixed << setfill('0') << setw(2) << myMonth << "/" << setw(2) << myDay << "/" << setw(4) << myYear << endl << endl;
}

int Date::getMonth()
{
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
