//No_1.4(5)

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

double M2(double a, double b, double eps, double (*fnc)(double, double), double (*fnc_)(double, double), int& k_iter, double s = 0) {

	double x = b;

	k_iter = 1;

	while (abs(fnc(x, s)) > eps) {
		x = x - (fnc(x, s) / fnc_(x, s));
		k_iter++;
	}
	return x;
}

double f1(double x, double s= 0) {
	return pow(x - 1, 2) - 5;
}

double f1_(double x, double s = 0) {
	return 2 * x - 2;
}

double f2(double x, double s) {
	return pow(x, 2) - sin(5 * pow(x, s));
}

double f2_(double x, double s) {
	return 2 * x - 5 * s* cos(5 * pow(x, s - 1));
}

int main() {

	cout << "FIND ROOT:" << endl;
	cout << "\na) f(x) = (x - 1)^2 - 5, a = -3, b = 0 " << endl;
	
	int k_iter = 0;
	double root = M2(-3, 0, pow(10, -6), f1, f1_, k_iter);
	double f = f1(root);

	//cout << "\nX:  " << root << "   F(x):  "  << f << endl;
	printf("\n%3s %6s %10s %9s", "S", "X", "F(x)", "k_iter");
	printf("\n%3s %6f %8f %8d\n", "-", root, f1(root), k_iter);

	cout << endl << "b) f(x) = x ^ 2 - sin(5x ^ S)   (a = 0.5, b = 0.8; S = [0.7, 1.6], ds = 0.3) " << endl << endl;

	printf("%3c %6c %10s %10s", 'S', 'X', "F(x)", "k_iter\n");
	
	for (double s = 0.7; s < 1.6; s += 0.3) {

		root = M2(0.5, 0.8, 1e-6, f2, f2_, k_iter, s);
		f = f2(root, s);
		printf(" %3f %6f %10f %10d\n", s, root, f, k_iter);
	}
	system("pause");
	return 0;
}