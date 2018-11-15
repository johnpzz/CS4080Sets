#include <iostream>
#include "Set.h"


using namespace std;

void initialize(Set s1, Set s2, int size1, int size2) {

	for (int i = 0; i < size1; i++) {
		cout << "Enter the values for set 1: ";
		int value;
		while (!(cin >> value)) {
			cout << "Enter a valid value: ";
			cin.clear();
			cin.ignore();
		}
		*(s1.getSetPointer() + i) = value;
	}


	for (int i = 0; i < size2; i++) {
		cout << "Enter the values for set 2: ";
		int value;
		while (!(cin >> value)) {
			cout << "Enter a valid value: ";
			cin.clear();
			cin.ignore();
		}
		*(s2.getSetPointer() + i) = value;
	}



}


void prompt(Set s1, Set s2, int size1, int size2) {
	cout << "Welcome!\n(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
	int selection;

	while (!(cin >> selection)) {
		cout << "Enter a valid selection: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}


	while (selection != 0) {
		if (selection == 1) {
			//union;
			//unionSet(a, b, sizeOfA, sizeOfB);
			Set resultSet = s1 + s2;
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
			cin >> selection;

		}
		else if (selection == 2) {
			//intersection
			//intersectionSet(a, b, sizeOfA, sizeOfB);
			Set resultSet = s1 & s2;
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
			cin >> selection;
		}
		else if (selection == 3) {
			//difference
			//differenceSet(a, b, sizeOfA, sizeOfB);
			Set resultSet = s1 - s2;
			cout << "(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
			cin >> selection;
		}
		else if (selection == 4) {
			//symmetric difference
			//symmetricDifferenceSet(a, b, sizeOfA, sizeOfB);
			Set resultSet = s1 * s2;
			cout << "Welcome!\n(1) for Union Set\n(2) for Intersection Set\n(3) for Difference Set\n(4) for Symmetric Difference Set\n(0) to EXIT: ";
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

	//Set *s1 = new Set(size1);
	//Set *s2 = new Set(size2);
	Set s1(size1);
	Set s2(size2);
	
	initialize(s1, s2, size1, size2);
	cout << "Set 1: "; s1.print();
	cout << "Set 2: "; s2.print();

	prompt(s1, s2, size1, size2);



	//s1->print();

	//Set resultSet = *s1 + *s2;

	/*
	*(s1.getSetPointer) = 2;
	*(s1.getSetPointer + 1) = 3;
	Set s2(2);
	*s2.getSetPointer = 3;
	*(s2.getSetPointer + 1) = 4;
	Set unionSet = s1 + s2;

	for (int i = 0; i < unionSet.getSize; i++) {
		cout << *(unionSet.getSetPointer + i) << " ";
	}
	*/


	//delete s1;
	//delete s2;

	system("pause");
	return 0;
}