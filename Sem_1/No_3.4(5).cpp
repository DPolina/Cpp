#include <iostream>
#include <math.h>

using namespace std;

int get_len_arr(int n[], int size);
int get_len_num(int num, int size);
void change_arr(int arr1[], int arr2[], int size);
void clear_arr(int arr[], int size);
void print_num(int arr[], int s);
void print_arr(int arr[], int s);
void print_line(int len);

int main()
{
	setlocale(LC_ALL, "rus");

	int M;
	int N;
	int M1[30] = {0};
	int M2[30] = {0};
	int R[30] = {0};

	int size = sizeof(M1) / sizeof(M1[0]);

	do {
		cout << "M = ";
		cin >> M;
	} while (M < 10);

	do {
		cout << "N = ";
		cin >> N;
	} while (N < 10);

	int M_ = M;
	
	for (int i = size - 1; i >= size - get_len_num(M, size); i--) {
		int m = M_ % 10;
		M1[i] = m;
		M2[i] = m;
		M_ /= 10;
	}

	
	int len2 = sizeof(M2) / sizeof(M2[0]);
	int len1 = sizeof(M1) / sizeof(M1[0]);

	// I_1 *
	// I_2 
	// -----
	// R

	for (int i = 1; i < N; i++) {

		cout << endl;
		print_arr(M1, size);
		print_arr(M2, size);
		print_line(size * 2 - 1);

		for (int i_2 = size - 1; i_2 >= size - get_len_arr(M2, size); i_2--) {	
			for (int i_1 = size - 1; i_1 >= size - get_len_arr(M1, size); i_1--) {

				int M12 = M1[i_1] * M2[i_2];
				R[i_1 + i_2 - size + 1] += M12;

				if (R[i_1 + i_2 - size + 1] >= 10) {
					R[i_1 + i_2 - size] += R[i_1 + i_2 - size + 1] / 10;
					R[i_1 + i_2 - size + 1] %= 10;
				}
			}
		}

		print_arr(R, size);
		cout << endl;

		if (i == N - 1) {
			cout << M << "^" << N << " = ";
			print_num(R, size);
		} else {
			change_arr(M1, R, size);
			clear_arr(R, size);
		}
	}
	
	system("pause");
	return 0;
}

int get_len_arr(int n[], int size) { // ?
	int idx_1 = 0;
	int idx_2 = size - 1;
	for (int i = 0; i < size; i++) {
		if (n[i] != 0) {
			idx_1 = i;
			break;
		}
	}
	return idx_2 - idx_1 + 1;
} 

int get_len_num(int num, int size) {
	int length = 0;
	while (num) {
		length++;
		num /= 10;
	}
	return length;
}

void print_arr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print_num(int arr[], int size) {
	bool not_zero = false;
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) {
			not_zero = true;
		}
		if (not_zero)
			cout << arr[i];
	}
	cout << endl;
}

void change_arr(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		arr1[i] = arr2[i];
	}
}

void clear_arr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

void print_line(int len) {
	for (int i = 0; i < len; i++) {
		cout << "-";
	}
	cout << endl;
}