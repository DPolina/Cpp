#include <iostream>
#include <list>
#include <cstring>

using namespace std;

//class List {
//private:
//    class Node {
//    public:
//        string name;
//        int id;
//        Node* p_next = nullptr;
//        Node* p_prev = nullptr;
//
//        Node(string name, int id, Node* p_next = nullptr) {
//            this->name = name;
//            this->id = id;
//            this->p_next = p_next;
//        }
//    };
//    Node* head = nullptr;
//    Node* tail = nullptr;
//    int size;
//
//public:
//
//    List() {
//        head = nullptr;
//        size = 0;
//    }
//
//    void push_back(string name, unsigned int hashId) {
//
//        if (!head) {
//            tail = head = new Node(name, hashId);
//        }
//        else {
//            tail->p_next = new Node(name, hashId);
//            tail->p_next->p_prev = tail;
//            tail = tail->p_next;
//
//        }
//        size++;
//    }
//    void Print() {
//        Node* it = head;
//        while (it != nullptr) {
//            cout << it->name << "(" << it->id << ")" << " | ";
//            it = it->p_next;
//        }
//        cout << endl;
//    }
//
//    string Find(unsigned int hash) {
//        Node* it = head;
//        while (it->id != hash) {
//            it = it->p_next;
//        }
//        return it->name;
//    }
//
//};
//
//class HashTable {
//private:
//    List* arr;
//    int size;
//public:
//
//    HashTable() {
//        size = 20;
//        arr = new List[size];
//    }
//
//    void Insert(string name, string value) {
//        unsigned int hash = GetHash(name);
//        int ID = hash % size;
//        arr[ID].push_back(value, hash);
//    }
//
//    unsigned int GetHash(string name) {
//        unsigned int value = 0;
//        for (int i = 0, id = 99; i < name.size(); i++, id--) {
//            value += name.at(i) * id;
//        }
//        return value;
//    }
//
//    void Print() {
//        for (int i = 0; i < size; i++) {
//            cout << " i = " << i << " : ";
//            arr[i].Print();
//        }
//    }
//
//    string GetInfo(string name) {
//        unsigned int hash = GetHash(name);
//        int Id = hash % size;
//        return arr[Id].Find(hash);
//    }
//};

class List {
private:
    class Node {
    public:
        int value_1;
        int id;
        Node* p_next = nullptr;
        Node* p_prev = nullptr;

        Node(int value_1, int id, Node* p_next = nullptr) {
            this->value_1 = value_1;
            this->id = id;
            this->p_next = p_next;
        }
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int size;

public:

    List() {
        head = nullptr;
        size = 0;
    }

    void push_back(int value_1, unsigned int hashId) {

        if (!head) {
            tail = head = new Node(value_1, hashId);
        }
        else {
            tail->p_next = new Node(value_1, hashId);
            tail->p_next->p_prev = tail;
            tail = tail->p_next;

        }
        size++;
    }
    void Print() {
        Node* it = head;
        while (it != nullptr) {
            cout << it->value_1 << "(" << it->id << ")" << " | ";
            it = it->p_next;
        }
        cout << endl;
    }

    int Find(unsigned int hash) {
        Node* it = head;
        while (it->id != hash) {
            it = it->p_next;
        }
        return it->value_1;
    }
};

class HashTable {
private:
    List* arr;
    int size;

public:

    HashTable() {
        size = 20;
        arr = new List[size];
    }

    void Insert(int value_1, int value_2) {
        unsigned int hash = GetHash(value_1);
        //int ID = hash % size;
        int ID = value_1 % size;
        arr[ID].push_back(value_2, hash);
    }

    unsigned int GetHash(int value_1) {
        return value_1; // ???
    }

    void Print() {
        for (int i = 0; i < size; i++) {
            cout << " i = " << i << " : ";
            arr[i].Print();
        }
    }

    int GetInfo(int value_1) {
        unsigned int hash = GetHash(value_1);
        int Id = hash % size;
        return arr[Id].Find(hash);
    }
};