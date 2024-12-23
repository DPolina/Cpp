#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;


/*
void N1() {

	cout << "Given a natural n. Is it true that this number corresponds exactly to the number of digits received?" << endl << endl;

	int n, k;

	cout << "N =  ";
	cin >> n;
	cout << "k = ";
	cin >> k;

	vector<int> vec;

	int n_size = int(log10(n) + 1); // *

	while(n) {
		vec.push_back(n % 10);
		n /= 10;
	}
	
	vec.Reverse();
	vec.Print();

	for (int i = 0; i < n_size; i++) {
		int counter = 0;
		for (int j = 0; j < n_size; j++) {
			if (vec.at(i) == vec.at(j)) {
				counter++;
			}
		}
		if (counter == k) {
			cout << "This is TRUE that this number contains exactly " << k << " identical numbers." << endl;
			return;
		}
	}
	cout << endl << "This is FALSE that this number contains exactly " << k << " identical numbers." << endl;
}

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
		if (n >= 1) {
			break;
		}
		else {
			cout << "Invalid value! " << endl;
		}
	} while (true);

	return n;
}

void N2() {

	cout << "Determine if the k-th digit of the fractional part of a given positive real number is equal to the sum of n previous digits." << endl << endl;

	string n;
	int k;
	int sum = 0;

	vector<char> frac;

	int count_dots = 0;

	bool isValid = false;

	while (isValid == false) {

		cout << "N = ";
		cin >> n;

		for (int i = 0; i < n.size(); i++) {
			if (n.at(i) == '.')
				count_dots++;
			if (((n.at(i) < '0' || n.at(i) > '9') && n.at(i) != '.') || count_dots > 1) {
				isValid = false;
				cout << "Invalid value!" << endl;
				count_dots = 0;
				break;
			}
			else {
				isValid = true;
			}
		}
	}

	k = input("k");

	for (int i = 0; i < n.size(); i++) {
		frac.push_back(n.at(i));
	}

	int int_size = 0;

	for (int i = 0; i < n.size(); i++) {
		if (frac.at(i) == '.')
			break;
		else
			int_size++;
	}

	int frac_size = 0;
	if (count_dots == 1 && frac.size() > int_size + 1)
		frac_size = frac.size() - int_size - 1;
	//cout << endl << "count_dots = " << count_dots << endl;
	//cout << "frac_size = " << frac_size << endl;

	if (k > frac_size) {
		if (count_dots == 0)
			frac.push_back('.');
		for (int i = 0; i < k - frac_size; i++) {  // 0.1234 000  |  .1234 000  | 1234.
			frac.push_back('0');
		}
		frac_size = k;
	}

	frac.Print();

	//cout << endl << "frac_size = " << frac_size << endl;
	//cout << endl << "int_size = " << int_size << endl;

	int target_idx = int_size + k;

	char target = frac.at(target_idx);
	//cout << "target = " << target << endl << endl;

	for (int i = int_size + 1; i < target_idx; i++) {
		sum += int(frac.at(i) - '0');
		//cout << "cur = " << frac.at(i) << "   sum = " << sum << endl;
	}

	if (int(frac.at(target_idx) - '0') == sum) {
		cout << endl << "The " << k << "-th digit " << frac.at(k + int_size) << " of the fractional part of N = " << n << " is EQUAL to the sum (" << sum << ") of " << k - 1 << " previous digits." << endl;
	}
	else {
		cout << endl << "The " << k << "-th digit " << frac.at(k + int_size) << " of the fractional part of N = " << n << " is NOT EQUAL to the sum (" << sum << ") of " << k - 1 << " previous digits." << endl;
	}
}
*/

void N2_1() {

	int size = 100;
	int max = 51;
	vector<int> vec;

	vector<int> occures;
	occures.assign(max, 0);

	for (int i = 0; i < size; i++) {
		int cur = rand() % max;
		occures[cur]++;
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << setw(5) << occures[vec[i]] << endl;
	}
	
	for (int i = 0; i < occures.size(); i++) {
		if (occures[i] == 2) {
			vec.push_back(i);
		}
	}
	
	cout << endl;
	for (auto el : vec) {
		cout << el << " ";
	}

	cout << endl << endl;
}

template<class T>
void fill_matrix(vector<vector<T>>& matrix, int max) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = (rand() % max) + 1;
		}
	}
}

template<class T>
void print_matrix(const vector<vector<T>>& matrix) {
	cout << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%4d ", matrix[i][j]);
		}
		cout << endl << endl;
	}
}

template<class T>
void N2_2() {

	srand(time(nullptr));

	int n = 0;
	cout << "N = ";
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));
	fill_matrix(matrix, 99);
	print_matrix(matrix);

	int size = 2 * n - 1;
	vector<int> arr(size);
	vector<int> arr(size);
	int arr_idx = size - 1;

	for (int down = n - 1; down > 0; down--) {
		int min = INT32_MAX;
		for (int j = down, i = n - 1; j <= n - 1, i >= down; j++, i--) {
			//cout << matrix[i][j] << " ";
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		//cout << "min = " << min << endl;
		arr[arr_idx--] = min;
	}

	for (int up = n - 1; up >= 0; up--) {
		int min = INT32_MAX;
		for (int j = 0, i = up; j <= up, i >= 0; j++, i--) {
			//cout << matrix[i][j] << " ";
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		//cout << "min = " << min << endl;
		arr[arr_idx--] = min;
	}

	for (const auto el : arr) {
		cout << el << " ";
	}
}

int main() {

	N2_1();
	N2_2<vector<int>>();

	system("pause");

	return 0;
}

