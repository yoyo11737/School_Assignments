#pragma once

#include <iostream>
using namespace std;

class Tlist {

public:
	Tlist();
	~Tlist();
	bool Is_Full();
	bool Is_Empty();
	int Search(const string key);
	void Insert(const string &key);
	void Remove(const string &key);
	void Display();

private:
	int count;
	int capacity;
	string * DB;

};