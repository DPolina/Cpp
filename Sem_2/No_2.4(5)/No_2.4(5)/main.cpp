//No_2.4(5)

#include <iostream>
#include<string.h>
#include<iomanip>
#include<time.h>
#include <fstream>

using namespace std;

struct Node {
	char data;
	Node* p;
};

void list_add(Node*& list, char symbol) {
    Node* node = new Node();
    node->data = symbol;
    node->p = nullptr;

    if (!list) {
        list = node;
        return;
    }

    Node* it = list;
    while (it->p) {
        it = it->p;
    }
    it->p = node;
}

void list_print(Node* list) {
    while (list) {
        cout << list->data << " ";
        list = list->p;
    }
}

bool list_contains(Node* list, char value) {
    while (list) {
        if (list->data == value) {
            return true;
        }
        list = list->p;
    }

    return false;
}

Node* list_create(const char* filename) {
    Node* list = nullptr;

    ifstream f(filename);
    while (f) {
        char s;
        f >> s;
        list_add(list, s);
    }

    return list;
}


Node* list_merge(Node* list1, Node* list2) {
    Node* list3 = nullptr;
    for (char i = '0'; i <= 'z'; i++) {

        bool contains_1 = list_contains(list1, i);
        bool contains_2 = list_contains(list2, i);
        bool contains_3 = list_contains(list3, i);

        if ((contains_1 || contains_2) && !contains_3) {
            list_add(list3, i);
        }
    }

    return list3;
}

void file_generate(const char* filename, int n) {
    ofstream out(filename);
    if (out.is_open()) {
        for (int i = 0; i < n; i++) {
            out << (char)((rand() % ('z' - '0')) + '0') << endl;
        }
    }
}

int main() {
    srand(time(nullptr));
    
    file_generate("L1.txt", 100);
    file_generate("L2.txt", 100);


    Node* L1 = list_create("L1.txt");
    Node* L2 = list_create("L2.txt");

    Node* L3 = list_merge(L1, L2);

    //
    cout << "Elements of new list are : ";
    list_print(L3);
    //

	system("pause");

	return 0;
}