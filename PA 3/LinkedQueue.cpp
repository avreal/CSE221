/*Arnaldo A Villarreal
CSCE 221-510
*/
//LinkedQueue.cpp

#include "LinkedQueue.h"

//Constructors

LinkedQueue::LinkedQueue() :ll() {} // constructor
LinkedQueue::~LinkedQueue() {ll.~LinkedList();} // destructor
LinkedQueue::LinkedQueue(const LinkedQueue& queue) {this->ll = LinkedList(queue.ll);} // copy constructor

// assignment operator

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& queue)
{
	ll = queue.ll;
	return *this;
}

// query function
int LinkedQueue::size() const { return ll.size(); }
bool LinkedQueue::isEmpty() const {return ll.isEmpty(); }

// accessor function

string LinkedQueue::first( ) const throw(QueueEmptyException)
{
	if ( isEmpty() ) throw QueueEmptyException();
	return ll.first();
}

// update functions

void LinkedQueue::enqueue(string elem)
{
	ll.insertLast(elem);
}
string LinkedQueue::dequeue( ) throw(QueueEmptyException)
{
	if ( isEmpty() ) throw QueueEmptyException();

	return ll.removeFirst();
}

ostream& operator<<(ostream& out, const LinkedQueue& queue)
{
	LinkedQueue temp = queue;
	if (temp.isEmpty()) out << "Empty\n";
	else
		while(!temp.isEmpty())
		{
			out << temp.dequeue() << ' ';
		}
		return out;
}