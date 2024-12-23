#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	double x_0 = -0.4;
	double x_n = 0.6;
	double dx = 0.1;

	for (double x = x_0; x < x_n; x += dx) {
		double y1 = 1 / pow(1 + x, 2) - 1;

		double y2 = 0;
		double slog = 0;
		int n = 1;

		do {
			slog = pow(-1., n)*(n + 1)*pow(x, n); 

			y2 += slog;

			n++;
		} 
		while(abs(slog) >= 1e-6);

		cout << "X: "  << setw(10) << x << "   Y1: " << setw(10) << y1 << "   Y2: "  << setw(10) << y2  << " | " << n << endl;
	}

	system("pause");
	return 0;
}

