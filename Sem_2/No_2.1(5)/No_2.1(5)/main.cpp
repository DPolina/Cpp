//No_2.1(5)

#include <iostream>
#include <fstream>

using namespace std;

void Print(int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 1) {
            cout << "arr[" << i << "] : " << arr[i] << endl;
        }
    }
}

int main() {

    const int size = 10001;
    int* arr = new int[size] {};
    ifstream file("./numbers.txt");
    Print(arr, size);
    if (file.is_open()) {
        int temp = 0;
        while (file >> temp) {
            arr[temp]++;
        }
    }
    Print(arr, size);

    delete[] arr;
    return 0;
}
