#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

int input(string str) {

	int n = 0;

	do {
		cout << str << " = ";
		cin >> n;
		if (cin.fail()) {
			cout << "Invalid value! " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (n >= 1 && n <= 30) {
			break;
		}
		else {
			cout << "Invalid value! " << endl;
		}
	} while (true);

	return n;
}

void print(int** matrix, int n, int m) {

	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d ", matrix[i][j]);
		}
		cout << endl << endl;
	}
	cout << endl;
}

int main() {

	srand(time(nullptr));

	int N = input("N");
	int M = input("M");

	int max = 999;
	int min = 0;

	int** rec = new int* [M];
	for (int m = 0; m < M; m++) {
		rec[m] = new int[N];
	}

	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			rec[m][n] = (rand() % (max - min)) + min;
		}
	}

	print(rec, N, M);

	system("pause");

	return 0;
}