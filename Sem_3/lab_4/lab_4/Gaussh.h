#pragma once
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

		//cout << "STEP " << step++ << " : FIND MAX AND PUT FIRST " << endl;

		swapMax(matrix, m, n, i);
		//printMatrix(matrix, m, n);

		//cout << "STEP " << step++ << " : DIVIDE BY MAX" << endl;

		divMatrix(matrix, m, n, matrix[i][i], i);
		//printMatrix(matrix, m, n);

		if (i == m - 1) break;

		//cout << "STEP " << step++ << " : DISTRACT ROWS TO GET NULLS" << endl;

		for (int j = i + 1; j < m; j++)
			distractRows(matrix, n, i, j);

		//printMatrix(matrix, m, n);
	}

	//cout << "FINAL MATRIX : " << endl;
	//printMatrix(matrix, m, n);
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
