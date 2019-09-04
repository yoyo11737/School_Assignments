/*
Name: Dalton McClain
Instructor: Dr. Bullard
Date: 4/1/2019
Points: 25

Description: This program uses a vector and class to create and maintain a list of strings.
*/
#include <iostream>
#include <string>
#include <vector>
#include "vlist.h"

using namespace std;

int main() {
	//Testing default constructor
	cout << "Test1:Testing the default constructor for string\n" << endl;
	vlist String_List;
	
	//Testing the insertion capabilities of our program
	cout << "Test2: Testing Insert \n";
	String_List.insert("Hello");
	String_List.insert("Zebra");
	String_List.insert("Good_Bye");
	String_List.insert("Space");
	String_List.insert("No_One");
	String_List.Print();
	
	//Testing the copy constructor
	cout << endl << "Test 3: Testing copy constructor for string \n" << endl;
	vlist Copied_String = String_List;
	Copied_String.Print();
	
	//Testing the removal capabilities of our program
	cout << endl << "Test 4: Testing Remove for string \n" << endl;
	cout << "Testing Search and IsEmpty also\n";
	String_List.remove("Zebra");
	String_List.remove("Good_Bye");
	String_List.remove("Hello");
	String_List.remove("No_One");
	String_List.remove("Space");
	String_List.remove("Hello");

	//The destrucotr will be called at the termination of the program
	cout<< endl << "When leave main destructor will be called"<<endl;
	return 0;

}