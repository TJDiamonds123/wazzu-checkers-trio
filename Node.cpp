#include "Node.hpp"



Node::Node(string data) {//initalize data to pointers
	mData = data;
	mpLeft = NULL;
	mpRight = NULL;

}



Node::~Node() {}//we dont need anythying here


void Node::setData(string data) {//setter for data
	mData = data;
}

void Node::setLeft(Node* left) {//setter for left 
	mpLeft = left;

}

void Node::setRight(Node* right) {//setter for the right
	mpRight = right;
}

string Node::getData() {//getter for data
	return mData;
}

Node*& Node::getLeft() {//getter for left
	return mpLeft;
}

Node*& Node::getRight() {//getter for right
	return mpRight;
}