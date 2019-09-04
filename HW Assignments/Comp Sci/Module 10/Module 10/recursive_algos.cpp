/*
Name: Dalton McClain
Instructor: Dr. Bullard
Date: 4/9/2019
Points: 25

Description: This program has three functions that process strings: 1. palindrome() this function finds if a string is a palindrome using recursion
																	2. printReversel() this function reverses a string by recursion
																	3. printIterReverse() this function reverses a string without recursion

I found this awesome khan academy article going over this subject in detail and it helped me understand it completly!
The link to the article is https://www.khanacademy.org/computing/computer-science/algorithms/recursive-algorithms/a/using-recursion-to-determine-whether-a-word-is-a-palindrome
*/
#include <iostream>
#include <string>

using namespace std;

//This function recursively parses a string and checks the first and last letters of the string and recursively reduces the string until there is either 
//one letter or no letters. If there is 0 or 1 characters in the string then the string is always a palindrome and with that knowledge all we have to do
//is reduce the string to that point.
bool palindrome(string & s) {
	int length = s.length();

	string start = s.substr(0, 1);
	string stop = s.substr(length - 1, 1);

	if (start == stop) {
		s = s.substr(1, length - 2);
		if (s.length() <= 1) return true;
		return palindrome(s);
	}
	else return false;

}

//This function uses recursivity to reverse the order of a string by removing the first character of the string and moving it to the end of the string.
string printReversel(const string & s) {
	int length = s.length();

	if (length <= 1) {
		return s;
	}
	else {
		return printReversel(s.substr(1, s.length())) + s.at(0);
	}

}

//This function works opposite of how printReversel works, it takes the last letter and moves it to the front of the string.
string printIterReverse(string & s) {
	string new_s;
	for (int i = s.length() - 1; i >= 0; i--) {
		new_s += s[i];
		
	}
	return new_s;
}

int main() {
	//This is to test the palindrome function.
	cout << "This is testing palindrome()" << endl;
	string s1 = "madsam";
	string s10 = "madsam";
	string s2 = "463364";
	string s20 = "463364";
	string s3 = "ABLE WAR I ERE I SAW ELBA";
	string s30 = "ABLE WAR I ERE I SAW ELBA";

	if (palindrome(s1)) {
		cout << s10 << " is a palindrome!" << endl;
	}
	else cout << s10 << " is not a palindrome :(" << endl;
	if (palindrome(s2)) {
		cout << s20 << " is a palindrome!" << endl;
	}
	else cout << s20 << " is not a palindrome :(" << endl;
	if (palindrome(s3)) {
		cout << s30 << " is a palindrome!" << endl;
	}
	else cout << s30 << " is not a palindrome :(" << endl;

	//This is to test the recursive reverse string function.
	cout << endl << "This is testing printReversel()" << endl;
	s1 = "madam";
	s2 = "463364";
	s3 = "ABLE WAS I ERE I SAW ELBA";

	cout << printReversel(s1) << endl;
	cout << printReversel(s2) << endl;
	cout << printReversel(s3) << endl;
	
	//This is to test the non recursive reverse string function.
	cout << endl << "This is to test printIterReverse()" << endl;
	s1 = "madam";
	s2 = "463364";
	s3 = "ABLE WAS I ERE I SAW ELBA";

	cout << printIterReverse(s1) << endl;
	cout << printIterReverse(s2) << endl;
	cout << printIterReverse(s3) << endl;

	return 0;
}