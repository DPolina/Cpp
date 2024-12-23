//No_2.6(5)

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

struct Node {
    double data;
    Node* next;
    Node* prev;

    Node(double data, Node* prev = nullptr, Node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
};

void add(List& list, double value) {
    if (!list.head) {
        list.tail = new Node(value);
        list.head = list.tail;
        return;
    }

    list.tail->next = new Node(value, list.tail);
    list.tail = list.tail->next;
}

void clear(List& list) {
    Node* it = list.head;

    while (it) {
        Node* temp = it;
        it = it->next;

        delete temp;
    }

    list.head = nullptr;
    list.tail = nullptr;
}

double getMult(List& list) {
    double result = 1;

    Node* it_head = list.head;
    Node* it_tail = list.tail;

    while (it_head && it_tail) {
        result *= (it_head->data - it_tail->data);
        
        cout << "result = it_head - it_tail = " << it_head << " - " << it_tail << " = " << result << ";" << endl;

        it_head = it_head->next->next;
        it_tail = it_tail->prev->prev;
    }

    return result;
}

int main() {

    List list{};

    int n = 0;
    cout << "Enter n: ";
    cin >> n;    
    for (int i = 0; i < 2 * n; i++) {
        double value = 0;
        cin >> value;
        add(list, value);
    }

    double mult = getMult(list);
    cout << "\nMULT = " << mult << endl;
    
    clear(list);

    system("pause");
    return 0;
}