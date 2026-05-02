#include "TransactionNode.hpp"

//initalize base class and units
TransactionNode::TransactionNode(string data, int units) : Node(data) {
	mUnits = units;
}

TransactionNode::~TransactionNode() {//destructor we dont need anything here

}

void TransactionNode::setUnits(int units) {//setter units
	mUnits = units;
}

int TransactionNode::getUnits() {//getter units
	return mUnits;
}

void TransactionNode::printData() {//prints the data and units
	cout << mData << " " << mUnits << endl;
}