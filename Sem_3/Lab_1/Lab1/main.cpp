#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void printMatrix(vector<vector<double>> matrix, int m, int n) {

	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1)
				cout << " | ";
			//printf("%5.2f ", matrix[i][j]);
			printf("%7.3f ", matrix[i][j]);
		}
		cout << endl << endl;
	}
	cout << endl;
}

void printVector(vector<double> vec, int m) {

	for (int i = 0; i < m; i++)
		printf("%9.5f ", vec[i]);

	cout << endl << endl;
}

void swap_el(vector<double>& matrix, int m, int idx1, int idx2) {
	double temp = matrix[idx1];
	matrix[idx1] = matrix[idx2];
	matrix[idx2] = temp;
}

void divMatrix(vector<vector<double>>& matrix, int m, int n, double k, int idx) {

	for (int i = idx; i < m; i++)
		for (int j = idx; j < n; j++)
			matrix[i][j] /= k;
}

void distractRows(vector<vector<double>>& matrix, int n, int root, int idx) {

	double cur = matrix[idx][root];
	//cout << endl << "cur = " << cur << endl;

	for (int k = 0; k < n; k++) {
		//cout << endl << matrix[idx][k] << " -= " << matrix[root][k] << " * " << cur  << " = " << matrix[idx][k] - matrix[root][k] * cur << endl;
		matrix[idx][k] -= matrix[root][k] * cur;
	}
}

vector<double> distractVectors(vector<double> vec1, vector<double> vec2, int m) {
	vector<double> res;
	for (int i = 0; i < m; i++)
		res.push_back(vec1[i] - vec2[i]);

	return res;
}

vector<double> multMatrix(vector<vector<double>> matrix, vector<double> vec, int m) {
	vector<double> res(m, 0);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			res[i] += matrix[i][j] * vec[j];
	}
	return res;
}

void takeNewVec(vector<vector<double>>& matrix, vector<double> vec, int m) {
	for (int i = 0; i < m; i++)
		matrix[i][m] = vec[i];
}

double getSum(vector<double> vec, vector<double> x, int m) {
	double res = 0;
	for (int i = 0; i < m; i++)
		res += vec[i] * x[i];
	return res;
}

void swapMax(vector<vector<double>>& matrix, int m, int n, int idx) {

	double m_max = matrix[idx][idx];
	int max_idx = idx;
	for (int i = idx + 1; i < m; i++) {
		if (abs(m_max) < abs(matrix[i][idx])) {
			m_max = matrix[i][idx];
			max_idx = i;
		}
	}
	matrix[idx].swap(matrix[max_idx]);
}

void Gauss(vector<vector<double>>& matrix, int m, int n) {

	int step = 1;

	for (int i = 0; i < m; i++) {

		cout << "STEP " << step++ << " : FIND MAX AND PUT FIRST " << endl;

		swapMax(matrix, m, n, i);
		printMatrix(matrix, m, n);

		cout << "STEP " << step++ << " : DIVIDE BY MAX" << endl;

		divMatrix(matrix, m, n, matrix[i][i], i);
		printMatrix(matrix, m, n);

		if (i == m - 1) break;

		cout << "STEP " << step++ << " : DISTRACT ROWS TO GET NULLS" << endl;

		for (int j = i + 1; j < m; j++)
			distractRows(matrix, n, i, j);

		printMatrix(matrix, m, n);
	}

	cout << "FINAL MATRIX : " << endl;
	printMatrix(matrix, m, n);
}

vector<double> BackGauss(vector<vector<double>> matrix, int m, int n) {

	vector<double> res(m, 0);

	res[m - 1] = matrix[m - 1][n - 1];
	for (int i = m - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < m; j++) {
			sum += matrix[i][j] * res[j];
		}
		res[i] = matrix[i][n - 1] - sum;
	}
	return res;
}

int main() { // точность, уст, эфф.

	srand(time(nullptr));
	
	int N = 4; // 3 x 3
	int M = 3;

	//int N = 5; // 4 x 4
	//int M = 4;

	//vector<vector<double>> matrix { { 2.21, 3.65, 1.69, 6.99, -8.35 }, { 8.30, 2.62, 4.10, 1.90, -10.65 }, { 3.92, 8.45, 7.78, 2.46, 12.21 }, { 3.77, 7.21, 8.04, 2.28, 10.48 } };
	vector<vector<double>> matrix{ { 2.31, 31.49, 1.52, 40.95 }, { 4.21, 22.42, 3.85, 30.24 }, { 3.49, 4.85, 28.72, 42.81 } };
	//vector<vector<double>> matrix { { 2.30, 5.70, -0.80, -6.49 }, { 3.50, -2.70, 5.30, 19.20 }, { 1.70, 2.30, -1.80, -5.09 } };

	/*vector<vector<double>> matrix;
	for (int i = 0; i < M; i++)
		matrix.push_back(vector<double>());

	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			double a;
			cout << "A_" << m + 1 << n + 1 << " = ";
			cin >> a;
			matrix[m].push_back(a);
		}
	}*/

	vector<double> def_vec;
	for (int i = 0; i < M; i++)
		def_vec.push_back(matrix[i][N - 1]);

	vector<vector<double>> matrix2;
	for (int i = 0; i < M; i++)
		matrix2.push_back(matrix[i]);

	//cout << endl << "ORIGINAL MATRIX : " << endl;
	//printMatrix(matrix, M, N);

	cout << "MATRIX_2 : " << endl;
	printMatrix(matrix2, M, N);

	Gauss(matrix2, M, N);

	vector<double> x_1 = BackGauss(matrix2, M, N);
	cout << "X : ";
	printVector(x_1, M);

	vector<double> AX = multMatrix(matrix, x_1, M);
	cout << "AX : ";
	printVector(AX, M);

	vector<double> delta_vec = distractVectors(AX, def_vec, M);
	cout << "DELTA_VEC : ";
	printVector(delta_vec, M);

	takeNewVec(matrix, AX, M);
	cout << "NEW ORIGINAL MATRIX : " << endl;
	printMatrix(matrix, M, N);

	Gauss(matrix, M, N);

	vector<double> x_2 = BackGauss(matrix, M, N);
	cout << "X_1 : ";
	printVector(x_1, M);
	cout << "X_2 : ";
	printVector(x_2, M);

	double sigma = 0.f;
	double max = 0.f;
	for (int i = 0; i < M; i++) {
		max = abs((x_2[i] - x_1[i]) / x_1[i]);
		if (sigma < max)
			sigma = max;
	}
	printf("SIGMA : %-20.16f\n\n", sigma);

	for (int i = 0; i < M; i++) {
		double left = 0;
		for (int j = 0; j < M; j++) {
			left += matrix[i][j] * x_1[j];
		}
		printf("%20.16f = %-20.16f\n", left, matrix[i][N - 1]);
	}

	system("pause");
	return 0;
}