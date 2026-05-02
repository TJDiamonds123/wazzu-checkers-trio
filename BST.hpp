#pragma once


#include "Node.hpp"

#include "TransactionNode.hpp"




class BST {
private: 
	Node* mpRoot;//pointer to the root of the BST

	void destroyTree(Node* pTree);// deletes all nodes in the tree
	void insert(Node*& pTree, string data, int units);//insert that works with pointers
	void inOrderTraversal(Node* pTree);



public:
	BST();//constructor
	~BST();//destructor

	void insert(string data, int units);//hides pointer details
	void inOrderTraversal();

	TransactionNode& findSmallest();//reeturns smallest unit
	TransactionNode& findLargest();//returns largest unit


};