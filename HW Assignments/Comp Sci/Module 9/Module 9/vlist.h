#ifndef vlist_H
#define vlist_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class vlist {
public:
	vlist(); // Default constructor
	vlist(const vlist &); // Copy constructor
	~vlist(); // Destructor
	bool isEmpty();
	vector<string>::iterator search(const string &);// Returns location of string using dynamic array
	void insert(const string & key); // Add key to dynamic memory
	void remove(const string & key); //Remove key from vector memory
	void Print(); //Print every string in vector
private:
	vector<string>DB;
	int count, size;
};

#endif