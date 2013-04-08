#include "PQueueHeap.h"
//#include "PQueueVector.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
	string file;
	PQueueHeap<string> pq;

	cout << "Howdy, enter the name of the file you wish to read from" << endl;
	cin >> file;

	pq.createPQueueHeap(pq, file);

	cout << "Testing for emptiness (0=not empty, 1=empty): " << pq.isEmpty() << endl;
	cout << "Size of PQueue is " << pq.size() << endl;

	cout << "Printing PQueue now..." << endl;
	pq.printQueue();

	cout << "Inserting element now..." << endl;
	int *pqv = pq.insert(20,"hi :3");

	cout << "Printing PQueue again..." << endl;
	pq.printQueue();

	cout << "Changing key of an element..." << endl;
	pq.decreaseKey(pqv,19);

	cout << "Printing PQueue again..." << endl;
	pq.printQueue();

	cout << "Memory address of minimum element " << pq.min() << endl;

	cout << "Removing minimum element..." << endl;
	pq.removeMin();

	cout << "Printing PQueue one last time )" << endl;
	pq.printQueue();

	return 0;
}
