#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void sort(int arr[], int arr_len);
int search(int arr[], int number);

int main() {

	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	const int ARR_MAX = 10000;
	
	int A[ARR_MAX];
	int B[ARR_MAX];
	int C[ARR_MAX];

	int len_A = 0;
	int len_B = 0;
	int len_C = 0;

	int A_min = 0;
	int A_max = 0;

	int B_min = 0;
	int B_max = 0;

	do {
		cout << "������� ����� ������� �: ";
		cin >> len_A;
		if (cin.fail()) {
			cout << "������� ������������ ��������. " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (len_A > 0 && len_A < ARR_MAX)
			break;
		else
			cout << "������� ������������ ��������. " << endl;
	} while (true);

	do {
		cout << "\n������� ����� ������� B: ";
		cin >> len_B;
		if (cin.fail()) {
			cout << "������� ������������ ��������. " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (len_B > 0 && len_B < ARR_MAX)
			break;
		else
			cout << "������� ������������ ��������. " << endl;
	} while (true);

	cout << "\n��� �� ������ ��������� ������ A? \n\n1 ������� \n2 ������������� ��������� ����� \n" << endl;

	int num = 0;

	do {
		cout << "�������� �� ������������ ���������: ";
		cin >> num;
		if (cin.fail()) {
			cout << "������! ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (num == 1 || num == 2)
			break;

	} while (true);

	cout << "\n" << endl;

	if (num == 1) {
		for (int i = 0; i < len_A; i++) {
			cout << "A[" << i << "] = ";
			cin >> A[i];
		}
	} else {
		do {
			do {
				cout << "������� ������ �������: ";
				cin >> A_min;
				if (cin.fail()) {
					cout << "������! ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				} else {
					break;
				}
			} while (true);

			do {
				cout << "������� ������� �������: ";
				cin >> A_max;
				if (cin.fail()) {
					cout << "������! ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				} else {
					break;
				}
			} while (true);

		if (A_min <= A_max)
			break;
		else
			cout << "������! ������ ������� ������ ���� ������ �������. " << endl;

		} while (true);

		for (int i = 0; i < len_A; i++) {
			A[i] = rand() % (A_max - A_min + 1) + A_min;
		}
	}

	cout << "\n������ � ��������." << endl;

	cout << "\n��� �� ������ ��������� ������ B? \n\n1 ������� \n2 ������������� ��������� ����� \n" << endl;

	do {
		cout << "�������� �� ������������ ���������: ";
		cin >> num;
		if (cin.fail()) {
			cout << "������! ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (num == 1 || num == 2)
			break;

	} while (true);

	cout << "\n" << endl;

	if (num == 1) {
		for (int i = 0; i < len_B; i++) {
			cout << "B[" << i << "] = ";
			cin >> B[i];
		}
	} else {
		do {
			do {
				cout << "������� ������ �������: ";
				cin >> B_min;
				if (cin.fail()) {
					cout << "������! ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				} else {
					break;
				}
			} while (true);

			do {
				cout << "������� ������� �������: ";
				cin >> B_max;
				if (cin.fail()) {
					cout << "������! ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				} else {
					break;
				}
			} while (true);

			if (B_min <= B_max) 
				break;
			else 
				cout << "������ ������� ������ ���� ������ �������. " << endl;

		} while (true);

		for (int i = 0; i < len_B; i++) {
			B[i] = rand() % (B_max - B_min + 1) + B_min;
		}
	}

	cout << "\n������ B ��������." << endl;
	
	sort(A, len_A); 
	sort(B, len_B);  
	//������ ������ �������:
	// 1) sizeof(A) / sizeof(A[0])
	// 2) _countof(A)  (������ ��� Microsoft Visual Studio)
	// 3) std::size(A) (������ ��� ����� ���������� �����)
	
	cout << " \n\n������ �[" << len_A << "]:  ";
	for (int i = 0; i < len_A; i++) {
		cout << A[i] << " ";
	}

	cout << " \n\n������ B[" << len_B << "]:  ";
	for (int i = 0; i < len_B; i++) {
		cout << B[i] << " ";
	}

	/*
	for (int i = 0, j = 0; i < len_A; i++) {
		if (search(B, len_B, A[i]) == -1) {
			C[j] = A[i];
			len_C++;
			j++;
		}
	}*/

	int idx_A = 0;
	int idx_B = 0;
	int idx_C = 0;

	for(; idx_A < len_A; idx_A++){
		int num = A[idx_A];

		while(idx_B < len_B && B[idx_B] < num){
			idx_B++;
		}

		if(num != B[idx_B]){
			C[idx_C++] = num;
			len_C ++;
		}
	}


	//sort(C, len_C); 

	cout << " \n\n������ C[" << len_C << "]:  ";
	for (int i = 0; i < len_C; i++) {
		cout << C[i] << " ";
	}
	cout << "\n" << endl;

	system("pause");
	return 0;
}

void sort(int arr[], int arr_len) {

	bool sw = true;
	while (sw) {
		sw = false;
		for (int i = 0; i < arr_len - 1; i++) {
			if (arr[i] > arr[i + 1]) 
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			    sw = true;
			}
		}
	}
}

int search(int arr[], int len_arr, int number) {

	int low = 0;
	int high = len_arr - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == number)
			return mid;
		else if (arr[mid] < number)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
