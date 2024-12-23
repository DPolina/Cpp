#include <iostream>
#include <time.h>
#include <list>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

template <class T>
void fill(list<T>& l, int n, T min, T max) {

	for (int i = 0; i < n; i++) {
		l.push_back((rand() % (max - min)) + min);
	}
}

void N2_4() {

	cout << "Describe a function that generates a list of L characters by including "
		<< "elements that are on at least one of the L1 and L2 lists once." << endl << endl;

	list<char> L1;
	list<char> L2;
	set<char> L3;

	fill(L1, 10, '0', 'z');
	fill(L2, 8, '0', 'z');

	cout << "L1: ";
	for (const auto el : L1) {
		cout << el << " ";
	}
	cout << endl;

	cout << "L2: ";
	for (const auto el : L2) {
		cout << el << " ";
	}
	cout << endl;

	L1.sort();
	L2.sort();
	merge(L1.begin(), L1.end(), L2.begin(), L2.end(), inserter(L3, L3.begin()));

	cout << "L3: ";
	for (const auto el : L3) {
		cout << el << " ";
	}
}

void N2_6() {

	list<int> List;

	{
		int n = 0;
		cout << "Enter n: ";
		cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			double value = 0;
			cin >> value;
			List.push_back(value);
		}
	}

	auto head = List.begin();
	auto tail = List.rbegin();
	int mult = 1;

	while (head != List.end() && tail != List.rend()) {
		mult *= (*head - *tail);
		cout << "mult: " << mult << setw(15) << "head: " << *head << setw(15) << "tail: " << *tail << endl;
		advance(head, 2);
		advance(tail, 2);
	}

	cout << endl << "MULT = " << mult << endl;
}

int main() {

	N2_4();
	cout << endl;
	N2_6();

	system("pause");

	return 0;
}