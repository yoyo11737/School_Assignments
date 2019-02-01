#include <iostream>
#include <string>
#include "date.h"

using namespace std;

int main() {
	Date myDate;
	Date yourDate(12, 31, 1957);
	Date test1Date(15, 1, 1962);
	Date test2Date(2, 29, 1956);
	Date test3Date(2, 30, 1956);
	Date test4Date(12, 31, 0000);
	Date test5Date(80, 40, 0000);

	yourDate.display();
	cout << yourDate.getMonth() << endl;
	cout << yourDate.getDay() << endl;
	cout << yourDate.getYear() << endl;
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout << "myDate: " << myDate << " test2Date: " << test2Date << " yourDate: " << yourDate << endl;

	return 0;
}