#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <limits>
#include <vector>
#include <list>
#include <deque>

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
		else {
			break;
		}
	} while (true);

	return n;
}

void print(vector<int> a, int size) {
	cout << "[ ";
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << "]" << endl;
}

void plusOne(vector<int>& combs, int i) {

	//print(combs, 10);
	if (i == 0) return;

	if (combs[i] == 0) {
		combs[i]++;
		return;
	}
	else if (combs[i] == 1) {
		combs[i] = 0;
		plusOne(combs, i - 1);
	}
}

void QuickSort(vector<int>& a, int left, int right) {

	int i = left, j = right;
	int mid = a[(left + right) / 2];       

	do {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;

		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}

	} while (i < j);

	if (left < j) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}

int takeSum(vector<int> arr, vector<int> bin, int size) {

	int sum = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (bin[i] == 1) {
			sum += arr[i];
		}
	}
	return sum;
}

void printSum(vector<int> arr, vector<int> bin, int size) {

	int count = 0;
	for (int i = 0; i < size; i++) {
		if (bin[i] == 1) {
			count++;
			if (i != 0 && count > 1)
				cout << " + " << arr[i];
			else
				cout << arr[i];
		}
	}
}

int takeSum(vector<int> arr, int size) {

	int sum = 0;
	if (size > 0)
		for (int i = 0; i < size; i++) sum += arr[i];

	return sum;
}

bool inArray(vector<int> arr, int size, int num) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == num) {
			return true;
		}
	}
	return false;
}

vector<int> method1(vector<int> array, vector<int>& res, int size, int k) {

	vector<int> combs;

	for (int i = 0; i < size; i++) 
		combs.push_back(0);

	plusOne(combs, size - 1);
	//print(combs, size);

	for (int i = 0; i < pow(2, size) - 2; i++) {

		int sum = takeSum(array, combs, size);
		if (sum == k) {

			for (int j = 0; j < size; j++) {
				if (combs[j] == 1)
					res.push_back(array[j]);
			}
			break;
		}
		else
			plusOne(combs, size - 1);
	}

	return res;
}

vector<int> method2(const vector<int> arr, vector<int>& res, const int size, int s) {

	int i = 0, j = size - 1;

	while (i < j) {
		
		if (arr[i] + arr[j] == s) {

			cout << arr[i] << " + " << arr[j] << " = " << s << endl << endl;
			res.push_back(arr[i]);
			res.push_back(arr[j]);
			return res;
		}
		else if (arr[i] + arr[j] < s)
			i++;
		else
			j--;

	} // O(n)

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {
				if (arr[i] + arr[j] + arr[k] == s) {
					cout << arr[i] << " + " << arr[j] << " + " << arr[k] << " = " << s << endl << endl;
					res.push_back(arr[i]);
					res.push_back(arr[j]);
					res.push_back(arr[k]);
					return res;
				}
			}
		}
	} // O(n^3)

	return res;
}

vector<int> method3(const vector<int> arr, vector<int>& res, const int size, int s) {

	deque<int> deck;
	for (int i = 0; i < size; i++)
		deck.push_back(arr[i]);

	while (!deck.empty()) {

		if (deck.front() + deck.back() == s) {

			cout << deck.front() << " + " << deck.back() << " = " << s << endl << endl;
			res.push_back(deck.front());
			res.push_back(deck.back());
			return res;
		}
		else if (deck.front() + deck.back() < s)
			deck.pop_front();
		else
			deck.pop_back();

	}
	return res;
}

int main() {

	srand(time(nullptr));

	vector<int> array;
	vector<int> result;

	int size = 10;
	int min = -20;
	int max = 20;

	for (int i = 0; i < size; i++) 
		array.push_back((rand() % (max - min)) + min);

	QuickSort(array, 0, size - 1);
	cout << "Sorted array: ";
	print(array, array.size());

	int k = input("k");
	cout << endl;

	//result = method1(array, result, size, k); // For all combinations
	//result = method2(array, result, size, k); // Two and three pointers
	result = method1(array, result, size, k); // Using deque and two pointers

	cout << "Output: ";
	if (!result.empty())
		print(result, result.size());
	else
		print(result, result.size());
	cout << endl;

	system("pause");

	return 0;
}