#pragma once


#include "DataAnalysis.hpp"


#include <sstream>

#include <iostream>

using namespace std;


void DataAnalysis::openFile() {
	mCsvStream.open("data.csv");
}

void DataAnalysis::parseLine(string line, int& units, string& type, string& transaction) {
	stringstream ss(line);
	string temp;
	getline(ss, temp, ',');
	units = stoi(temp);

	getline(ss, type, ',');
	getline(ss, transaction, ',');
}


void DataAnalysis::insertData(int units, string type, string transaction) {
	if (transaction == "Sold") {
		mTreeSold.insert(type, units);
	}
	else {
		mTreePurchased.insert(type, units);
	}
}


void DataAnalysis::loadData() {
	string line;

	while (getline(mCsvStream, line)) {
		int units;
		string type;
		string transaction;

		parseLine(line, units, type, transaction);
		insertData(units, type, transaction);
	}

	cout << "Sold tree\n";
	mTreeSold.inOrderTraversal();
	cout << "Purchased Tree:\n";
	mTreePurchased.inOrderTraversal();


}

void DataAnalysis::displayTrends() {
	cout << "Trends: \n";
	cout << "Most Sold:\n";
	mTreeSold.findLargest().printData();


	cout << "Least Sold:\n";
	mTreeSold.findSmallest().printData();

	cout << "Most Purchased: \n";
	mTreePurchased.findLargest().printData();

	cout << "Least Purchased: \n";
	mTreePurchased.findSmallest().printData();


}

void DataAnalysis::runAnalysis() {
	openFile();
	loadData();
	displayTrends();
}