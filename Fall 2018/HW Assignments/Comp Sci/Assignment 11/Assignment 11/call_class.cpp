#include "call_class.h"

call_class::call_class()
{

	call_DB = new call_record[size];

	ifstream in;

	in.open("callstats_data.txt");

	if (in.fail()) {
		cout << "Input file did not open correctly" << endl;
	}
	else {

		while (!in.eof()) {

			for (int i = count; i < size; i++) {
				in >> call_DB[i].firstname;
				in >> call_DB[i].lastname;
				in >> call_DB[i].cell_number;
				in >> call_DB[i].relays;
				in >> call_DB[i].call_length;

				process();

				count++;
			}
			if (is_full()) {
				if (count == size) {
					double_size();
				}

			}
		}
	}

	in.close();

}

call_class::call_class(const call_class & obj) {

	size = obj.size;
	count = obj.count;
	call_DB = new call_record[size];
	
	for (int i = 0; i < count; i++) {
		call_DB[i] = obj.call_DB[i];
	}
}


bool call_class::is_empty()
{
	return count == 0;
}


bool call_class::is_full()
{
	return count == size;
}


int call_class::search(const string key)
{

	for (int i = 0; i < count; i++) {

		if (call_DB[i].cell_number == key) {
			return i;
		}

	}
	return -1;

}


void call_class::add()
{

	cout << "Enter the first name: ";
	cin >> call_DB[count - 1].firstname;
	cout << "Enter the last name: ";
	cin >> call_DB[count - 1].lastname;
	cout << "Enter the cell number: ";
	cin >> call_DB[count - 1].cell_number;
	cout << "Enter the the number of relays: ";
	cin >> call_DB[count - 1].relays;
	cout << "Enter the call length(minutes): ";
	cin >> call_DB[count - 1].call_length;

	if (count - 1 == size) {
		double_size();
	}
	count++;

	if (call_DB[count - 2].relays >= 0 && call_DB[count - 2].relays <= 5) {
		call_DB[count - 2].tax_rate = 0.01;
	}
	else if (call_DB[count - 2].relays >= 6 && call_DB[count - 2].relays <= 11) {
		call_DB[count - 2].tax_rate = 0.03;
	}
	else if (call_DB[count - 2].relays >= 12 && call_DB[count - 2].relays <= 20) {
		call_DB[count - 2].tax_rate = 0.05;
	}
	else if (call_DB[count - 2].relays >= 21 && call_DB[count - 2].relays <= 50) {
		call_DB[count - 2].tax_rate = 0.08;
	}
	else if (call_DB[count - 2].relays > 50) {
		call_DB[count - 2].tax_rate = 0.12;
	}

	call_DB[count - 2].net_cost = call_DB[count - 2].relays / 50.0 * 0.4 * call_DB[count - 2].call_length;
	call_DB[count - 2].call_tax = call_DB[count - 2].net_cost * call_DB[count - 2].tax_rate;
	call_DB[count - 2].total_cost = call_DB[count - 2].net_cost + call_DB[count - 2].call_tax;


}

call_class & call_class::operator-(const string key)
{
	while (search(key) > -1) {
		int loc = search(key);

		if (loc != -1)
		{
			for (int j = loc; j < count - 1; j++)
			{
				call_DB[j] = call_DB[j + 1];

			}
			count--;
		}
	}

	return *this;
}

void call_class::double_size()
{
	size *= 2;
	call_record *temp = new call_record[size];

	for (int i = 0; i<count; i++)
	{
		temp[i] = call_DB[i];
	}

	delete[] call_DB;
	call_DB = temp;
}



void call_class::process()
{


	if (call_DB[count].relays >= 0 && call_DB[count].relays <= 5) {
		call_DB[count].tax_rate = 0.01;
	}
	else if (call_DB[count].relays >= 6 && call_DB[count].relays <= 11) {
		call_DB[count].tax_rate = 0.03;
	}
	else if (call_DB[count].relays >= 12 && call_DB[count].relays <= 20) {
		call_DB[count].tax_rate = 0.05;
	}
	else if (call_DB[count].relays >= 21 && call_DB[count].relays <= 50) {
		call_DB[count].tax_rate = 0.08;
	}
	else if (call_DB[count].relays > 50) {
		call_DB[count].tax_rate = 0.12;
	}

	call_DB[count].net_cost = call_DB[count].relays / 50.0 * 0.4 * call_DB[count].call_length;
	call_DB[count].call_tax = call_DB[count].net_cost * call_DB[count].tax_rate;
	call_DB[count].total_cost = call_DB[count].net_cost + call_DB[count].call_tax;


}



ostream & operator<<(ostream & out, call_class & Org)
{
	for (int i = 0; i < Org.count - 1; i++)
	{
		out << setw(10) << left << Org.call_DB[i].firstname << "\t"
			<< setw(10) << left << Org.call_DB[i].lastname << "\t"
			<< Org.call_DB[i].cell_number << "\t"
			<< fixed << setprecision(0) << Org.call_DB[i].relays << "\t"
			<< fixed << setprecision(0) << Org.call_DB[i].call_length << "\t"
			<< fixed << setprecision(2) << Org.call_DB[i].net_cost << "\t"
			<< fixed << setprecision(2) << Org.call_DB[i].tax_rate << "\t"
			<< fixed << setprecision(2) << Org.call_DB[i].call_tax << "\t"
			<< fixed << setprecision(2) << Org.call_DB[i].total_cost << endl;

	}



	return out;
}


call_class::~call_class()
{

	delete[] call_DB;
	call_DB = 0;

}