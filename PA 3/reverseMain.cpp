/*Arnaldo A Villarreal
CSCE 221-510
*/
// reverse a queue

#include <iostream>
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include <fstream>

using namespace std;
// The reverse main function runs in O(n) time
// add your functions here

void readListFromFile(LinkedQueue& ll, string fileName)
{
	try{
		ifstream ist(fileName.c_str());
		string stuff;     
		while(ist>>stuff)
		{
			ll.enqueue(stuff);
		}
	}
	catch(...)
	{
		cout<< "Invalid input\n";
	}
}


int main()
try {

	string fileName;
	cout << "Howdy, please enter the name of the text file to read from." << '\n';
	cin >> fileName;
	LinkedQueue QUEUE;
	LinkedStack STACK;

	readListFromFile(QUEUE,fileName);
	cout << "The input data is as follows: " << QUEUE << ".\n";

	while(QUEUE.isEmpty())
	{
		cout << "empty queue, please enter an input file which contains data" << endl;
		cin >> fileName;
		readListFromFile(QUEUE,fileName);

	}

	while(!QUEUE.isEmpty())
	{
		STACK.push(QUEUE.dequeue());
	}

	while(!STACK.isEmpty())
	{
		QUEUE.enqueue(STACK.pop());
	}
	cout << "This is the queue after operations have been performed: " << QUEUE << ".\n";
	

 } catch(RuntimeException &e) {
   cout << e << endl;
 }
