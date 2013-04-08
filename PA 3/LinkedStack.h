/*Arnaldo A Villarreal
CSCE 221-510
*/
// LinkedListStack.h

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
#include "RuntimeException.h"
#include "LinkedList.h"

class LinkedStack
{
private:
	LinkedList ll;
public:
	// user-defined exceptions
	class StackEmptyException : public RuntimeException {
	public:
		StackEmptyException() : RuntimeException("Stack is empty") {}
	};

	LinkedStack();// default constructor
	~LinkedStack();// destructor
	LinkedStack(const LinkedStack& stack);// copy constructor
	LinkedStack& operator=(LinkedStack& stack); // assignmnet operator

	// query functions
	bool isEmpty();		//O(1)
	int size() const;		//O(1)

	// accessor function
	string top() const throw(StackEmptyException); //O(1)

	// update functions
	void push(string elem);	//O(1)
	string pop() throw(StackEmptyException); //O(1)
};

ostream& operator<<(ostream& out,
					const LinkedStack& stack); //overload <<

#endif
