#pragma once

class Set {
private:
	const int defaultSize = 50;
	int* setPointer;
	int size;


public:
	bool found(int a[], int number, int arraySize);
	void print();
	int* getSetPointer();
	int getSize();

	Set(int size);
	Set();

	//union
	Set operator + (Set& otherSet);
	//intersection
	Set operator & (Set& otherSet);
	//difference
	Set operator - (Set& otherSet);
	//symmetric difference
	Set operator * (Set& otherSet);


};

