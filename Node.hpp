#pragma once


#include <string>

using namespace std;
class Node {
protected: //protected string, left and right pointer
	string mData;
	Node* mpLeft;
	Node* mpRight;





public:
	//constructor

	Node(string data);

		//v destructor
	virtual ~Node();


	//setter for the data and left and right
	void setData(string data);

	void setLeft(Node* left);
	
	void setRight(Node* right);

	//getters for data and left and rigt
	string getData();
	Node*& getLeft();
	Node*& getRight();


	virtual void printData() = 0;



};