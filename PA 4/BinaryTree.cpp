/*Arnaldo A Villarreal
CSCE 221-510
03-04-2013
*/

#include <iostream>
#include "BinaryTree.h"

void BinaryTree::copy(BinaryTree& rhs)
{
	if (this != &rhs) {
		deleteTree(root);
		if(rhs.root !=NULL) root = rhs.root->copy();
	}
}

void BinaryTree::merge(int rootItem, BinaryTree& t1, BinaryTree& t2)
{
	if(t1.root == t2.root && t1.root != NULL) {
		std::cerr << "Left_tree == right_tree; "
			<< "merge aborted" << '\n';
		return;
	}

	if ( this != &t1 && this != &t2) deleteTree(root);
	root = new BinaryNode(rootItem, t1.root, t2.root);

	if (this != &t1) t1.root = NULL;
	if (this != &t2) t2.root = NULL;
}

void BinaryTree::deleteTree(BinaryNode *root)
{
	if (root == NULL) return;
	if (root->left != NULL)
		deleteTree(root->left);
	if (root->right != NULL)
		deleteTree(root->right);
	delete root;
}

void BinaryTree::insert(int value)
{
	if(root == NULL)
		root = new BinaryNode(value);
	else
		insertHelper(root, value);
}

void BinaryTree::insertHelper(BinaryNode* node, int value)
{
	if(value < node->element)
	{
		if(node->left == NULL)
			node->left = new BinaryNode(value);
		else
			insertHelper(node->left, value);
	}
	else
	{
		if(node->right == NULL)
			node->right = new BinaryNode(value);
		else
			insertHelper(node->right, value);
	}
}
<<<<<<< HEAD

void BinaryTree::printBinaryTree(BinaryNode *root)
{
	if ( root != NULL ) {
		printBinaryTree( root->left ); 
		std::cout << root->getElem() <<" [" << searchCost(root) << "] ";
		printBinaryTree( root->right ); 
	}
}

int BinaryTree::printavgSearchCost(BinaryNode *root)
{
	int search = 0;
	int avg;
	if ( root != NULL ) {  
		printavgSearchCost( root->left );    
		search+=(root->height(root)+1);
		printavgSearchCost( root->right );
	}

	return search;
}

int BinaryTree::searchCost(BinaryNode *t)
{
	return t->height(t)+1;
}

BinaryNode*  BinaryTree::find(int elem,  BinaryNode* r) {
	if ( elem  ==  r -> getElem()  )		
		return r;
	else if (  elem <  r -> getElem()  ) 
		return find(  elem,  r -> getLeft() );
	else					
		return find(  elem,  r -> getRight()  );
}

void BinaryTree::remove(int rem)
{
	BinaryNode* par= getRoot(); 
	BinaryNode* curr= find(rem,par); 
	if(curr) 
	{
		if(curr->left && curr->right) //2 children case
		{
			BinaryNode* tmp=curr;
			par=curr;
			curr=curr->left;
			while(curr->right)
			{
				par=curr;
				curr=curr->right;
			}
			tmp->element=curr->element;
		}

		//1 or 0 child case
		BinaryNode *tmp=(curr->left ? curr->left : curr->right);

=======

void BinaryTree::printBinaryTree(BinaryNode *root)
{
	if ( root != NULL ) {
		printBinaryTree( root->left ); 
		std::cout << root->getElem() <<" [" << searchCost(root) << "] ";
		printBinaryTree( root->right ); 
	}
}

int BinaryTree::printavgSearchCost(BinaryNode *root)
{
	int search = 0;

	if ( root != NULL ) {  
		printavgSearchCost( root->left );    
		search+=searchCost(root);
		printavgSearchCost( root->right );
	}

	return search;
}

int BinaryTree::searchCost(BinaryNode *t)
{
	return t->height(t)+1;
}

BinaryNode*  BinaryTree::find(int elem,  BinaryNode* r) {
	if ( elem  ==  r -> getElem()  )		
		return r;
	else if (  elem <  r -> getElem()  ) 
		return find(  elem,  r -> getLeft() );
	else					
		return find(  elem,  r -> getRight()  );
}
/*
BinaryNode *BinaryTree::findMin(BinaryNode *t)

{
if (t == NULL)
while (t->left != NULL) t = t->left;
return t;
}

BinaryNode *BinaryTree::removeMin(BinaryNode *t)
{
if (t == NULL)
if (t->left != NULL)
t->left = removeMin(t->left);
else {
BinaryNode *node = t;
t = t->right;
delete node;
}
return t;
}

BinaryNode *BinaryTree::remove(int x, BinaryNode *t){
	
	if (t == NULL)
if (x < t->element)
{t->left = remove(x, t->left);}
else if (x > t->element)
t->right = remove(x, t->right);
else if (t->left != NULL && t->right != NULL) {
// item x is found; t has two children
t->element = findMin(t->right)->element;
t->right = removeMin(t->right);
} else { //t has only one child
BinaryNode *node = t;
t = (t->left != NULL) ? t->left : t->right;
delete node;
}
return t;*/
	
	
	int BinaryTree::remove(int rem){
	BinaryNode* par= getRoot(); 
	BinaryNode* curr= find(rem,par); 
	if(curr) 
	{
		if(curr->left && curr->right) //2 children case
		{
			BinaryNode* tmp=curr;
			par=curr;
			curr=curr->left;
			while(curr->right)
			{
				par=curr;
				curr=curr->right;
			}
			tmp->element=curr->element;
		}

		//1 or 0 child case
		BinaryNode *tmp=(curr->left ? curr->left : curr->right);

>>>>>>> First commit PA 5
		if(!par)
			root=tmp;
		else if(par->element < curr->element)
			par->right=tmp;
		else
			par->left=tmp;
<<<<<<< HEAD
		delete curr;
	}
}
=======
		int searchRem = searchCost(curr);
		std::cout << "Search cost of element removed is: " << searchRem << '\n';
		delete curr;
		return searchRem;
	}
	
}
>>>>>>> First commit PA 5
