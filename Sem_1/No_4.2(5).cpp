#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	const int MAX = 100;

	char num[MAX] = {0};
	char num2[MAX] = {0};
	cout << "����� � 16��: ";
	cin.getline(num, MAX);

	int length = strlen(num);
	int power = 0;
	int idx = 0;

	while (true) {
		power++;
		if (num[idx + 1] == '.') {
			break;
		} else {
			idx++;
		}
	}

	double answer = 0;
	double number = 0;

	for (int i = 0; i < length; i++) {

		char letter = toupper(num[i]);
		if (letter == '.')
			continue;

		switch (letter) {
			case 'A':
				number = 10;
				break;
			case 'B':
				number = 11;
				break;
			case 'C':
				number = 12;
				break;
			case 'D':
				number = 13;
				break;
			case 'E':
				number = 14;
				break;
			case 'F':
				number = 15;
				break;
			default:
				number = char(letter - '0');
				break;
		}
		cout << number << "*16^" << power - 1 << " + ";
		answer += number * pow(16., power - 1);
		power--;
	}

	sprintf(num2, "Number is %f\n", answer);
	cout << num2;
	//cout << "����� � 10��: " << setprecision(20) << answer << endl;

	system("pause");

	return 0;
}

