/*Arnaldo A Villarreal
CSCE 221-510
*/
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include "RuntimeException.h"
#include "LinkedList.h"

class LinkedQueue {
private:
	LinkedList ll;

public:
	// user-defined exceptions
	class QueueEmptyException : public RuntimeException {
	public:
		QueueEmptyException() : RuntimeException("Access to an empty queue") {}
	};

	LinkedQueue(); // constructor
	~LinkedQueue();  // destructor
	LinkedQueue(const LinkedQueue& queue); // copy constructor
	LinkedQueue& operator=(const LinkedQueue& queue); // assignment operator

	// query function
	int size() const;
	bool isEmpty() const;
	// accessor function
	string first() const throw(QueueEmptyException);

	// update functions
	void enqueue(string elem);
	string dequeue() throw(QueueEmptyException);
};

ostream& operator<<(ostream& out, const LinkedQueue& queue); // overload <<

#endif
