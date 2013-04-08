/*Arnaldo A Villarreal
CSCE 221-510
*/
// LinkedStack.cpp

#ifndef LINKEDLISTSTACK_CPP
#define LINKEDLISTSTACK_CPP

#include "LinkedStack.h"

//Constructors

LinkedStack::LinkedStack() :ll() {}// default constructor
LinkedStack::~LinkedStack() {ll.~LinkedList();}// destructor
LinkedStack::LinkedStack(const LinkedStack& stack) {this->ll = LinkedList(stack.ll);}// copy constructor

// assignment operator

LinkedStack& LinkedStack::operator=(LinkedStack& stack)
{
	ll = stack.ll;
	return *this;
}

// query functions
bool LinkedStack::isEmpty() { return ll.isEmpty(); }
int LinkedStack::size() const { return ll.size(); }

// accessor function

string LinkedStack::top() const throw(StackEmptyException)
{
	if (ll.isEmpty())
		throw StackEmptyException();
	return ll.first();
}

// update function

string LinkedStack::pop() throw(StackEmptyException)
{
	if (ll.isEmpty()) throw StackEmptyException();
	return ll.removeFirst();
}

void LinkedStack::push(string elem)
{
	ll.insertFirst(elem);
}

ostream& operator<<(ostream& out, const LinkedStack& stack)
{
	LinkedStack temp = stack;
	if (temp.isEmpty()) out << "Empty\n";
	else{
		while(!temp.isEmpty())
		{
			out << temp.pop() << ' ';
		}}
	return out;
}
#endif