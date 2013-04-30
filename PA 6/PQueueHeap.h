/*********************************/
/*Arnaldo A Villarreal
/*CSCE 221 -510
/*Assignment 6, 04-30-2013
/**********************************/
#include "BinaryHeap.h"
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

template<typename Type>
class PQueueHeap {
protected: typedef Item<Type> Item;
		   typedef PQComp<Type> Comp;

private: BinaryHeap<Item, Comp> T;
		 static const int DEF_SIZE = 8;

public: // class PriorityQueue cont.
	class EmptyPriorityQueue {}; //exception class
	PQueueHeap(int size = DEF_SIZE) : T(size) { }
	bool isEmpty() const { return T.isEmpty(); }

	int* min()
	{
		return T.findMin().loco;
	}
	int* insert(const int k, const Type& e)
	{
		int* pos = new int[1];
		T.insert(Item(k, e, pos));
		return pos;
	}
	const Type& minElement() throw(EmptyPriorityQueue) {
		if (T.isEmpty()) throw EmptyPriorityQueue();
		return T.findMin().getElem();
	}
	const int minKey() throw(EmptyPriorityQueue) {
		if (T.isEmpty()) throw EmptyPriorityQueue();
		return T.findMin().getKey();
	}
	int removeMin() throw(EmptyPriorityQueue) {
		if (T.isEmpty()) throw EmptyPriorityQueue();
		int comp = T.removeMin();
		return comp;
	}

	void remove(int* location) throw (EmptyPriorityQueue)
	{
		if (T.isEmpty()) throw EmptyPriorityQueue();
		T.remove(location);
	}

	int decreaseKey(const int* location, int k)
	{
		int comp1 = 0;
		int comp2 = 0;
		if (T.getArray()[*location].getKey() < k)
		{
			T.getArray()[*location].setKey(k);
			comp1 = T.walkDown(*location);
		}
		else
		{
			T.getArray()[*location].setKey(k);
			Item i(k,T.getArray()[*location].getElem(), T.getArray()[*location].loco);
			comp2 = T.walkUp(i, *location);
		}
		//cout << "Key decreased, number of comparisons" << comp1+comp2 << endl;
		int comps = comp1 + comp2;
		return comps;
	}

	int size() {return T.size();}

	void createPQueueHeap(PQueueHeap<string>& pq, string fileName)
	{
		ifstream ist(fileName.c_str());
		int key;
		string elem;
		while(ist>>key>>elem)
		{
			pq.insert(key,elem);
		}
	}

	void printQueue()
	{
		if (T.isEmpty()) cout << "Empty Queue (." << endl;
		for(int i = 0; i < T.size(); i++){
			cout << "value: " << T.getArray()[i].getElem() << " // " << "key: " << T.getArray()[i].getKey() << endl;
		}
	}
};
