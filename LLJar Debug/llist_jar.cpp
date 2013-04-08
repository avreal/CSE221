#include <cstdlib>
#include <iostream>
#include "llist_jar.h"

using namespace std;

// default constructor
LListJar::LListJar()
{
	ll = std::list<Marble>();
}

// constructor
LListJar::LListJar(int num)
{
	//Check for invalid input
	while(num > 12 || num < 0) {
		cout << "Invalid amount of marbles!" << endl
			<< "Only up to 12 marbles can be created (no duplicates)."
			<< endl << "Enter number of marbles: ";
		cin >> num;
	}

	while(marble_number() < num) {
		Marble temp; // randomly created marble
		add(temp); // add already checks for uniqueness
	}
}

// copy constructor
LListJar::LListJar(const LListJar& jar)
{
	for (int i = 0; i < jar.marble_number(); i++) {
		Marble m1 = jar.get_elem(i+1);
		ll.push_back(m1);
	}
}

// get_elem is useful for copying marbles;
// another possibility is to use a stack (less efficient)
const Marble& LListJar::get_elem(int i) const
{
	list<Marble>::const_iterator it = ll.begin(); //-- stuff
	advance(it,i-1);
	return *it;
}

void LListJar::add(const Marble& m)
{
	if(!is_in_jar(m)) {  // is_in_jar checks for uniqeness
		ll.push_back(m);
	}
}

bool LListJar::is_in_jar(const Marble& m) const
{
	list<Marble>:: const_iterator it = ll.begin(); //-- causes break, VS debugger says that a list is not decrementable
	while(it != ll.end()) {
		if(*it == m) {
			return true;
		}
		advance(it,1);
	}
	return false;
}

void LListJar::remove(const Marble& m)
{
	list<Marble>::iterator it;

	for (it = ll.begin(); it != ll.end(); ++it) {
		if (*it == m) {
			ll.erase(it); // make yourself familiar with the functions of
			// list class in STL
			break;
		}
	}
}

Marble LListJar::remove_any()
{
	if (ll.empty()) throw Empty_jar();

	int rem = rand() % (ll.size()-1);
	list<Marble>::iterator it = ll.begin();
	advance(it, rem);
	Marble temp = *it;
	ll.erase(it);
	return temp;
}

void LListJar::clear()
{
	list<Marble>::iterator it;
	ll.clear();
}

int LListJar::marble_number() const
{
	return ll.size();
}

int LListJar::marble_nsize(Marble::Size s) const
{
	int num = 0;

	list<Marble> temp = ll;
	int size1 = temp.size();
	for (int i = 0; i < size1; i++) {
		if(temp.front().get_size() == s)
			num++;
		temp.pop_front();
	}
	return num;
}

int LListJar::marble_ncolor(Marble::Color c) const
{
	int num = 0;

	list<Marble> temp = ll;
	int size1 = temp.size();

	for(int i = 0; i < size1; i++){
		if(temp.front().get_color() == c)
			num++;
		temp.pop_front();
	}
	return num;
}

bool LListJar::is_empty() const
{
	return ll.empty();
}

void LListJar::merge(const Jar& jar1, const Jar& jar2)
{
	clear();

	difference(jar1, jar2);

	for (int i = 0; i < jar2.marble_number(); i++) {
		add (jar2.get_elem(i+1));
	}
}

void LListJar::intersection(const Jar& jar1, const Jar& jar2)
{
	clear();

	for(int i = 0; i < jar1.marble_number(); i++) {
		for (int j = 0; j < jar2.marble_number(); j++) {
			if (jar1.get_elem(i+1) == jar2.get_elem(j+1)) {
				add(jar2.get_elem(j+1));
			}
		}
	}
}

void LListJar::difference(const Jar& jar1, const Jar& jar2)
{
	clear();

	bool found = false;
	for(int i = 0; i < jar1.marble_number(); i++) {
		for(int j = 0; j < jar2.marble_number(); j++) {
			if(jar1.get_elem(i+1) == jar2.get_elem(j+1)) {
				found = true;
			}
		}
		if(!found) {
			add(jar1.get_elem(i+1));
		}
		found = false;
	}

	//adds remaining of jar 2
	for (int i = 0; i < jar2.marble_number(); i++) {
		for (int j = 0; j < jar1.marble_number(); j++) {
			if(jar2.get_elem(i+1) == jar1.get_elem(j+1))
			{
				found = true;
				break;
			}
		}
		if (!found) {
			add(jar2.get_elem(i+1));
		}
	}
}