//No_1.5(5)

#include <iostream>
#include <math.h>
#include <tgmath.h>
#include <stdio.h>

using namespace std;

double Int(double a, double b, double s, double t, double eps, int n, double(*pf)(double, double, double)) {

	double Int = 0;
	double h = (abs(b - a) / n);
	double sum = 0;

	for (double x = a; x < b; x += h) {
		sum += pf(x, s, t);
	}

	Int = h * sum;
	return Int;
}

double Int_pereschet(double a, double b, double s, double t, double eps, int n, double(*pf)(double, double, double), int& k_iter) {

	double int_cur = Int(a, b, s, t, eps, n, pf);
	double int_prev = 0;

	while (abs(int_cur - int_prev) > eps) {
		
		n *= 2;
		k_iter++;

		int_prev = int_cur;
		int_cur = Int(a, b, s, t, eps, n, pf);
	}

	return int_cur;
}

double f(double x, double s, double t) {
	return s * pow(x, 2) / (log10(pow(x, t)) + pow(cos(cbrt(x)), 2));
}

int main() {

	cout << "INT ( s * pow(x, 2) / (log(pow(x, t) + pow(cos(cbrt(x)), 2))) );  a = 2.63, b = 3.1" << endl;
	printf("\n%4s %15s %15s %14s\n\n", "s", "t", "Int", "k_iter");

	int k_iter = 0;
	double a = 2.63; 
	double b = 3.1;
	int n = 50000;

	for (double s = 1; s <= 10; s += 3) {
		for (double t = 1; t <= 3; t++) {
			double integral = Int_pereschet(a, b, s, t, 1e-6, n, f, k_iter);
			printf("%-14f %-14f %-14f %-14d\n", s, t, integral, k_iter);
		}
	}

	system("pause");

	return 0;
}