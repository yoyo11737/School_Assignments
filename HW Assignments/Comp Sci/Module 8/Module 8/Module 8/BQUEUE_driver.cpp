/*
Dalton McClain
COP3530
Dr. Bullard
Points: 25
3/23/19
Description: This program implements a doubly linked list queue to add and remove items from the list.
*/

#include <iostream>
#include "BQUEUE.h"

using namespace std;

//This driver is provided to test the queue.
int main() {
	BQUEUE k;
	k.Enqueue(60);
	k.Print();
	k.Enqueue(20);
	k.Enqueue(30);
	k.Print();
	k.Enqueue(10);
	k.Print();
	k.Enqueue(50);
	k.Enqueue(40);
	k.Print();

	BQUEUE j = k;

	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();


	return 0;
}