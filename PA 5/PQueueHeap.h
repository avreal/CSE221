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
	void removeMin() throw(EmptyPriorityQueue) {
		if (T.isEmpty()) throw EmptyPriorityQueue();
		T.removeMin();
	}

	void remove(int* location) throw (EmptyPriorityQueue)
	{
		if (T.isEmpty()) throw EmptyPriorityQueue();
		T.remove(location);
	}

	void decreaseKey(const int* location, int k) 
	{
		if (T.getArray()[*location].getKey() < k)
		{
			T.getArray()[*location].setKey(k);
			T.walkDown(*location);
		}
		else
		{
			T.getArray()[*location].setKey(k);
			Item i(k,T.getArray()[*location].getElem(), T.getArray()[*location].loco);
			T.walkUp(i, *location);
		}
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
