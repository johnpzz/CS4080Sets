#include <iostream>
#include "Set.h"

using namespace std;


void initialize(int* a, int* b, int sizeOfA, int sizeOfB) {

	for (int i = 0; i < sizeOfA; i++) {
		cout << "Enter the values for set 1: ";
		int value;
		while (!(cin >> value)) {
			cout << "Enter a valid value: ";
			cin.clear();
			cin.ignore();
		}

		*(a + i) = value;
	}

	for (int i = 0; i < sizeOfB; i++) {
		cout << "Enter the values for set 2: ";
		int value;
		while (!(cin >> value)) {
			cout << "Enter a valid value: ";
			cin.clear();
			cin.ignore();
		}

		*(b + i) = value;
	}
}



void prompt(int a[], int b[], int sizeOfA, int sizeOfB) {

	cout << "Welcome!\n(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(0) to EXIT: ";
	int selection;

	while (!(cin >> selection)) {
		cout << "Enter a valid selection: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	while (selection != 0) {

		if (selection == 1) {
			//union;
			unionSet(a, b, sizeOfA, sizeOfB);
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
			cin >> selection;

		}
		else if (selection == 2) {
			//intersection
			intersectionSet(a, b, sizeOfA, sizeOfB);
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
			cin >> selection;
		}
		else if (selection == 3) {
			//difference
			differenceSet(a, b, sizeOfA, sizeOfB);
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
			cin >> selection;
		}
		else if (selection == 4) {
			//symmetric difference
			symmetricDifferenceSet(a, b, sizeOfA, sizeOfB);
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
			cin >> selection;
		}
		else {
			cout << "Enter a valid selection: ";
			cin >> selection;
		}

	}
	cout << "\nThanks for using my program!\n";

}


int main() {

	int size1, size2;
	cout << "Enter the size of set 1: ";
	cin >> size1;
	cout << "Enter the size of set 2: ";
	cin >> size2;

	int* set1 = new int[size1];
	int* set2 = new int[size2];

	initialize(set1, set2, size1, size2);

	prompt(set1, set2, size1, size2);



	delete[size1] set1;
	delete[size2] set2;
	system("pause");
	return 0;
}