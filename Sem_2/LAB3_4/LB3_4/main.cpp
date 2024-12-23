#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int getSize(const char* file) {

    ifstream in(file);
    int size = 0;

    string str;
    while (!in.eof()) {
        in >> str;
        size++;
    }
    return sqrt(size);
}

void printFile(int n, const char* file) {

    ifstream in(file);
    char ch;

    if (in.fail()) {
        cout << "ERROR" << endl;
        return;
    }

    while (!in.eof()) {

        for (int i = 0; i < n; i++) {
            while (in.get(ch)) {
                cout << ch;
            }
        }
    }
    cout << endl << endl;
}

void writeFile(vector<vector<int>> matrix, int n) {

    ofstream out("./file.txt");

    if (out.fail()) {
        cout << "ERROR" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << matrix[i][j] << " ";
        }
        out << endl;
    }
}

template<class T>
void printMatrix(vector<vector<T>> matrix, int n) {

    printf("%4s", "");
    for (int i = 0; i < n; i++) {
        printf("%2d ", i);
    }
    cout << endl << endl;

    for (int i = 0; i < n; i++) {
        printf(" %-3d", i);
        for (int j = 0; j < n; j++) {
            printf("%2d ", matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> getMatrix(vector<vector<int>>& matrix, int n, const char* file) {

    ifstream in(file);
    char ch;

    while (!in.eof()) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                in >> ch;
                matrix[i].push_back(ch - '0');
            }
        }
    }
    return matrix;
}

vector<vector<int>> Mult(vector<vector<int>> original_matrix, vector<vector<int>> matrix2, int n) {

    vector<vector<int>> res;

    for (int i = 0; i < n; i++) {
        res.push_back(vector<int>());
        for (int j = 0; j < n; j++) {
            res[i].push_back(0);
            for (int k = 0; k < n; k++) {
                res[i][j] += original_matrix[i][k] * matrix2[k][j];
            }
        }
    }
    return res;
}

bool existsRoot(vector<vector<int>> matrix, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && matrix[i][j] > 0) {
                return true;
            }
        }
    }
    return false;
}

void addVertice(vector<vector<int>>& matrix, int& n) {

    for (int i = 0; i < n; i++) {
        matrix[i].push_back('0');
    }
    matrix.push_back(vector<int>(n + 1, 0));
    n++;
    writeFile(matrix, n);
}

void deleteVertice(vector<vector<int>>& matrix, int& n) {

    for (int i = 0; i < n; i++) {
        matrix[i].erase(matrix[i].end() - 1);
    }
    matrix.erase(matrix.end() - 1);
    n--;
    writeFile(matrix, n);
}

int main() {

    int n = getSize("file.txt");
    cout << "Size = " << n << endl << endl;

    printFile(n, "file.txt");

    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++) {
        matrix.push_back(vector<int>());
    }
    matrix = getMatrix(matrix, n, "file.txt");

    //printMatrix(matrix, n);

    vector<vector<int>> matrix2 = matrix;
    int root;

    for (int i = 1; i <= n; i++) {

        if (existsRoot(matrix2, n)) {
            cout << "A^" << i << ": \n\n";
            printMatrix(matrix2, n);
            cout << "K = " << i << endl << endl;
            break;
        }
        else
            matrix2 = Mult(matrix, matrix2, n);

    }

    //addVertice(matrix, n);
    //printFile(n, "file.txt");

    system("pause");

	return 0;
}

