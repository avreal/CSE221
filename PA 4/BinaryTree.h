/*Arnaldo A Villarreal
CSCE 221-510
03-04-2013
*/

#include <iostream>
#include "BinaryNode.h"

class BinaryTree {
private:
	BinaryNode *root;
	void deleteTree(BinaryNode *root);

public:
	BinaryTree() { root = NULL; }
	BinaryTree(int el) { root = new BinaryNode(el);}
	~BinaryTree() {deleteTree(root); root = NULL;}

	BinaryNode *getRoot() { return root;}
	bool isEmpty() { return root == NULL;}
	int size() { return (root == NULL) ? 0 : root->size(root);}
	int height() { return (root == NULL) ? 0 : root->height(root);}
	void copy(BinaryTree& rhs);
	void merge(int rootItem, BinaryTree& t1, BinaryTree& t2);
	void insert(int value);
	void insertHelper(BinaryNode* node, int value);
	void printBinaryTree(BinaryNode *root);
	int searchCost(BinaryNode *t);
	BinaryNode*	find(int elem,  BinaryNode* r);
<<<<<<< HEAD
	void remove(int rem);
	int printavgSearchCost(BinaryNode *r);
};
=======
	int remove(int rem);
	//BinaryNode* findMin(BinaryNode *t);
	//BinaryNode* removeMin(BinaryNode *t);
	int printavgSearchCost(BinaryNode *r);
};
>>>>>>> First commit PA 5
