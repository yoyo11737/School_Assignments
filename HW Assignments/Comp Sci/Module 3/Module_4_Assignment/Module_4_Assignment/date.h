#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date {

public:
	Date();
	Date(unsigned m, unsigned d, unsigned y);
	void display();
	int getMonth();
	int getDay();
	int getYear();
	void setMonth(unsigned m);
	void setDay(unsigned d);
	void setYear(unsigned y);

	friend ostream & operator<<(ostream & out, const Date & dateObj);

private:
	int myMonth, myDay, myYear;

};

#endif
