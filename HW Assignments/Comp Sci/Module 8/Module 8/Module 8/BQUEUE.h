#pragma once
#include <iostream>

using namespace std;

class bqnode {
public:
	int time;
	bqnode *prev, *next;

};

class BQUEUE {

public:
	BQUEUE();
	~BQUEUE();
	BQUEUE(const BQUEUE &);
	void Enqueue(int);
	void Dequeue();
	void Print();
private:
	bqnode * front;

};