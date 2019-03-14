#include <iostream>
#include <string>
#include <stdlib.h>
#include "stack.h"

using namespace std;


int main() {
	stack s;
	string postFix, inFix, op1, op2, expr;
	int repeat = 1, error = 0;
	do {
		cout << "What postfix expression would you like to convert to infix?: ";
		getline(cin, postFix);
		cout << endl << endl;


		for (int i = 0; i < postFix.length(); i++) {
			string c = postFix.substr(i, 1);
			if (c == "+" || c == "-" || c == "*" || c == "/") {
				op2 = s.pop();
				if (op2 == "empty") {
					cout << "Too many operators!" << endl;
					error = 1;
					break;
				}
				op1 = s.pop();
				if (op1 == "empty") {
					cout << "Too many operators!" << endl;
					error = 1;
					break;
				}
				expr = "(" + op1 + " " + c + " " + op2 + ")";
				s.push(expr);
			}
			else if (c == " ") {
				continue;
			}
			else {
				s.push(c);
			}
		}
		if (error != 1) {
			inFix = s.pop();
			if (s.pop() == "empty") {
				cout << "\nThe postfix expression was: " << postFix << endl;
				cout << "The infix conversion is: " << inFix << endl << endl;
			}
			else {
				cout << "Too many operators!" << endl;
				while (s.pop() != "empty") s.pop();
			}
		}
		cout << "Do you want to make another conversion?" << endl;
		cout << "1. Yes\n0. No" << endl;
		cout << "Choice: ";
		cin >> repeat;
		cin.ignore();
		system("CLS");

	} while (repeat == 1);

	return 0;
}

