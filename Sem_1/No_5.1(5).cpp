#include <iostream> // No_5.1(5)

using namespace std;

double input_x();
double mult(double a, double b);
double div(double a, double b);
double fact(int n);
double power(double m, int n);
double absolute(double* n);
double count_sum(double x, double e, int& k);

int main() {
	int k = 0;

	double x = input_x();
	double sum = count_sum(x, 1e-6, k);
	cout << "\nsum: " << sum << endl;
	cout << "terms: " << k << endl;

	system("pause");
	return 0;
}

double input_x() {
	double x = 0;
	do {
		cout << "x = ";
		cin >> x;

		if (cin.fail()) {
			cout << "Invalid value! " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (x > 0 && x <= 1) {
			break;
		}
		else {
			cout << "Invalid value! " << endl;
		}

	} while (true);

	return x;
}

double mult(double a, double b) {
	return a * b;
}

double div(double a, double b) {
	return a / b;
}

double fact(int n) {

	int factorial = 1;
	for (int i = 1; i <= n; i++) {
		factorial = factorial * i;
	}
	return factorial;
}

double power(double m, int n) {

	double num = m;
	for (int i = 1; i < n; i++) {
		num *= m;
	}
	return num;
}

double absolute(double* n) { //0x4368A21 --> * --> -10

	if ((*n) < 0) {
		return (*n) * (-1);
	}
	else {
		return (*n);
	}
}

double count_sum(double x, double E, int& k) {

	double sum = 0;

	for (k = 1; ; k++) {

		double slog = mult(div(power(-1, k), fact(mult(2, k))), power(div(x, 3.0), mult(4, k)));
		//cout << "k = " << k << ": " << slog << endl;
		sum += slog;

		//-10 --> & --> 0x4368A21
		double abs = absolute(&slog);

		if (abs < E) {
			break;
		}
	}
	return sum;
}
