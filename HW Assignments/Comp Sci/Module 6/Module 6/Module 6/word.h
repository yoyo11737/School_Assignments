#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef WORD_H
#define WORD_H

class character {
public:
	char symbol;
	character *next;
};

class WORD {
public:
	bool IsEmpty() { return front == 0; }
	int Length();
	friend ostream & operator<<(ostream & out, const WORD & s) { out << s.here; return out; }
	void operator=(const string & s) {  }
	WORD & operator=(const WORD & w) { WORD k = w; return k; }
	void operator+(const WORD& B) {}
	WORD() { front = back = 0; }
	WORD(const string & s) { here = s; }
	WORD(const WORD & org) {}
	~WORD() {}
	bool IsEqual(const WORD & B) { return true; }
	//void WORD::Remove(WORD & Org) {};
	//void WORD::RemoveALL(WORD & Org) {};

private:
	character * front, * back;
	string here;

};

#endif