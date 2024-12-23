#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <iomanip>
#include <cassert>
#include <fstream>

using namespace std;

struct Student {
    char FullName[32]{};
    char gender[8]{};
    double mark;
    int age;
    int course;

    void read(ifstream& r) {
        r >> FullName;
        r >> gender;
        r >> mark;
        r >> age;
        r >> course;
    }

    void write(ofstream& r) {
        r << FullName << " ";
        r << gender << " ";
        r << mark << " ";
        r << age << " ";
        r << course << " ";
        r << endl;
    }
};

//static_assert(std::is_trivially_copyable<Student>());

struct Node {
    Student s;
    Node* p;
};

void Print(Node* list) {
    printf("%-26s%10s%10s%10s%11s\n\n", "Full name", "Gender", "Age", "Course", "Mark");
    while (list) {
        printf("%-30s%-13s%-10d%-10d%-10.1f\n", list->s.FullName, list->s.gender,
            list->s.age, list->s.course, list->s.mark);
        list = list->p;
    }
    cout << endl << endl;
}

void find_space(Node* list, const char* Name, Node*& ppv) {
    Node* pv = list;
    ppv = list;
    while (pv && strcmp(pv->s.FullName, Name) <= 0) {
        ppv = pv;
        pv = pv->p;
    }
}

void add(Node*& list, const char* Name, const char* gender, int age, int course, double mark, int& size) {
    Node* ppv = NULL;
    Node* new_list = new Node;
    strcpy(new_list->s.FullName, Name);
    strcpy(new_list->s.gender, gender);
    new_list->s.age = age;
    new_list->s.course = course;
    new_list->s.mark = mark;
    new_list->p = NULL;
    if (!list) {
        list = new_list;
    }
    else {
        if (list->s.FullName >= Name) {
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
        if (list->s.FullName >= new_list->s.FullName) {
            new_list->p = list;
            list = new_list;
        }
        else {
            find_space(list, new_list->s.FullName, ppv);
            new_list->p = ppv->p;
            ppv->p = new_list;
        }
    }
}

int input(string str, int min, int max) {

    int n = 0;

    do {
        cout << str << ": ";
        cin >> n;
        if (cin.fail()) {
            cout << "Invalid value! " << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (n >= min && n <= max) {
            break;
        }
        else {
            cout << "Invalid value! " << endl;
        }
    } while (true);

    return n;
}

Node* read_list_from_file(const char* filename) {

    Node* list = NULL;

    //1. READ FROM FILE
    ifstream in(filename);
    while (in) {
        Node* n = new Node{};
        n->s.read(in);

        if (!in) {
            break;
        }

        add(list, n);
    }

    return list;
}

int main() {

    Node* list1 = NULL;
    int size = 0;

    add(list1, "Michelangelo",             "male",   18, 1, 5.0,  size);
    add(list1, "Oscar_Claude_Monet",       "male",   19, 2, 3.3,  size);
    add(list1, "Frida_Kahlo",              "female", 17, 1, 6.3,  size);
    add(list1, "Vincent_Williem_van_Gogh", "male",   20, 4, 1.3,  size);
    add(list1, "Henri_Matisse",            "male",   19, 2, 4.1,  size);
    add(list1, "Leonardo_da_Vinci",        "male",   18, 3, 10.0, size);
    add(list1, "Salvador_Dali",            "male",   18, 2, 2.3,  size);
    add(list1, "Pablo_Ruiz_Picasso",       "male",   20, 4, 8.3,  size);

    ofstream out("./students_input.txt");

    Node* pv1 = list1;
    while (pv1) {
        pv1->s.write(out);
        pv1 = pv1->p;
    }
    out.close();

    //1. READ FORM FILE
    Node* list = read_list_from_file("students_input.txt");

    //2. PRINT
    cout << "LIST: \n\n";
    Print(list);
    
    //3. ENTER COURSE
    int course = input("COURSE", 1, 4);
    cout << endl;
    
    //4. FILTER AND OUTPUT
    ofstream out2("./students_output.txt");

    Node* pv = list;
    while (pv) {
        if (pv->s.course == course && out) {
            pv->s.write(out2);
        }
        pv = pv->p;
    }
    out2.close();

    //5. READ AGGAIN
    Node* list2 = read_list_from_file("students_output.txt");
    Print(list2);
    
    system("pause");

    return 0;
}