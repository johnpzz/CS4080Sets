#include "Set.h"
#include <iostream>
#include <chrono>
using namespace std;

bool Set::found(int a[], int number, int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		if (a[i] == number) {
			return true;
		}
	}

	return false;
}


void Set::print()
{
	for (int i = 0; i < this->getSize(); i++) {
		cout << *(this->getSetPointer() + i) << " ";
	}
	cout << "\n";


}

int * Set::getSetPointer()
{
	return this->setPointer;
}

int Set::getSize()
{
	return this->size;
}

Set::Set(int size)
{
	this->size = size;
	this->setPointer = new int[size];

	for (int i = 0; i < this->getSize(); i++) {
		*(this->getSetPointer() + i) = -1;
	}
}

Set::Set()
{
	this->size = defaultSize;
	this->setPointer = new int[defaultSize];

	for (int i = 0; i < this->getSize(); i++) {
		*(this->getSetPointer() + i) = -1;
	}
}


Set Set::operator +(Set& otherSet)
{
	auto start = chrono::high_resolution_clock::now();
	Set resultSet(this->getSize() + otherSet.getSize());

	for (int i = 0; i < this->size; i++) {
		*(resultSet.setPointer + i) = *(this->setPointer + i);
	}

	for (int i = 0; i < otherSet.size; i++) {

		if (!found(resultSet.getSetPointer(), *(otherSet.setPointer + i), otherSet.size)) {
			*(resultSet.setPointer + i + this->size) = *(otherSet.setPointer + i);

		}
	}

	cout << "Union Set: ";
	for (int i = 0; i < resultSet.getSize(); i++) {
		if (*(resultSet.getSetPointer() + i) != -1) {
			cout << *(resultSet.getSetPointer() + i) << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << " ms" << endl;

	return resultSet;
}

Set Set::operator &(Set& otherSet)
{
	auto start = chrono::high_resolution_clock::now();
	Set resultSet(fmax(this->size, otherSet.size));

	for (int i = 0; i < this->getSize(); i++) {
		int number = *(this->getSetPointer() + i);

		if (found(otherSet.getSetPointer(), number, otherSet.size)) {
			*(resultSet.getSetPointer() + i) = number;
		}
	}


	cout << "Intersection Set: ";
	for (int i = 0; i < resultSet.getSize(); i++) {
		if (*(resultSet.getSetPointer() + i) != -1) {
			cout << *(resultSet.getSetPointer() + i) << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << " ms" << endl;

	return resultSet;
}

Set Set::operator -(Set& otherSet)
{
	auto start = chrono::high_resolution_clock::now();
	Set resultSet(fmin(this->getSize(), otherSet.size));
	for (int i = 0; i < this->getSize(); i++) {
		int number = *(this->getSetPointer() + i);

		if (!found(otherSet.getSetPointer(), number, otherSet.getSize())) {
			*(resultSet.getSetPointer() + i) = number;
		}

	}

	cout << "Difference Set: ";
	for (int i = 0; i < resultSet.getSize(); i++) {
		if (*(resultSet.getSetPointer() + i) != -1) {
			cout << *(resultSet.getSetPointer() + i) << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << " ms" << endl;

	return resultSet;
}

Set Set::operator*(Set & otherSet)
{
	auto start = chrono::high_resolution_clock::now();
	Set resultSet(this->getSize() + otherSet.getSize());

	for (int i = 0; i < this->getSize(); i++) {
		int number = *(this->getSetPointer() + i);

		if (!found(otherSet.getSetPointer(), number, otherSet.getSize())) {
			*(resultSet.getSetPointer() + i) = number;
		}
	}

	for (int i = 0; i < otherSet.getSize(); i++) {
		int number = *(otherSet.getSetPointer() + i);

		if (!found(this->getSetPointer(), number, this->getSize())) {
			*(resultSet.getSetPointer() + this->getSize()) = number;
		}
	}



	cout << "Symmetric Difference Set: ";
	for (int i = 0; i < resultSet.getSize(); i++) {
		if (*(resultSet.getSetPointer() + i) != -1) {
			cout << *(resultSet.getSetPointer() + i) << " ";
		}
	}

	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << " ms" << endl;

	return resultSet;
}
