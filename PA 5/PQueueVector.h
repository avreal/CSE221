#include "Item.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

struct EmptyPriorityQueue { }; //exceptionclass

template<typename ElemType>
class PQueueVector {
protected: typedef Item<ElemType> Item;
		   typedef PQComp<ElemType> PQComp;

private: vector<Item>V;
		 static const int DEF_SIZE = 8;

public:

	PQueueVector() : V(0) { }
	bool isEmpty() const { return V.empty(); }
	int size() {return V.size();}

	int* insert(const int k, const ElemType& e)
	{
		int* loc = new int[1];
		*loc = V.size();
		V.push_back(Item(k,e,loc));
		return loc;
	}

	int* min() throw(EmptyPriorityQueue)
	{
		if (V.empty()) throw EmptyPriorityQueue();
		int keyIndex = 0;

		for(int i = 0; i < V.size()-1; i++){
			if (V[i].getKey() < V[keyIndex].getKey()) keyIndex = i;
		}
		return V[keyIndex].loco;
	}

	void removeMin() throw(EmptyPriorityQueue)
	{
		int compare = 0;
		cout << "Removing min element..." << endl;
		if (V.empty()) throw EmptyPriorityQueue();
		int index = 0;
		int min = INT_MAX;
		for(int i = 0; i < V.size()-1; i++){
			if(V[i].getKey() < min)
			{
				min = V[i].getKey();
				index = i;
			}
			compare++;
		}
		V.erase(V.begin()+index);

		for(int i = index; i < V.size(); i++)
			*V[i].loco = i;

		cout << compare << " Comparisons made" << endl;
	}

	void decreaseKey(int* location, int k)
	{
		V[*location].setKey(k);
	}

	void remove(int* location) throw (EmptyPriorityQueue)
	{
		if (V.isEmpty()) throw EmptyPriorityQueue();
		V.erase(location);
	}

	void createPQueueVector(PQueueVector<ElemType>& pq, string fileName)
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
		if (V.empty()) cout << "Empty Queue (." << endl;
		for(int i = 0; i < V.size(); i++){
			cout << "value: " << V[i].getElem() << " // " << "key: " << V[i].getKey() << endl;
		}
		cout << endl;
	}
};
