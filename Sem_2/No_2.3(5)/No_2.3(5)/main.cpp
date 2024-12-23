//No_2.3(5)

#include <iostream>
#include <string.h>
#include <iomanip>
#include <cassert>
using namespace std;

struct Node {

    string FullName;
    string birtday;
    short course;
    double mark;
    Node* p;
};

void Print(Node* list) {
    printf("%16s%16s%8s%8s\n\n", "FullName", "birtday", "course", "mark");
    while (list) {
        cout << setw(16) << list->FullName;
        cout << setw(16) << list->birtday;
        cout << setw(8) << list->course;
        cout << setw(8) << list->mark;
        list = list->p;
        cout << endl;
    }
    printf("\n\n");
}

void find_space(Node* list, string Name, Node*& ppv) {
    Node* pv = list;
    ppv = list;
    while (pv && pv->FullName <= Name) {
        ppv = pv; // remember last element
        pv = pv->p;
    }
}

void add(Node*& list, string Name, string birtday, int coures, double mark, int& size) {
    Node* ppv = NULL;
    Node* new_list = new Node;
    new_list->FullName = Name;
    new_list->birtday = birtday;
    new_list->course = coures;
    new_list->mark = mark;
    new_list->p = NULL;
    if (!list) {
        list = new_list;
    }
    else {
        if (list->FullName >= Name) {
            new_list->p = list;
            list = new_list;
        }
        else {
            find_space(list, Name, ppv);
            new_list->p = ppv->p;
            ppv->p = new_list;
        }
    }
    size++;
}

void add(Node*& list, Node* new_list) {
    Node* ppv = NULL;
    new_list->p = NULL;
    if (!list) {
        list = new_list;
    }
    else {
        if (list->FullName >= new_list->FullName) {
            new_list->p = list;
            list = new_list;
        }
        else {
            find_space(list, new_list->FullName, ppv);
            new_list->p = ppv->p;
            ppv->p = new_list;
        }
    }
}

bool find_eq(Node* list, Node*& ppv, Node*& course, int target = 4) {
    Node* pv = list;
    while (pv) {
        if (pv->course == target) {
            return true;
        }
        ppv = pv;
        pv = pv->p;
    }

    return false;
}

void remove(Node*& list, Node*& course, int& totalFoolishNum, int& actualFoolishNum, int target) {
    Node* pv = nullptr;
    Node* ppv = nullptr;

    while (find_eq(list, ppv, course, target)) {

        if (!ppv) {

            pv = list;
            list = list->p;
        }
        else {
            pv = ppv->p;
            ppv->p = pv->p;
        }
        add(course, pv);
    }
}

int main() {

    Node* list = NULL;
    Node* foolish = NULL;
    Node* prev;
    int totalFoolishNum = 0;
    int size = 0;
    int actualFoolishNum = 0;

    add(list, "Fitz Nobody", "23.06.2022", 4, 5.0, size);
    add(list, "Gayl River", "22.11.2021", 3, 3.3, size);
    add(list, "Dara River", "12.02.1999", 2, 6.3, size);
    add(list, "Gelicia Aubelts", "21.06.1941", 1, 1.3, size);
    add(list, "Maxim Galton", "09.05.1945", 2, 4.1, size);
    add(list, "Mark Dine", "04.09.1983", 6, 10.0, size);
    add(list, "Vilen Gilton", "01.06.1961", 1, 2.3, size);
    add(list, "Gospodin Past", "02.10.2000", 1, 8.3, size);


    cout << "Original list: \n";
    Print(list);

    int course = 0;
    cout << " Enter course: ";
    cin >> course;

    remove(list, foolish, totalFoolishNum, actualFoolishNum, course);
    cout << "Students of the other cources : \n";
    Print(list);
   cout << "Students of the " << course << " course are: \n";
    Print(foolish);
    cout << "Enter Full students name: ";
    string tempName;
    cin >> tempName;
    cout << "Enter students birtday: ";
    string tempBD;
    cin >> tempBD;
    cout << "Enter students course: ";
    int tempCourse;
    cin >> tempCourse;
    cout << "Enter student's mark: ";
    double tempMark;
    cin >> tempMark;
    add(list, tempName, tempBD, tempCourse, tempMark, size);
    cout << "Updated students list members: " << endl;
    Print(list);

    system("pause");
    return 0;
}