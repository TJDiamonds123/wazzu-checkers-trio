
#include "DataAnalysis.hpp"


#include <sstream>

#include <iostream>

using namespace std;


void DataAnalysis::openFile() {//opens the file csv
	mCsvStream.open("data.csv");
}
//skips the first line becaus eit has usints type and transaction. it also splits them in their own catagories
void DataAnalysis::parseLine(string line, int& units, string& type, string& transaction) {
	stringstream ss(line);
	//extracts units product and transactio  to their own thing
	ss >> units; 
	ss >> type;
	ss >> transaction;
}

//inserts data to BST
void DataAnalysis::insertData(int units, string type, string transaction) {
	if (transaction == "Sold") {//if its sold then put it in sold
		mTreeSold.insert(type, units);
	}
	else {
		mTreePurchased.insert(type, units);
	}
}


void DataAnalysis::loadData() {//reads file and loads BST
	string line;

	while (getline(mCsvStream, line)) {
		//skip empty lines and the header if they have
		if (line == "" || line.find("Units") != string::npos) {
			continue;
		}
		
		
		int units;
		string type;
		string transaction;

		parseLine(line, units, type, transaction);
		insertData(units, type, transaction);
	}
	//display BST
	cout << "Sold tree\n";
	mTreeSold.inOrderTraversal();
	cout << "\nPurchased Tree:\n";
	mTreePurchased.inOrderTraversal();


}

void DataAnalysis::displayTrends() {//display the trends and prints them if they ahve them
	cout << "\nTrends:\n";
	cout << "\nMost Sold:\n";
	mTreeSold.findLargest().printData();


	cout << "\nLeast Sold:\n";
	mTreeSold.findSmallest().printData();

	cout << "\nMost Purchased: \n";
	mTreePurchased.findLargest().printData();

	cout << "\nLeast Purchased: \n";
	mTreePurchased.findSmallest().printData();


}

void DataAnalysis::runAnalysis() {//runs the program
	openFile();
	loadData();
	displayTrends();
}