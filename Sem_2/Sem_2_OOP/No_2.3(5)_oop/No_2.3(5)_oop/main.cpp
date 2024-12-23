#include <iostream>
#include<iomanip>
#include<time.h>

#include "list.h"

using namespace std;

int main() {

	List<int> list;

	int n = 0;
	cout << "Enter n: ";
	cin >> n;

	for (int i = 0; i < 2 * n; i++) {
		double value = 0;
		cin >> value;
		list.add(value);
	}

	double mult = list.get_mult();
	cout << "\nMULT = " << mult << endl;

	system("pause");

	return 0;
}