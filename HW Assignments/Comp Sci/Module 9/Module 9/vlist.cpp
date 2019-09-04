#include <iostream>
#include <string>
#include <vector>
#include "vlist.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: Constructor has not been invoked.
//Postcondition: count=0, vector size is 9.
//Description: Constructs an instance of a vlist object.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist()
{
	count = 0;
	size = 9;
	cout << "Default constructor invoked." << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(const vlist & list)
{
	cout << "Copy constructor invoked." << endl;

	for (int i = 0; i < count; i++) {
		DB.push_back(list.DB.at(i));
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~vlist
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
vlist::~vlist()
{
	cout << "Destructor invoked." << endl;

	DB.empty();
}

//This function is called and returns a boolean value of whether the the vecotr is empty or not
bool vlist::isEmpty()
{
	cout << "isEmpty invoked." << endl;

	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

//This function iterates through each element of the vector to find a specific item.
vector<string>::iterator vlist::search(const string & key)
{
	cout << "Search invoked." << endl;

	if (!isEmpty()) {
		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++) {
			if (key == *i) {
				cout << "Found" << endl;
				return i;
			}
		}
	}

	cout << "Absent" << endl;
	return DB.end();
}

//This function is called when you need to insert a string into the vector field.
void vlist::insert(const string & key)
{
	if (isEmpty()) {
		DB.push_back(key);
		count++;
		return;
	}
	else if (key <= *DB.begin()) {
		DB.insert(DB.begin(), key);
		count++;
		return;
	}
	else {
		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++) {
			if (key <= *i) {
				DB.insert(i, key);
				count++;
				return;
			}
		}
		count++;
		DB.insert(DB.end(), key);
	}
}

//This function is called wjhen you want to remove a string from the vector field, it utilizes the search function to find the specific item.
void vlist::remove(const string & key)
{
	cout << "Remove Invoked" << endl;
	if (isEmpty()) {
		cout << "Empty Vector!" << endl;
		return;
	}
	else if (search(key) != DB.end()) {
		DB.erase(search(key));
		count--;
		cout << key << " has been removed." << endl;
		return;
	}
	else if (key == *DB.end()) {
		DB.erase(DB.end());
		count--;
		cout << key << " has been removed." << endl;
		return;
	}
	else {
		cout << "Entry not found!" << endl;
	}
}

//This function prints the contents of the vector to the console.
void vlist::Print()
{
	if (isEmpty()) {
		cout << "The vector is empty!" << endl;
	}
	else {
		cout << endl << "The vectors contents are:" << endl;
		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++) {
			cout << *i << endl;
		}
	}
}
