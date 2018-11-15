#include <iostream>
#include <algorithm>
#include "Set.h"
#include <chrono>

using namespace std;

void unionSet(int a[], int b[], int sizeOfA, int sizeOfB)
{
	auto start = chrono::high_resolution_clock::now();

	int resultSet[500];
	for (int i = 0; i < sizeof(resultSet) / 4; i++) {
		resultSet[i] = -1;
	}


	for (int i = 0; i < sizeOfA; i++) {
		if (!found(resultSet, a[i], sizeof(resultSet)/4))
		resultSet[i] = a[i];

	}

	for (int i = 0; i < sizeOfB; i++) {
		if (!found(resultSet, b[i], sizeof(resultSet) / 4))
			resultSet[i + sizeOfA] = b[i];
	}

	sort(begin(resultSet), end(resultSet));
	cout << "Union Set: ";

	for (int i = 0; i < sizeof(resultSet)/4; i++) {
		if (resultSet[i] != -1) {
			cout << resultSet[i] << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << "ms" << endl;


}

void intersectionSet(int a[], int b[], int sizeOfA, int sizeOfB)
{
	auto start = chrono::high_resolution_clock::now();
	int resultSet[500];

	for (int num = 0; num < sizeof(resultSet) / 4; num++) {
		resultSet[num] = -1;
	}


	for (int i = 0; i < sizeOfA; i++) {
		int number = a[i];

		for (int j = 0; j < sizeOfB; j++) {
			if (b[j] == number) {
				resultSet[i] = number;
			}
		}

	}

	sort(begin(resultSet), end(resultSet));
	cout << "Intersection Set: ";

	for (int i = 0; i < sizeof(resultSet) / 4; i++) {
		if (resultSet[i] != -1) {
			cout << resultSet[i] << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << "ms" << endl;


}

void differenceSet(int a[], int b[], int sizeOfA, int sizeOfB)
{
	auto start = chrono::high_resolution_clock::now();
	int resultSet[500];

	for (int num = 0; num < sizeof(resultSet) / 4; num++) {
		resultSet[num] = -1;
	}

	for (int i = 0; i < sizeOfA; i++) {
		int number = a[i];

		for (int j = 0; j < sizeOfB; j++) {
			if (found(b, number, sizeOfB)) {
				break;
			}
			else if (!found(b, number, sizeOfB)) {
				resultSet[i] = number;
				}
		}

	}

	sort(begin(resultSet), end(resultSet));
	cout << "Difference Set: ";

	for (int i = 0; i < sizeof(resultSet) / 4; i++) {
		if (resultSet[i] != -1) {
			cout << resultSet[i] << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << "ms" << endl;

}

void symmetricDifferenceSet(int a[], int b[], int sizeOfA, int sizeOfB)
{
	auto start = chrono::high_resolution_clock::now();
	int resultSet[500];

	for (int num = 0; num < sizeof(resultSet) / 4; num++) {
		resultSet[num] = -1;
	}

	for (int i = 0; i < sizeOfA; i++) {
		if (!found(b, a[i], sizeOfB)) {
			resultSet[i] = a[i];
		}

		for (int i = 0; i < sizeOfB; i++) {
			if (!found(a, b[i], sizeOfA)) {
				resultSet[i + sizeOfA] = b[i];
			}
		}

	}



	cout << "Symmetric Difference Set: ";
	sort(begin(resultSet), end(resultSet));
	for (int i = 0; i < sizeof(resultSet) / 4; i++) {
		if (resultSet[i] != -1) {
			cout << resultSet[i] << " ";
		}
	}
	cout << "\n";
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Time: " << duration.count() << "ms" << endl;

}

bool found(int a[], int value, int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		if (a[i] == value) {
			return true;
		}
	}

	return false;
}