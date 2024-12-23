#include <iostream>
#include <math.h>

using namespace std;

int length(int num);


int pow_int(int x, int y) {
	int result = 1;

	for(int i = 0; i < y ;i++) {
		result *= x;
	}

	return result;
}

int main() {
	
	setlocale(LC_ALL, "rus");

	int n, k;

	cout << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;

	int count = 0;

	int len = length(n);
	for (int i = 1; i <= len; i++) {
		count = 0;
		int digit1 = n / pow_int(10,i) % 10;
		
		for (int j = 0; j < len; j++) {
			int digit2 = n / pow_int(10, j) % 10;
			if (digit1 == digit2) {
				count++;
			}
		}

		if (count >= k) {
			cout << "��� �����, ��� � ����� " << n << " ���� " << k << " ���������� ����." << endl;
			break;
		}
	}

	if (count < k) {
		cout << "��� �������, ��� � ����� " << n << " ���� " << k << " ���������� ����." << endl;
	}

	system("pause");
	return 0;
}

int length(int num) {

	int len = 0;
	while(num) {
		num /= 10;
		len++;
	}

	return len;
}

