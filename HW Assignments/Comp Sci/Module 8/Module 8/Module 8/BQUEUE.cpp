#include <iostream>
#include "BQUEUE.h"

using namespace std;

//This function creates the the queue
BQUEUE::BQUEUE()
{
	front = NULL;
}

//This is the destructor, it's job is to remove and delete all the items that are inside of the queue.
BQUEUE::~BQUEUE()
{
	if (front != NULL) {
		while (true) {
			if (front->next == front) {
				delete front;
				front = NULL;
				break;
			}
			bqnode * present = front->next;
			present->next->prev = front;
			front->next = present->next;
			delete present;
		}
	}
}

//This is the copy constructor, it's job is to make a copy of the elements inside of one list and transfer them into another.
BQUEUE::BQUEUE(const BQUEUE & org)
{
	this->front = NULL;
	bqnode * tmp = org.front;
	do {
		this->Enqueue(tmp->time);
		tmp = tmp->next;
	} while (tmp != org.front);
}

//This is the function that adds an item to the queue.
void BQUEUE::Enqueue(int q)
{
	cout << "Enqueuing " << q << endl;

	bqnode * tmp = new bqnode();
	tmp->time = q;

	if (front == NULL) {
		front = tmp;
		front->next = front;
		front->prev = front;
	}
	else {
		bqnode * present = front->prev;
		tmp->prev = present;
		present->next = tmp;
		tmp->next = front;
		front->prev = tmp;
	}
}

//This is the function that removes an item from the queue.
void BQUEUE::Dequeue()
{
	if (front == NULL) {
		cout << "ERROR" << endl;
	}
	else if (front->next == front) {
		cout << front->time << " has been deleted from the queue." << endl;
		delete front;
		front = NULL;
	}
	else {
		bqnode * tmp = front;
		front->prev->next = tmp->next;
		front->next->prev = tmp->prev;
		front = front->next;
		cout << tmp->time << " has been deleted from the queue." << endl;
		delete tmp;
	}
}

//This function prints the items that are in the queue in order.
void BQUEUE::Print()
{
	if (front == NULL) {
		cout << "ERROR" << endl;
	}
	else {
		bqnode *tmp = front;

		do {
			cout << tmp->time << endl;
			tmp = tmp->next;
		} while (tmp != front);
	}
}
