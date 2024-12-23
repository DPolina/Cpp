#include <iostream>
#include<string.h>
#include<iomanip>
#include<time.h>

#include "list.h"

using namespace std;

List<char> list_merge(List<char> list1, List<char> list2, int min, int max) {
    List<char> list3;
    for (char i = min; i <= max; i++) {
        if ((list1.contains(i) || list2.contains(i)) && !list3.contains(i)) {
            list3.add(i);
        }
    }

    return list3;
}

int main() {
    srand(time(nullptr));

    List<char> list1;
    List<char> list2;

    list1.fill(20, '0', 'z');
    list2.fill(20, '0', 'z');

    cout << "list1: ";
    cout << list1;
    cout << "list2: ";
    cout << list2;

    List<char> list3 = list_merge(list1, list2, '0', 'z');
    cout << endl << "list3: ";
    cout << list3;

	system("pause");

	return 0;
}

