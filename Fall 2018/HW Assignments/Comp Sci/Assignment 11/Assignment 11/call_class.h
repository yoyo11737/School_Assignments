#ifndef CALL_CLASS_H_
#define CALL_CLASS_H_
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


class call_record
{
public:
	string firstname;
	string lastname;
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};

class call_class
{
public:
	call_class();
	call_class(const call_class &);
	~call_class();
	bool is_empty();
	bool is_full();
	int search(const string key);
	void add();
	call_class & operator-(const string key);
	void double_size();
	void process();
	friend ostream & operator<<(ostream & out_to_screen, call_class & Org);

private:
	int count = 0;
	int size = 5;
	call_record *call_DB;
};


#endif