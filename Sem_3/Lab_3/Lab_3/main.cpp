#include <iostream>
#include <iomanip>

using namespace std;

double func1(double x1, double x2) {
	return 2 * pow(x1, 3) - pow(x2, 2) - 1;
}

double func2(double x1, double x2) {
	return x1 * pow(x2, 3) - x2 - 4;
}

void Jacobi(double x1, double x2, double** J) {

	J[0][0] = 6 * pow(x1, 2);
	J[0][1] = -2 * x2;
	J[1][0] = pow(x2, 3);
	J[1][1] = 3 * x1 * pow(x2, 2) - 1;
}

void M_Jacobi(double x1, double x2, double** J, double M) { // приращение ћ

	J[0][0] = (func1(x1 + M * x1, x2) - func1(x1, x2)) / (M * x1);
	J[0][1] = (func1(x1, x2 + M * x2) - func1(x1, x2)) / (M * x2);
	J[1][0] = (func2(x1 + M * x1, x2) - func2(x1, x2)) / (M * x1);
	J[1][1] = (func2(x1, x2 + M * x2) - func2(x1, x2)) / (M * x2);
}

double* Gauss(double** arr1, double* arr2, int n) {

	double* X = new double[n];

	for (int k = 0; k < n; k++) {

		for (int i = k + 1; i < n; i++) {
			if (abs(arr1[i][k]) > abs(arr1[k][k])) {
				swap(arr1[i], arr1[k]);
				swap(arr2[i], arr2[k]);
			}
		}
		double key = arr1[k][k];
		if (key == 0) {

			cout << "Error\n";
			system("pause");
			exit(0);
		}
		for (int i = k; i < n; i++)
			arr1[k][i] /= key;
		
		arr2[k] /= key;
		for (int i = k + 1; i < n; i++) {

			double s = arr1[i][k];
			for (int j = k; j < n; j++)
				arr1[i][j] -= s * arr1[k][j];
			
			arr2[i] -= s * arr2[k];
		}
	}


	for (int k = n - 1; k >= 0; k--) {
		X[k] = arr2[k];
		for (int i = n - 1; i > k; i--)
			X[k] -= arr1[k][i] * X[i];
	}
	return X;
}

double* Newton(double x1, double x2, int NIT, double eps1, double eps2) {

	int k = 1;
	cout << left << setw(5) << "k" << setw(20) << "sigma1" << setw(20) << "sigma2" << setw(20) << "X1" << setw(20) << "X2" << endl;
	double* F = new double[2];
	double** J = new double* [2]; // якоби
	for (int i = 0; i < 2; i++)
		J[i] = new double[2];

	double* dX = new double[2];
	double x1k, x2k;
	double sigma1, sigma2;
	double tmp;

	do {
		F[0] = -func1(x1, x2);
		F[1] = -func2(x1, x2);
		Jacobi(x1, x2, J);

		dX = Gauss(J, F, 2);
		x1k = x1 + dX[0];
		x2k = x2 + dX[1];
		sigma1 = abs(func1(x1, x2));
		tmp = abs(func2(x1, x2));
		if (tmp > sigma1)
			sigma1 = tmp;
		sigma2 = abs(x1k - x1) / (x1k >= 1 ? x1k : 1);
		tmp = abs(x2k - x2) / (x2k >= 1 ? x2k : 1);
		if (tmp > sigma2)
			sigma2 = tmp;
		
		x1 = x1k;
		x2 = x2k;
		cout << left << setw(5) << k << setw(20) << sigma1 << setw(20) << sigma2 << setw(20) << x1 << setw(20) << x2 << endl;
		if (k >= NIT) {
			cout << "IER = 2\n";
			system("pause");
			exit(2);
		}
		k++;
	} while (sigma1 > eps1 && sigma2 > eps2);

	dX[0] = x1;
	dX[1] = x2;
	return dX;
}

double* M_Newton(double x1, double x2, int NIT, double eps1, double eps2, double M) {

	int k = 1;
	cout << left << setw(4) << "k" << setw(20) << "sigma1" << setw(20) << "sigma2" << setw(20) << "X1" << setw(20) << "X2" << endl;
	double* F = new double[2];
	double** J = new double* [2];
	for (int i = 0; i < 2; i++)
		J[i] = new double[2];
	
	double* dX = new double[2];
	double x1k, x2k;
	double sigma1, sigma2;
	double tmp;
	do {
		F[0] = -func1(x1, x2);
		F[1] = -func2(x1, x2);
		M_Jacobi(x1, x2, J, M);

		dX = Gauss(J, F, 2);
		x1k = x1 + dX[0];
		x2k = x2 + dX[1];
		sigma1 = abs(func1(x1, x2));
		tmp = abs(func2(x1, x2));
		if (tmp > sigma1)
			sigma1 = tmp;
		
		sigma2 = abs(x1k - x1) / (x1k >= 1 ? x1k : 1);
		tmp = abs(x2k - x2) / (x2k >= 1 ? x2k : 1);
		if (tmp > sigma2)
			sigma2 = tmp;

		x1 = x1k;
		x2 = x2k;
		cout << left << setw(4) << k << setw(20) << sigma1 << setw(20) << sigma2 << setw(20) << x1 << setw(20) << x2 << endl;
		if (k >= NIT) {
			cout << "IER = 2\n";
			exit(2);
		}
		k++;
	} while (sigma1 > eps1 && sigma2 > eps2);

	dX[0] = x1;
	dX[1] = x2;
	return dX;
}


int main() {

	int NIT = 100;
	double eps1 = 1e-9;
	double eps2 = 1e-9;

	cout << "Newton method at (1;1)  \n\n";
	double* x = new double[2];
	x = Newton(1, 1, NIT, eps1, eps2);

	cout << "\nM_Newton method at (1;1) and M = 0.01  \n\n";
	double* x1 = new double[2], * x2 = new double[2], * x3 = new double[2];
	x1 = M_Newton(1, 1, NIT, eps1, eps2, 0.01);

	cout << "\nM_Newton method at (1;1) and M = 0.05  \n\n";
	x2 = M_Newton(1, 1, NIT, eps1, eps2, 0.05);

	cout << "\nM_Newton method at (1;1) and M = 0.1  \n\n";
	x3 = M_Newton(1, 1, NIT, eps1, eps2, 0.1);

	system("pause");
	return 0;
}
