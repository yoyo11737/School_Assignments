#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

stack::~stack()
{
	//cout << "Inside !stack" << endl;
	while (s_top != 0) {
		pop();
	}
}

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

void stack::push(const stack_element & item)
{
	//cout << "Inside push" << endl;
	stack_node * p = new stack_node;

	p->data = item;
	p->next = s_top;
	s_top = p;
}

void stack::print()
{
	//cout << "Inside print" << endl;

	for (stack_node * p = s_top; p != 0; p = p->next) {
		cout << p->data << endl;
	}
}
