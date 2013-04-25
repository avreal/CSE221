#include "Item.h"
//#include "PQueueVector.h"

using namespace std;

struct EmptyHeap { }; //Exception class

template<typename ElemType, typename Comp>
class BinaryHeap {
private:
	Comp comp; // Comp is a comparator class
	// and comp(a,b) will compare arguments a and b
	int curSize; //number of elements in heap
	ElemType *array; //(dynamic) heap array
	int length; //the length of the array
	static const int DEF_SIZE = 8;

	void getNewArray(int newSize) {
		if (!isEmpty())
		{
			ElemType *temp = array;
			int t_length = length;
			array = new ElemType[newSize];
			length = newSize;
			for (int i = 0; i < t_length; i++)
				array[i] = temp[i];
			delete[] temp;
			return;
		}
		array = new ElemType[newSize];
		length = newSize;
	}

public: // templated class BinaryHeap (cont)
	BinaryHeap(int size = DEF_SIZE) { //constructor
		curSize = 0;
		getNewArray(size);
	}
	ElemType& findMin() throw(EmptyHeap) {
		if ( isEmpty() ) throw EmptyHeap();
		return array[0];
	}
	bool isEmpty( ) const { return curSize == 0; }
	int size() {return curSize;}
	ElemType *getArray(){ return array; }
	void buildHeap();
	void insert(const ElemType& x);
	void removeMin() throw(EmptyHeap);
	void walkDown(int hole);
	void walkUp(const ElemType& x, int hole);
	void checkSize() { if (curSize == length) getNewArray(length*2); }
	void remove(int* location) throw(EmptyHeap);
};

template<typename ElemType, typename Comp>void BinaryHeap<ElemType, Comp>::insert(const ElemType& x) {
	checkSize();

	cout << "Inserting an element..." << endl;
	array[curSize] = x;
	*(array[curSize].loco) = curSize;

	walkUp(x, curSize);
	curSize++;
}

template<typename ElemType, typename Comp>void BinaryHeap<ElemType, Comp>::removeMin() throw(EmptyHeap) {
	array[0] = array[ --curSize ]; //decrease size
	walkDown(0);
}

template<typename ElemType, typename Comp>void BinaryHeap<ElemType, Comp>::walkDown(int hole) {
	int child;
	ElemType key = array[hole];
	int compare = 0;
	for ( ; 2*hole+1 < curSize; hole = child) {
		child = 2*hole+1;
		compare=+2;
		if (child != curSize-1 &&
			comp(array[child], array[child+1]) > 0)
			child++; // right child = 2*hole+2
		if (comp(key, array[child]) > 0)
			array[hole]=array[child];
		else break;
	}
	array[hole] = key;
	cout << "WalkDown operation completed, " << compare << " comparisons made" << endl;
}

template <typename ElemType, typename Comp>void BinaryHeap<ElemType,Comp>::walkUp(const ElemType& x, int hole){
	int compare = 0;
	for ( ; hole > 0 && (compare++,comp(array[(hole-1)/2], x) > 0); hole = (hole-1)/2){
		array[hole] = array[(hole-1)/2];
		*(array[hole].loco) = hole;
	}
	array[hole] = x;
	*(array[hole].loco) = hole;
	cout << "WalkUp operation completed, " << compare << " comparisons made" << endl;
}

template<typename ElemType, typename Comp>void BinaryHeap<ElemType, Comp>::remove(int* location) throw(EmptyHeap)
{
	cout << "Removing an element..." << endl;
	if (isEmpty()) throw EmptyHeap();
	array[*location] = array[--curSize];
	walkDown(*location);
}