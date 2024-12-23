//No_1.1(5)

#include<iostream>

using namespace std;

enum direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

void print_matrix(int m, int n, int** matrix) {
    for (int i = 0; i < m; i++) {
        for (int i_m = 0; i_m < n; i_m++) {
            printf("%4d ", matrix[i][i_m]);
        }
        cout << endl;
    }
    cout << endl << endl;
}

void fill_matrix(int** matrix, int m, int n) {

    int num = 1;
    bool run = true;

    int y = m - 1; // начальная y
    int x = 0; // начальная x
    matrix[y][x] = num++;

    direction dir = UP;

    while (num <= n * m) {

        switch (dir) {
        case UP:
            y--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        }

        if (y < 0 || y == m || x == n || x < 0 || matrix[y][x] != 0) {
            switch (dir) {
            case UP:
                y++;
                break;
            case RIGHT:
                x--;
                break;
            case DOWN:
                y--;
                break;
            case LEFT:
                x++;
                break;
            } // шаг назад
            dir = direction((dir + 1) % 4); // поменять направление
            continue;
        }

        matrix[y][x] = num++;

        print_matrix(m, n, matrix);
    }
}

int main() {

    printf("Enter matrix MxN \n");

    int m = 0;
    int n = 0;

    cout << "\nM: "; 
    cin >> m; // y
    cout << "N: ";
    cin >> n; // x

    int** matrix = new int* [m];
    for (int y = 0; y < m; y++) {
        matrix[y] = new int[n];
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            matrix[y][x] = 0;
        }
    }

    fill_matrix(matrix, m, n);
    print_matrix(m, n, matrix);

	system("pause");

	return 0;
}