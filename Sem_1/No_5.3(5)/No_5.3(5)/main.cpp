#include <iostream>
#include <time.h>
#include "sort_insert.h"

using namespace std;

int* firest_element(int** matrix_prt, int m, int n, int* first, int* index) {
    for (int i_n = 0; i_n < m; i_n++) {
        first[i_n] = matrix_prt[n - 1][i_n];
        index[i_n] = i_n;
    }
    return first;
}

void outing(int n, int m, int** matrix) {
    for (int i = 0; i < n; i++) {
        for (int i_n = 0; i_n < m; i_n++) {
            printf("%4d ", matrix[i][i_n]);
        }
        cout << endl;
    }
    cout << endl;
}

void outing(int m, int* arr) {
    for (int i = 0; i < m; i++) {
        printf("%4d ", arr[i]);
    }
    cout << endl;
}

int main() {

    srand(time(NULL));
    printf("Enter matrix NxM ");

    int n = 0;
    int m = 0;

    cout << "\nN: ";
    cin >> n;
    cout << "M: ";
    cin >> m;
    
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int i_n = 0; i_n < m; i_n++) {
            matrix[i][i_n] = rand() % 100;
        }
    }

    cout << "Original matrix:" << endl;
    outing(n, m, matrix);

    int* first = new int[m];
    int* index = new int[m];

    first = firest_element(matrix, m, n, first, index);

    cout << "Before sorting: " << endl;
    outing(m, first);
    outing(m, index);
    cout << endl;

    first = sort_insert(&first[0], m, index);

    cout << "After sorting: " << endl;
    outing(m, first);
    outing(m, index);
    cout << endl;

    int** newmatrix = new int* [n];
    for (int i = 0; i < n; i++) {
        newmatrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int i_n = 0; i_n < m; i_n++) {
            newmatrix[i][i_n] = matrix[i][index[i_n]];
        }
    }

    cout << "New sorted matrix is " << endl;
    outing(n, m, newmatrix);

    delete[] first;
    delete[] index;

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
        delete[] newmatrix[i];
    }

    delete[] matrix;
    delete[] newmatrix;

    system("pause");

    return 0;
}