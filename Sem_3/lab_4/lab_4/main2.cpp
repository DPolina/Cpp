#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double* Gauss_(double** matrix, int n, int m) {

	double elem;
	for (int j = 0; j < n; j++) {

		double max = 0;
		int strm = 0;

		for (int i = j; i < n; i++) {
			if (abs(matrix[i][j]) > max) {
				max = abs(matrix[i][j]);
				strm = i;
			}
		}

		if (max > abs(matrix[j][j])) {
			double* sto = matrix[j];
			matrix[j] = matrix[strm];
			matrix[strm] = sto;
		}

		elem = matrix[j][j];
		for (int i = j; i < m; i++) {
			matrix[j][i] /= elem;
		}

		for (int i = j + 1; i < n; i++) {
			elem = matrix[i][j];
			for (int k = j; k < m; k++) {
				matrix[i][k] -= elem * matrix[j][k];
			}
		}
	}

	double* vec = new double[m];
	vec[n - 1] = matrix[n - 1][n];

	for (int i = n - 2; i >= 0; i--) {
		vec[i] = matrix[i][n];
		for (int j = i + 1; j < n; j++) {
			vec[i] -= matrix[i][j] * vec[j];
		}
	}

	delete[] matrix;

	return vec;
}

void Print(double* vec, int size) {
	for (int i = 0; i < size; i++) {
		printf("%8.3f", vec[i]);
	}
	cout << endl << endl;
}

void Print(double** matrix, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				printf("%3s % -13.1f ", "|", matrix[i][j]);
				break;
			}
			printf("%-13.1f ", matrix[i][j]);
		}
		cout << endl << endl;
	}
	cout << endl;
}

int main(void) {

	int N = 7;
	int m = 6;

	double* X = new double[7] { 0, 1, 2, 3, 4, 5, 6 }; // H
	double* Y = new double[7] { 760.0, 674.8, 598.0, 528.9, 466.6, 410.6, 360.2 }; // P

	double* POWERX = new double[2 * m + 1]{};
	for (int i = 0; i < m * 2 + 1; i++) {
		double value = 0.f;
		for (int j = 0; j < N; j++) {
			value += pow(X[j], i);
		}
		POWERX[i] = value;
	}

	cout << "POWERX: ";
	Print(POWERX, 2 * m + 1);

	double** SUMX = new double* [m + 1];
	for (int i = 0; i < m + 1; i++) {
		SUMX[i] = new double[m + 2]{};
	}
	SUMX[0][0] = N;
	for (int l = 0; l < m + 1; l++) {
		for (int j = 0; j < m + 1; j++) {
			if (!l && !j) {
				continue;
			}
			int k = l + j;
			SUMX[l][j] = POWERX[k];
		}
	}
	cout << "SUMX: " << endl << endl;
	Print(SUMX, m + 1, m + 2);

	double* PRAW = new double[m + 1]{};
	for (int l = 0; l < m + 1; l++) {
		double value = 0.f;
		for (int i = 0; i < N; i++) {
			value += Y[i] * pow(X[i], l);
		}
		PRAW[l] = value;
	}
	cout << "PRAW: ";
	Print(PRAW, m + 1);

	for (int i = 0; i < m + 1; i++) {
		SUMX[i][m + 1] = PRAW[i];
	}
	cout << "SUMX: " << endl << endl;
	Print(SUMX, m + 1, m + 2);

	double* A = Gauss_(SUMX, m + 1, m + 2);
	cout << "A: ";
	Print(A, m + 1);

	double S = 0.f;
	for (int i = 0; i < N; i++) {
		double value = Y[i];
		for (int j = 0; j < m + 1; j++) {
			value -= (A[j] * pow(X[i], j));
		}
		value = pow(value, 2);
		S += value;
	}
	S *= (1 / (N - m));
	S = sqrt(S);

	cout << "S: " << S;

	double sumA = 0.f;
	double sumB = 0.f;

	int counter = 0;
	for (int i = 0; i < N - 1; i++) {

		for (int j = i + 1; j < N - 1; j++) {
			double** matrix = new double* [3];
			for (int i_n = 0; i_n < 3; i_n++) {
				matrix[i_n] = new double[3];
			}

			matrix[0][0] = 1;
			matrix[0][1] = X[i];
			matrix[0][2] = log10(Y[i]);
			matrix[1][0] = 1;
			matrix[1][1] = X[j];
			matrix[1][2] = log10(Y[j]);
			//Print(matrix, 2, 3);
			double* vec = Gauss_(matrix, 2, 3);
			//Print(vec, 2);
			sumA += pow(10, vec[0]);
			sumB += vec[1];
			counter++;
			delete[] vec;
		}
	}

	cout << endl << endl << "a = " << sumA / counter << endl;
	cout << "b = " << sumB / counter << endl;
	
	return 0;
}



