//N0_1.6(5)

#include "MergeSort.hpp"

using namespace std;

template <typename T>
void Entering(T* array, int isize) {
    cout << "Enter your elements: ";
    for (int i = 0; i < isize; i++) {
        T value;
        cin >> value;
        array[i] = value;
    }
}

void Entering(char** array, int isize) {
    cout << "Enter your elements: ";
    for (int i = 0; i < isize; i++) {
        cin.getline(array[i], isize + 10);
        array[i][strlen(array[i]) + 1] = '\0';
    }
}

template <typename T>
void Print(T* array, int isize) {
    for (int i = 0; i < isize; i++) {
        cout << array[i] << "   ";
    }
    cout << endl;
}

void Print(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int i_n = 0; i_n < strlen(arr[i]); i_n++) {
            cout << arr[i][i_n];
        }
        cout << " ";
    }
    cout << endl;
}

template <typename T>
void Work(T array, int isize) {
    Entering(array, isize);
    Print(array, isize);
    MergeSort(array, 0, isize - 1);
    Print(array, isize);
}

int main() {
    int isize = 0;
    cout << "Enter size of array: ";
    cin >> isize;

    short mark = 0;
    cout << "0 for int, 1 for double, 2 for chars, 3 for strings: ";
    cin >> mark;

    switch (mark) {
    case(0): {
        int* array = new int[isize];
        Work(array, isize);

        delete[] array;
        break;
    }
    case(1): {
        double* array = new double[isize];
        Work(array, isize);

        delete[] array;
        break;
    }
    case(2): {
        char* array = new char[isize];
        Work(array, isize);

        delete[] array;
        break;
    }
    case(3): {
        char** array = new char* [isize];
        for (int i = 0; i < isize; i++) {
            array[i] = new char[isize];
        }
        Work(array, isize);

        for (int i = 0; i < isize; i++) {
            delete[] array[i];
        }
        delete[] array;
        break;
    }
    default: {
        cout << "Try to read!";
    }
    }

    return 0;
}
