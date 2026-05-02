#pragma once


#include "BST.hpp"

#include <fstream>
#include <string>


using namespace std;

class DataAnalysis {
private:
	BST mTreeSold;//bst for sold
	BST mTreePurchased;//bst for purchased
	ifstream mCsvStream;//file stream

	void openFile();
	void parseLine(string line, int& units, string& type, string& transaction);
	void insertData(int units, string type, string transaction);
	void loadData();
	void displayTrends();

public:
	void runAnalysis();//run program




};