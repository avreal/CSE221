# Makefile

all: reverse
test_all: linkedlist linkedstack linkedqueue reverse

linkedlist: LinkedListMain.cpp LinkedList.cpp 
	g++ -Wall -g -o linkedlist LinkedList.cpp LinkedListMain.cpp

linkedstack: LinkedList.cpp LinkedStack.cpp LinkedStackMain.cpp
	g++ -Wall -g -o linkedstack LinkedList.cpp LinkedStack.cpp \
	     LinkedStackMain.cpp

linkedqueue: LinkedList.cpp LinkedQueue.cpp LinkedQueueMain.cpp
	g++ -Wall -g -o linkedqueue LinkedList.cpp  LinkedQueue.cpp \
	     LinkedQueueMain.cpp

reverse: LinkedList.cpp LinkedStack.cpp LinkedQueue.cpp reverseMain.cpp
	g++ -Wall -g -o reverse LinkedList.cpp  LinkedStack.cpp \
	     LinkedQueue.cpp reverseMain.cpp

.PHONY: clean

clean:
	/bin/rm -f *.o linkedlist linkedstack linkedqueue reverse
