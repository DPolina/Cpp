//No_2.2(5)

#include<iostream>
#include<time.h>

using namespace std;

void fill_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (rand() % 99) + 1;
        }
    }
}

void print_matrix(int** matrix, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]);
        }
        cout << endl << endl;
    }
}

void print_arr(int* arr, int n) {

    cout << endl << "ARR: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    srand(time(nullptr));

    int n = 0;
    cout << "N = ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    //arr[i][j]

    //int* matrix = new int [n*n];
    //arr[i*n+j]

    fill_matrix(matrix, n);
    print_matrix(matrix, n);

    int size = 2 * n - 1;

    int* arr = new int[2 * n - 1]{};
    int arr_idx = size - 1;

    for (int down = n - 1; down > 0; down--) {
        int min = INT32_MAX;
        for (int j = down, i = n - 1; j <= n - 1, i >= down; j++, i--) {
            //cout << matrix[i][j] << " ";
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        //cout << "min = " << min << endl;
        arr[arr_idx--] = min;
    }

    for (int up = n - 1; up >= 0; up--) {
        int min = INT32_MAX;
        for (int j = 0, i = up; j <= up, i >= 0; j++, i--) {
            //cout << matrix[i][j] << " ";
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        //cout << "min = " << min << endl;
        arr[arr_idx--] = min;
    }

    print_arr(arr, size);

	system("pause");

	return 0;
}