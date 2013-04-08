/*Arnaldo A Villarreal
CSCE 221-510
*/
//LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "RuntimeException.h"

struct ListNode {
	// data members
	string obj;
	ListNode *next;

	// function members
	ListNode(string& e, ListNode *n = NULL) : obj(e), next(n) { }
	const string& getElem() const { return obj; }
	ListNode* getNext() const { return next; }
};

class LinkedList {
private:
	ListNode *head, *tail;

public:
	// user-defined exceptions
	class EmptyLinkedListException : public RuntimeException {
	public:
		EmptyLinkedListException() : RuntimeException("Empty linked list") {}
	};
	class InvalidPointerException : public RuntimeException {
	public:
		InvalidPointerException() : RuntimeException("Attempt to use null pointer") {}
	};

	LinkedList();// default constructor
	~LinkedList(); // destructor	O(n)
	LinkedList(const LinkedList& ll);// copy constructor	O(n)
	LinkedList & operator=(const LinkedList& ll); // assignment operator	O(n)

	// query function
	int size() const;
	bool isEmpty() const;

	// accessor functions
	string first() const throw(EmptyLinkedListException);
	ListNode* getHead() const;
	ListNode* getTail() const;

	// update functions
	void insertFirst(string& newobj);
	string removeFirst() throw(EmptyLinkedListException);
	void insertLast(string& newobj);
	void removeAll(); //O(n)
};

ostream& operator<<(ostream& out, const LinkedList& ll); //overload <<

#endif
