//No_1.3(5)

#include <iostream>
#include <limits.h>
#include <time.h>

using namespace std;


void arr_fill(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "A[" << i << "] = ";
		cin >> arr[i];
	}
}

void arr_print(int* arr, int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "A[" << i << "] = " << arr[i] << endl;
	}
	cout << endl;
}

int find_max(int* arr, int size) {

	int max = INT_MIN;

	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int find_min(int* arr, int size) {

	int min = INT_MAX;

	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int indexof(int* arr, int x, int size) {

	int index= -1;

	for (int i = 0; i < size; i++) {
		if (x == arr[i]) {
			index = i;
		}
	}
	return index;
}

int& ref_max(int* arr, int size) {
;
	int* arr_ = new int[size];
	for (int i = 0; i < size; i++) {
		arr_[i] = arr[i];
	}

	int idx = -1;
	int max = find_max(arr, size);
	//cout << "\nmax = " << max << endl;
	int min = find_min(arr, size);
	//cout << "min = " << min << endl;

	while (idx < 0) {

		cout << endl;
		int max_ = find_max(arr_, size);
		int counter = 0;

		for (int i = 0; i < size; i++) {
			if (arr_[i] == max_) {
				counter++;
				if (counter >= 2) {
					idx = i;
				} 
			}
		}
		//cout << "max_ = " << max_ << endl;
		//cout << "counter = " << counter << endl;
		//cout << "idx = " << idx << endl;

		if (idx < 0) {
			if (find_max(arr_, size) == min) {
				idx = indexof(arr, max, size);
				break;
			}
			for (int i = 0; i < size; i++) {
				if (arr_[i] == max_) {
					arr_[i] = min - 1;
				}
			}
		}
	}
	//cout << "\nidx = " << idx << endl;


	delete[] arr_;
	return arr[idx];
}

int main() {

	srand(time(NULL));

	int n = 0;
	cout << "N = ";
	cin >> n;
	int* arr = new int[n];

	cout << endl;

	arr_fill(arr, n);

	arr_print(arr, n);
	
	arr_print(arr, n);

	system("pause");
	return 0;
}