#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

//This function empties the stack.
stack::~stack()
{
	//cout << "Inside !stack" << endl;
	while (s_top != 0) {
		pop();
	}
}

//This function is the copy constructor, which goes unused in this program.
stack::stack(const stack & Org)
{
	//cout << "Inside the Copy Constructor" << endl;

	stack_node * p = Org.s_top;
	(*this).s_top = 0;

	while (p != 0) {
		(*this).push(p->data);
		p = p->next;
	}
}

//This function pushes the the top item on the stack into the pointer that stores the data
stack_element stack::top()
{
	//cout << "Inside top" << endl;

	if (s_top == 0) {
		exit(1);
	}
	else {
		return s_top->data;
	}
}

//This function pops the item that is on top of the stack out of the stack
string stack::pop()
{
	//cout << "Inside pop" << endl;
	stack_node * p;
	if (s_top == 0) return "empty";
	p = s_top;
	string final = p->data;
	s_top = s_top->next;
	delete p;
	return final;
	
}

//This function allows the stack to be populated with the required information
void stack::push(const stack_element & item)
{
	//cout << "Inside push" << endl;
	stack_node * p = new stack_node;

	p->data = item;
	p->next = s_top;
	s_top = p;
}

//This function prints the items of the stack
void stack::print()
{
	//cout << "Inside print" << endl;

	for (stack_node * p = s_top; p != 0; p = p->next) {
		cout << p->data << endl;
	}
}
