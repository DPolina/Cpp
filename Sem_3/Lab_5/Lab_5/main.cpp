#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
	return (1 + pow(x, 2)) / (1 + pow(x, 3));
}

double f(double x, double y) {
	//return pow(x, 2) + 2 * y;
	return sin(x + y);
}

//double f(double x, double y, double m, double n) {
//	//return pow(x, 2) + 2 * y;
//	return pow(M_E, -m * (x + y)) / (1 + n * (x + y));
//}

double Trapeze_method(double epsilon, double a, double b, int n) {

	double h = (b - a) / n;
	double res = 0;

	//do {
	double sum = 0;
	double x_cur = a;

	for (int i = 1; i <= n - 1; i++) {
		sum += f(x_cur);
		x_cur += h;
	}
	res = (h / 2) * (f(a) + 2 * sum + f(b));

	//} while (abs(Trapeze_method(epsilon, a, b, h / 2) - Trapeze_method(epsilon, a, b, h)) > 3 * epsilon);

	return res;
}

//double R_Trap(double f(double), double r, double p, double epsilon, double a, double b, int n) {
//	double I = Trapeze_method(epsilon, a, b, n);
//	double Ir = Trapeze_method(epsilon, a, b, n * pow(r, -1));
//
//	return (I - Ir) / (pow(r, p) - 1);
//}

double Simpson_method(double epsilon, double a, double b, int n) {

	double h = (b - a) / n;
	double sum1 = 0;
	double sum2 = 0;
	int m = n / 2;

	for (double x = a + h; x < b; x += 2 * h)
	{
		sum1 += f(x);
	}
	for (double x = a + 2 * h; x < b; x += 2 * h)
	{
		sum2 += f(x);
	}
	double res = (h / 3) * (f(a) + (4 * sum1) + (2 * sum2) + f(b));

	return res;
}

double CubatureSimpson_method(double epsilon, double a, double b, double c, double d, int n, int m) {

	double h_x = (b - a) / (2 * n);
	double x_0 = a;
	double x_1 = (a + b) / 2; 
	double x_2 = b;
	double h_y = (d - c) / (2 * m);
	double y_0 = c;
	double y_1 = (c + d) / 2;
	double y_2 = d;

	double sum = 0;

	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= m - 1; j++) {
			sum += f(x_0 + (2 * i) * h_x, y_0 + (2 * j) * h_y) + 
				4 * f(x_0 + (2 * i + 1) * h_x, y_0 + (2 * j) * h_y) + 
				f(x_0 + (2 * i + 2) * h_x, y_0 + (2 * j) * h_y) +
				4 * f(x_0 + (2 * i) * h_x, y_0 + (2 * j + 1) * h_y) + 
				16 * f(x_0 + (2 * i + 1) * h_x, y_0 + (2 * j + 1) * h_y) + 
				4 * f(x_0 + (2 * i + 2) * h_x, y_0 + (2 * j + 1) * h_y) + 
				f(x_0 + (2 * i) * h_x, y_0 + (j + 2) * h_y) + 
				4 * f(x_0 + (2 * i + 1) * h_x, y_0 + (2 * j + 2) * h_y) + 
				f(x_0 + (2 * i + 2) * h_x, y_0 + (2 * j + 2) * h_y);
		}
	}
	double res = (h_x * h_y) / 9 * sum;

	return res;
}

int main() {

	double epsilon = 1e-5;
	int n = 1000;

	printf("TRAPEZE - F4: %8.6f\n", Trapeze_method(epsilon, 3.0, 4.254, n));
	printf("SIMPSON - F4: %8.6f\n", Simpson_method(epsilon, 3.0, 4.254, n));
	printf("CUBATURE SIMPSON - F33: %6.4f\n", CubatureSimpson_method(epsilon, 0, M_PI / 2, 0 , M_PI / 4, n, n));
}