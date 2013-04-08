/*Arnaldo A Villarreal
CSCE 221-510
*/
//LinkedList.cpp
#include <iostream>
#include "LinkedList.h"
#include "RuntimeException.h"

using namespace std;

//Constructors

LinkedList::LinkedList() : head(NULL), tail(NULL) {} // default constructor

LinkedList::~LinkedList() {                     //destructor
	ListNode *node;
	while (head != NULL) {
		node = head;
		head = head->next;
		delete node;
	}
	tail = NULL;}

LinkedList::LinkedList(const LinkedList& ll)	//copy con
{
	head = NULL;
	*this = ll;
}

// assignment operator

LinkedList& LinkedList::operator=(const LinkedList& ll)
{
	this->removeAll();
	ListNode *current = ll.head;

	for( ;current!=NULL;current = current->next)
		insertLast(current->obj);
	return *this;
}

// query function

int LinkedList::size() const {
	ListNode *current = getHead();
	int count = 0;
	while(current != NULL) {
		count++;
		current = current->getNext();
	}
	return count;
}

bool LinkedList::isEmpty() const { return head == NULL; }

// accessor function

string LinkedList::first() const throw(EmptyLinkedListException)
{
	if (head == NULL)
		throw EmptyLinkedListException();
	return head->obj;
}

ListNode* LinkedList::getHead() const {return head; }

ListNode* LinkedList::getTail() const {return tail; }

// update functions

void LinkedList::insertFirst(string& newobj)
{
	ListNode *newNode = new ListNode(newobj);

	if (head == NULL) tail = newNode;
	newNode->next = head;
	head = newNode;
}

void LinkedList::insertLast(string& newobj)
{
	ListNode *newNode = new ListNode(newobj);
	if (head == NULL) head = tail = newNode;
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

string LinkedList::removeFirst() throw(EmptyLinkedListException)
{
	if (head == NULL)
		throw EmptyLinkedListException();

	ListNode *node = head;
	head = node->next;

	if (head == NULL) tail = NULL;
	string obj = node->obj;
	delete node;
	return obj;
}

void LinkedList::removeAll()
{
	ListNode *node;
	while (head != NULL) {
		node = head;
		head = head->next;
		delete node;
	}
	tail = NULL;
}

ostream& operator<<(ostream& out, const LinkedList& ll)
{
	if (ll.isEmpty()) out << "Empty\n";
	else{
		ListNode *node = ll.getHead();
		while (node !=NULL) {
			out << node->obj << " ";
			node = node->next;
		}
	}
	return out;
}