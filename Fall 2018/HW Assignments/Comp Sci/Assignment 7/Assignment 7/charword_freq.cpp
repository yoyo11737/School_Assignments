#include <iostream>
#include <fstream>

using namespace std;

//Function Prototypes
void everything( char & ch, int & count, int & words, int letterCount[26]);
void output(int letterCount[26]);

const char LETTERS[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

int main() {
	//Variables
	char ch = ' ';
	int count = 0;
	int numWords = 0;
	int letterCount[26] = { 0 };

	//Everything
	everything(ch, count, numWords, letterCount);

	//Output
	output(letterCount);

	return 0;
}

void everything(char & ch, int & count, int & words, int letterCount[26])
{
	ifstream in;
	in.open("mytext.dat");

	int numSpaces = 0;

	if (in.fail()) {
		cout << "Input file did not open correctly" << endl;
	}
	else {
		while (!in.eof()) {
			in.get(ch);

			if (ch == ' ') {
				numSpaces++;
			}
			else if (ch == '.' || ch == ',' || ch == '!' || ch == '(' || ch == ')' || ch == '\'' || ch == '-') {
				continue;
			}
			else if (ch == 'A' || ch == 'a') {
				letterCount[0] += 1;
			}
			else if (ch == 'B' || ch == 'b') {
				letterCount[1] += 1;
			}
			else if (ch == 'C' || ch == 'c') {
				letterCount[2] += 1;
			}
			else if (ch == 'D' || ch == 'd') {
				letterCount[3] += 1;
			}
			else if (ch == 'E' || ch == 'e') {
				letterCount[4] += 1;
			}
			else if (ch == 'F' || ch == 'f') {
				letterCount[5] += 1;
			}
			else if (ch == 'G' || ch == 'g') {
				letterCount[6] += 1;
			}
			else if (ch == 'H' || ch == 'h') {
				letterCount[7] += 1;
			}
			else if (ch == 'I' || ch == 'i') {
				letterCount[8] += 1;
			}
			else if (ch == 'J' || ch == 'j') {
				letterCount[9] += 1;
			}
			else if (ch == 'K' || ch == 'k') {
				letterCount[10] += 1;
			}
			else if (ch == 'L' || ch == 'l') {
				letterCount[11] += 1;
			}
			else if (ch == 'M' || ch == 'm') {
				letterCount[12] += 1;
			}
			else if (ch == 'N' || ch == 'n') {
				letterCount[13] += 1;
			}
			else if (ch == 'O' || ch == 'o') {
				letterCount[14] += 1;
			}
			else if (ch == 'P' || ch == 'p') {
				letterCount[15] += 1;
			}
			else if (ch == 'Q' || ch == 'q') {
				letterCount[16] += 1;
			}
			else if (ch == 'R' || ch == 'r') {
				letterCount[17] += 1;
			}
			else if (ch == 'S' || ch == 's') {
				letterCount[18] += 1;
			}
			else if (ch == 'T' || ch == 't') {
				letterCount[19] += 1;
			}
			else if (ch == 'U' || ch == 'u') {
				letterCount[20] += 1;
			}
			else if (ch == 'V' || ch == 'v') {
				letterCount[21] += 1;
			}
			else if (ch == 'W' || ch == 'w') {
				letterCount[22] += 1;
			}
			else if (ch == 'X' || ch == 'x') {
				letterCount[23] += 1;
			}
			else if (ch == 'Y' || ch == 'y') {
				letterCount[24] += 1;
			}
			else if (ch == 'Z' || ch == 'z') {
				letterCount[25] += 1;
			}
		}
	}
	words = numSpaces + 1;
	cout << endl << "Number of Words: " << words << endl;
}

void output(int letterCount[26])
{

	if (letterCount[0] > 0) {
		cout << "The letter " << LETTERS[0] << " appears " << letterCount[0] << " times" << endl;
	}
	if (letterCount[1] > 0) {
		cout << "The letter " << LETTERS[1] << " appears " << letterCount[1] << " times" << endl;
	}
	if (letterCount[2] > 0) {
		cout << "The letter " << LETTERS[2] << " appears " << letterCount[2] << " times" << endl;
	}
	if (letterCount[3] > 0) {
		cout << "The letter " << LETTERS[3] << " appears " << letterCount[3] << " times" << endl;
	}
	if (letterCount[4] > 0) {
		cout << "The letter " << LETTERS[4] << " appears " << letterCount[4] << " times" << endl;
	}
	if (letterCount[5] > 0) {
		cout << "The letter " << LETTERS[5] << " appears " << letterCount[5] << " times" << endl;
	}
	if (letterCount[6] > 0) {
		cout << "The letter " << LETTERS[6] << " appears " << letterCount[6] << " times" << endl;
	}
	if (letterCount[7] > 0) {
		cout << "The letter " << LETTERS[7] << " appears " << letterCount[7] << " times" << endl;
	}
	if (letterCount[8] > 0) {
		cout << "The letter " << LETTERS[8] << " appears " << letterCount[8] << " times" << endl;
	}
	if (letterCount[9] > 0) {
		cout << "The letter " << LETTERS[9] << " appears " << letterCount[9] << " times" << endl;
	}
	if (letterCount[10] > 0) {
		cout << "The letter " << LETTERS[10] << " appears " << letterCount[10] << " times" << endl;
	}
	if (letterCount[11] > 0) {
		cout << "The letter " << LETTERS[11] << " appears " << letterCount[11] << " times" << endl;
	}
	if (letterCount[12] > 0) {
		cout << "The letter " << LETTERS[12] << " appears " << letterCount[12] << " times" << endl;
	}
	if (letterCount[13] > 0) {
		cout << "The letter " << LETTERS[13] << " appears " << letterCount[13] << " times" << endl;
	}
	if (letterCount[14] > 0) {
		cout << "The letter " << LETTERS[14] << " appears " << letterCount[14] << " times" << endl;
	}
	if (letterCount[15] > 0) {
		cout << "The letter " << LETTERS[15] << " appears " << letterCount[15] << " times" << endl;
	}
	if (letterCount[16] > 0) {
		cout << "The letter " << LETTERS[16] << " appears " << letterCount[16] << " times" << endl;
	}
	if (letterCount[17] > 0) {
		cout << "The letter " << LETTERS[17] << " appears " << letterCount[17] << " times" << endl;
	}
	if (letterCount[18] > 0) {
		cout << "The letter " << LETTERS[18] << " appears " << letterCount[18] << " times" << endl;
	}
	if (letterCount[19] > 0) {
		cout << "The letter " << LETTERS[19] << " appears " << letterCount[19] << " times" << endl;
	}
	if (letterCount[20] > 0) {
		cout << "The letter " << LETTERS[20] << " appears " << letterCount[20] << " times" << endl;
	}
	if (letterCount[21] > 0) {
		cout << "The letter " << LETTERS[21] << " appears " << letterCount[21] << " times" << endl;
	}
	if (letterCount[22] > 0) {
		cout << "The letter " << LETTERS[22] << " appears " << letterCount[22] << " times" << endl;
	}
	if (letterCount[23] > 0) {
		cout << "The letter " << LETTERS[23] << " appears " << letterCount[23] << " times" << endl;
	}
	if (letterCount[24] > 0) {
		cout << "The letter " << LETTERS[24] << " appears " << letterCount[24] << " times" << endl;
	}
	if (letterCount[25] > 0) {
		cout << "The letter " << LETTERS[25] << " appears " << letterCount[25] << " times" << endl;
	}
}