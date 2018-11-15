#include "Set.h"
#include <iostream>
#include <chrono>


using namespace std;

void unionSet(int a[], int b[], int sizeOfA, int sizeOfB)
{
	auto start = chrono::high_resolution_clock::now();
	int maxSize = sizeOfA + sizeOfB;
	int *resultSet = new int[maxSize];

	for (int i = 0; i < maxSize; i++) {
		resultSet[i] = -1;
	}

	for (int i = 0; i < sizeOfA; i++) {
		resultSet[i] = a[i];
	}

	for (int i = 0; i < sizeOfB; i++) {
		if (!found(resultSet, b[i], maxSize)) {
			resultSet[i + sizeOfA] = b[i];
		}
	}

	cout << "Union Set: ";
	for (int i = 0; i < maxSize; i++) {
		if (*(resultSet + i) != -1) {
			cout << *(resultSet + i) << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << " ms" << endl;

	delete[maxSize] resultSet;
}

void intersectionSet(int a[], int b[], int sizeOfA, int sizeOfB)
{
	auto start = chrono::high_resolution_clock::now();
	int maxSize = fmax(sizeOfA, sizeOfB);
	int *resultSet = new int[maxSize];

	for (int i = 0; i < maxSize; i++) {
		resultSet[i] = -1;
	}

	for (int i = 0; i < sizeOfA; i++) {
		int number = a[i];
		if (found(b, number, sizeOfB)) {
			resultSet[i] = number;
		}
	}

	cout << "Intersection Set: ";
	for (int i = 0; i < maxSize; i++) {
		if (*(resultSet + i) != -1) {
			cout << *(resultSet + i) << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << " ms" << endl;

	delete[maxSize] resultSet;
}

void differenceSet(int a[], int b[], int sizeOfA, int sizeOfB)
{
	auto start = chrono::high_resolution_clock::now();
	int maxSize = sizeOfA;
	int *resultSet = new int[maxSize];

	for (int i = 0; i < maxSize; i++) {
		resultSet[i] = -1;
	}

	for (int i = 0; i < sizeOfA; i++) {

		if (!found(b, a[i], sizeOfB)) {
			resultSet[i] = a[i];
		}
	}

	cout << "Difference Set: ";
	for (int i = 0; i < maxSize; i++) {
		if (*(resultSet + i) != -1) {
			cout << *(resultSet + i) << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << " ms" << endl;

	delete[maxSize] resultSet;
}

void symmetricDifferenceSet(int a[], int b[], int sizeOfA, int sizeOfB)
{
	auto start = chrono::high_resolution_clock::now();
	int maxSize = sizeOfA + sizeOfB;
	int *resultSet = new int[maxSize];

	for (int i = 0; i < maxSize; i++) {
		resultSet[i] = -1;
	}

	for (int i = 0; i < sizeOfA; i++) {

		if (!found(b, a[i], sizeOfB)) {
			resultSet[i] = a[i];
		}
	}

	for (int i = 0; i < sizeOfB; i++) {
		if (!found(a, b[i], sizeOfA)) {
			resultSet[i + sizeOfA] = b[i];
		}
	}

	cout << "Symmetric Difference Set: ";
	for (int i = 0; i < maxSize; i++) {
		if (*(resultSet + i) != -1) {
			cout << *(resultSet + i) << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << " ms" << endl;

	delete[maxSize] resultSet;

}

bool found(int a[], int number, int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		if (a[i] == number) {
			return true;
		}
	}

	return false;
}
