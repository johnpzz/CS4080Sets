#include <iostream>
#include "Set.h"

using namespace std;

void initialize(int size1, int size2, int a[], int b[]) {

	cout << "Enter the " << size1 << " values for set 1: " << "\n";
	int input;
	for (int i = 0; i < size1; i++) {
		while (!(cin >> input)) {
			cin.clear();
			//cin.ignore(10000, '\n');
			cin.ignore();
			cout << "Enter a correct number: ";
		}
		a[i] = input;
		//cout << "Please enter another number: ";
	}
	cout << "\nEnter the " << size2 << " values for set 2: " << "\n";
	for (int i = 0; i < size2; i++) {
		while (!(cin >> input)) {
			cin.clear();
			//cin.ignore(10000, '\n');
			cin.ignore();
			cout << "Enter a correct number: ";
		}
		b[i] = input;
		//cout << "Please enter another number: ";
	}
}



int main() {
	const int size1 = 50;
	const int size2 = 50;
	cout << "The size of set one is " << size1 << "\n";
	cout << "The size of set two is " << size2 << "\n";
	int a[size1];
	int b[size2];
	initialize(size1, size2, a, b);
	cout << "\n(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
	int answer = -1;
	while (answer != 0) {
		cin >> answer;
		if (answer == 1) {
			unionSet(a, b, size1, size2);
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
		}
		else if (answer == 2) {
			intersectionSet(a, b, size1, size2);
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
		}
		else if (answer == 3) {
			differenceSet(a, b, size1, size2);
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
		}
		else if (answer == 4) {
			symmetricDifferenceSet(a, b, size1, size2);
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
		}
		else {
			cout << "Enter a valid selection: ";
		}
	}

	system("pause");
	return 0;
}