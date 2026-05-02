#pragma once



#include "Node.hpp"
#include <iostream>
using namespace std;



class TransactionNode : public Node {


private:
	int mUnits;//# of units 

public:
	TransactionNode(string data, int units);//constructor
	~TransactionNode();//destructor

	void setUnits(int units);//sttters
	int getUnits();//getters

	void printData();//prints the data and the units associated with it




};