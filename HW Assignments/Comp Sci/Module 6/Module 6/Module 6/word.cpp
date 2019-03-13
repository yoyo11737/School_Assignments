#include <iostream>
#include <string>
#include "word.h"

using namespace std;

int WORD::Length() {

	string s;

	if (front == 0) {
		return 0;
	}
	else {
		character *p = front;
		int count = 0;
		while (p != 0) {
			count++;
			p = p->next;
		}
		return count;
	}

}

