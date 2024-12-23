//#define _USE_MATH_DEFINES
//
//#include <iostream>
//#include <math.h>
//#include <vector>
//
//#include "Gaussh.h"
//
//using namespace std;
//
//void Print(vector<vector<double>> matrix) {
//	cout << endl;
//	for (int i = 0; i < matrix.size(); i++) {
//		for (int j = 0; j < matrix.at(i).size(); j++) {
//			printf("%-10.3f", matrix[i][j]);
//			if (j == matrix.size() - 1) {
//				printf("%s  %-10.3f", "|", matrix[i][j + 1]);
//				break;
//			}
//		}
//		cout << endl << endl;
//	}
//	cout << endl;
//}
//
//void Print(vector<double> vec, int m) {
//	for (int i = 0; i < m; i++)
//		printf("%8.3f ", vec[i]);
//
//	cout << endl << endl;
//}
//
//int main() {
//
//	int N = 6;
//	int m = 5;
//
//	vector<double> X = { 0.164, 0.328, 0.656, 0.984, 1.312, 1.640 }; // H
//	vector<double> Y = { 0.448, 0.432, 0.421, 0.417, 0.414, 0.412 }; // ìþ
//
//	/*
//	int N = 5;
//	int m = 4;
//
//	vector<double> X = { 2.40, 3.50, 5.00, 6.89, 10.00 }; // nu
//	vector<double> Y = { 0.0141, 0.0281, 0.0562, 0.1125, 0.2250 }; // P
//	*/
//
//	/*
//	cout << "\nPOWERX : ";
//
//	vector<double> POWERX;
//
//	for (int k = 0; k < 2 * m + 1; k++) {
//		double sum = 0;
//		for (int i = 0; i < N; i++) {
//			sum += pow(X[i], k);
//		}
//		POWERX.push_back(sum);
//	}
//	Print(POWERX, 2 * m);
//
//	cout << "\nMATRIX: SUMX | PRAW " << endl;
//
//	vector<vector<double>> SUMX(m + 1, vector<double>(m + 1, 0));
//	vector<double> PRAW;
//
//	for (int l = 0; l < m + 1; l++) {
//		for (int j = 0; j < m + 1; j++) {
//			SUMX[l][j] = (POWERX[l + j]);
//		}
//		double sum = 0;
//		for (int i = 0; i < m + 1; i++) {
//			sum += Y[i] * pow(X[i], l);
//		}
//		PRAW.push_back(sum);
//	}
//	SUMX[0][0] = N;
//
//	//Print(SUMX);
//
//	vector<vector<double>> NMATRIX;
//	for (int i = 0; i < m + 1; i++) {
//		NMATRIX.push_back(SUMX[i]);
//		NMATRIX[i].push_back(PRAW[i]);
//	}
//
//	//Print(SUMX, PRAW, m);
//	Print(NMATRIX);
//	*/
//
//	vector<double> POWERX(2 * m + 1, 0);
//
//	for (int i = 0; i < m * 2 + 1; i++) {
//		double value = 0.f;
//		for (int j = 0; j < N; j++) {
//			value += pow(X[j], i);
//		}
//		POWERX[i] = value;
//	}
//	
//	cout << "\POWERX: ";
//	Print(POWERX, 2 * m + 1);
//	
//	vector<vector<double>> SUMX(m + 1, vector<double>(m + 2, 0));
//	
//	SUMX[0][0] = N;
//	for (int l = 0; l < m + 1; l++) {
//		for (int j = 0; j < m + 1; j++) {
//			if (!l && !j) {
//				continue;
//			}
//			int k = l + j;
//			SUMX[l][j] = POWERX[k];
//		}
//	}
//	cout << "\SUMX:\n";
//	Print(SUMX);
//	
//	vector<double> PRAW(m + 1, 0);
//	for (int l = 0; l < m + 1; l++) {
//		double value = 0.f;
//		for (int i = 0; i < N; i++) {
//			value += Y[i] * pow(X[i], l);
//		}
//		PRAW[l] = value;
//	}
//	cout << "\nPRAW:";
//	Print(PRAW, m + 1);
//	
//	for (int i = 0; i < m + 1; i++) {
//		SUMX[i][m + 1] = PRAW[i];
//	}
//	Print(SUMX);
//	
//	cout << "GAUSS : " << endl;
//
//	vector<double> A = Gauss_(SUMX, m + 1, m + 2);
//	cout << "\nA: ";
//	Print(A, m + 1);
//
//	double S = 0.f;
//	double sum = 0.f;
//	for (int i = 0; i < N; i++) {
//		sum = Y[i];
//		for (int j = 0; j < m; j++) {
//			sum -= (A[j] * pow(X[i], j));
//		}
//		sum = pow(sum, 2);
//		S += sum;
//	}
//	S *= (1 / (N - m));
//	S = sqrt(S);
//	cout << "S: " << S << endl;
//}