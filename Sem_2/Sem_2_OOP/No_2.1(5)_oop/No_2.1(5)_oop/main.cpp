#include <iostream>
#include <fstream>
#include <time.h>

#include "vector.h"

using namespace std;


void cool_function(Vector& a) {
	a[3] = 4;
}

void another_cool_function(const Vector& a) {
	cout << a[3];
}

int main() {

	srand(time(nullptr));
	//cool_function(a);
	//another_cool_function(a);

    const int size = 10001;
    Vector a(size);
    Vector b;

    ifstream file("./numbers.txt");

    if (file.is_open()) {
        int temp = 0;
        while (file >> temp) {
            a[temp]++;
        }
    }
    //a.print();

    for (int i = 0, j = 0; i < size; i++) {
        if (a[i] > 1) {
            b.push_back(i);
        }
    }

    b.print();
    cout << endl;
    
	system("pause");

	return 0;
}