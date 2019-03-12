#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool IsOperator(const char);

int main() {
	stack S;
	string postFix;
	int count = 0;
	
	string userInput;

	cout << "What would you like to convert?: ";
	getline(cin, userInput);
	cout << endl << endl;


	for (int i = userInput.length(); i >= 0; i--) {
		if (userInput[i] == ' ') {
			cout << endl << "space" << endl;
			count++;
			continue;
		}
		else if (IsOperator(userInput[i])) {
			if (IsOperator(userInput[i - 1])) {
				
			}
		}
		else if ((int(userInput[i]) >= 33 && int(userInput[i]) <= 41) || (int(userInput[i]) >= 58 && int(userInput[i]) <= 96) || (int(userInput[i]) >= 123 && int(userInput[i]) <= 127)) {
			cout << "\n\nYou have entered a value that cannot be used. Try again . . . \n\n";
		}
		S.push(userInput[i]);
		count++;
		
	}
	
	cout << count - 1 << endl;
	//S.push("hi");
	S.print();

	return 0;
}

bool IsOperator(const char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	else {
		return false;
	}
}
