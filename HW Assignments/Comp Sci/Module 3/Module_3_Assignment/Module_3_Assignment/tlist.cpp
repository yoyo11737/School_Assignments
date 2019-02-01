#include <iostream>
#include <fstream>
#include <string>
#include "tlist.h"

using namespace std;

Tlist::Tlist()
{
	count = 0;
	capacity = 12;
	DB = new string[capacity];

	cout << "Default Constructor Invoked" << endl;

	string n;
	ifstream in;
	in.open("myData.txt");
	if (in.fail()) {
		cout << "Input file did not open correctly" << endl;
	}
	else {
		while (!in.eof()) {
			in >> n;
			Insert(n);
		}
		in.close();
	}
}

Tlist::~Tlist()
{
	cout << "Destructor Invoked" << endl;
	delete[] DB;
	DB = 0;

}

bool Tlist::Is_Full()
{
	cout << "Is_Full Invoked" << endl;
	return count == capacity;
}


bool Tlist::Is_Empty()
{
	cout << "Is_Empty Invoked" << endl;
	return count == 0;
}

int Tlist::Search(const string key)
{
	cout << "Search Invoked" << endl;
	for (int i = 0; i < count; i++) {
		if (DB[i] == key) {
			return i;
		}
	}
	return -1;
}

void Tlist::Insert(const string &key)
{
	cout << "Insert Invoked" << endl;
	if (!Is_Full()) {
		DB[count] = key;
		count++;
	}
}

void Tlist::Remove(const string &key)
{
	cout << "Remove Invoked" << endl;
	int n = Search(key);
	if (n != -1) {
		for (int i = n; i < count - 1; i++) {
			DB[i] = DB[i + 1];
		}
		count--;
	}
}

void Tlist::Display()
{

	for (int i = 0; i < count; i++) {
		cout << "DB[ " << i << " ] = " << DB[i] << endl;
	}
}