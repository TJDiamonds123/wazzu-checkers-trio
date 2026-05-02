#include "BST.hpp"


#include <iostream>
using namespace std;


BST::BST() {//initalize root to null
	mpRoot = NULL;
}

BST::~BST() {//destructor uses destroyTree to free memory
	destroyTree(mpRoot);
}


void BST::destroyTree(Node* pTree) {//recursion. Deletes nodes in opposite order
	if (pTree != NULL) {
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;//delete node current
	}
}

void BST::insert(string data, int units) {//insert functopn
	insert(mpRoot, data, units);
}

void BST::insert(Node*& pTree, string data, int units) {
	if (pTree == NULL) {//creates new node if empty p;ace is ffound
		pTree = new TransactionNode(data, units);
	}
	else {//
		TransactionNode* temp = (TransactionNode*)pTree;//cast node to trannode to access the unit

		if (units < temp->getUnits()) {//if it is smaller go left otherwise go right
			insert(pTree->getLeft(), data, units);
		}
		else {
			insert(pTree->getRight(), data, units);
		}
	}
}


void BST::inOrderTraversal() {
	inOrderTraversal(mpRoot);
}


void BST::inOrderTraversal(Node* pTree) {
	if (pTree == NULL) {
		return;
	}
	
	//visiits the current left or right tree
		inOrderTraversal(pTree->getLeft());
	pTree->printData();
	inOrderTraversal(pTree->getRight());
}


TransactionNode& BST::findSmallest() {//finds the smallest value
	
	
	Node* temp = mpRoot;

	while (temp->getLeft() != NULL) {
		temp = temp->getLeft();//keep going left
	}
	
	
	return *(TransactionNode*)temp;//returns the reference
}


TransactionNode& BST::findLargest() {//finds the largest valuye
	Node* temp = mpRoot;
	


	while (temp->getRight() != NULL) {
		temp = temp->getRight();//goes right

	}

	return *(TransactionNode*)temp;//retyrns the reference
}
