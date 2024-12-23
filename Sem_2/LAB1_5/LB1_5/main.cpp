#include<iostream>
#include <math.h>

using namespace std;

void Ex(int n, int noms[], int k) {

	int banks = 0;
	int comps = 1;

	if (n % 5 != 0 || n <= 0) {
		cout << "Requested amount cannot be paid!" << endl;
	} else {
		cout << "\nBANKNOTES: ";

		for (int i = k - 1; i >= 0; ) {

			comps++;
			if (n >= noms[i]) {
				cout << noms[i] << " ";
				n = n - noms[i];
				banks++;
			}
			else {
				i--;
			}
		}

		cout << "\nNUM OF BANKNOTES: " << banks << endl;
		cout << "\ncomps = " << comps << endl;
	}
}

int main() {

	setlocale(LC_ALL, "rus");

	int noms[6] = { 5, 10, 20, 50, 100, 500};

	int k = 0;
	do {
		cout << "k = ";
		cin >> k;
		if (k > 0 && k <= 6) {
			break;
		}
		else {
			cout << "Invalid value! " << endl;
		}

	} while (true);
	
	int N = 0;
	cout << "N = ";
	cin >> N;

	Ex(N, noms, k);

	system("pause");

	return 0;
}