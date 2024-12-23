#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>

using namespace std;

void printArray(int arr[5][5]);

int main() {

	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	int MIN = 0;
	int MAX = 99;

	int A[5][5];
	int B[5][5];
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			A[i][j] = rand() % (MAX - MIN + 1) + MIN;
		}
	}
	/*
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			max_num = 0;

			for (int i2 = 0; i2 < 5; i2++) {
				for (int j2 = 0; j2 < 5; j2++) {

					if (i != i2 && j != j2) {
						continue;
					}

					if (A[i2][j2] > max_num)
						max_num = A[i2][j2];
				}
			}

			B[i][j] = max_num;
		}
	}*/

	
	int max_row[5];
	int max_col[5];

	for (int i = 0; i < 5; i++) {
		int max_num = 0;
		for (int j = 0; j < 5; j++) {
			if (A[i][j] > max_num)
				max_num = A[i][j];
		}
		max_row[i] = max_num;
	}

	for (int j = 0; j < 5; j++) {
		int max_num = 0;
		for (int i = 0; i < 5; i++) {
			if (A[i][j] > max_num)
				max_num = A[i][j];
		}
		max_col[j] = max_num;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			B[i][j] = max_row[i] >= max_col[j] ? max_row[i] : max_col[i];
		}
	}

	printArray(A);
	cout << endl;
	printArray(B);

	system("pause");
	return 0;
}

void printArray(int arr[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << setw(3) <<  arr[i][j];
		}
		cout << endl;
	}
}

