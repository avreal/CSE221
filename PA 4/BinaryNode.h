/*Arnaldo A Villarreal
CSCE 221-510
03-04-2013
*/

//Class BinaryNode

#include <iostream>

class BinaryNode {
private:
	friend class BinaryTree;
	int element;
	BinaryNode *left,*right;

public:
	BinaryNode (int el = 0, BinaryNode *lt = NULL, BinaryNode *rt = NULL) :
		element(el), left(lt), right(rt) {} //constructor

	//fucntions
	BinaryNode *getLeft() {return left;}
	BinaryNode *getRight() {return right;}
	int getElem() {return element;}
	int size(BinaryNode *t);
	int height(BinaryNode *t);
	BinaryNode *copy();
};
