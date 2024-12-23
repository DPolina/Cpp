#include <iostream>

using namespace std;

template <typename T>
class Node {

public:
	T el;
	Node<T>* p = nullptr;

	Node(T el) {
		this->el = el;
	}

	void setNext(Node* n) {
		p = n;
	}
};


template <typename T>
class List {

public:
	List() = default;

	List(const List<T>& other) {
		Node<T>* it = other.head;
		while (it->p != nullptr) {
			add(it->el);
			it = it->p;
		}
	}

	List<T>& operator =(List<T>&other){
		if (this == &other) {
			return *this;
		}

		clear();

		Node<T>* it = other.head;
		while (it->p != nullptr) {
			add(it->el);
			it = it->p;
		}

		return *this;
	}

	~List() {
		clear();
	}

	bool contains(const T& el) const {
		Node<T>* it = head;
		while (it) {
			if (it->el == el) {
				return true;
			}
			it = it->p;
		}

		return false;
	}

	void fill(int size, int min, int max) {
		clear();

		for (int i = 0; i < size; i++) {
			add((T)((rand() % (max - min)) + min));
		}
	}

	void add(const T& el) {	

		if (!head) {
			head = new Node<T>(el);
		}
		else {
			Node<T>* it = head;
			while (it->p) {
				it = it->p;
			}

			it->p = new Node<T>(el);
		}
		size++;
	}

	bool del_el(const T& el) { 

		if (!head) {
			return false;
		}

		if (head->el == el) {
			Node<T>* to_delete = head;
			head = head->p;
			delete to_delete;
			size--;
			return true;
		}

		Node<T>* it = head;
		while (it->p) {
			if (it->p->el == el) {
				Node<T>* to_delete = it->p;
				it->p = it->p->p;
				delete to_delete;
				size--;
				return true;
			}
			it = it->p;
		}

		return false;
	}

	friend ostream& operator <<(ostream& stream, List<T>& list) {
		Node<T>* nv = list.head;
		while(nv) {
			stream << nv->el << " ";
			nv = nv->p;
		}
		stream << endl;

		return stream;
	}

	void clear() {
		Node<T>* nv = nullptr;
		while (nv) {
			del_el(nv->el);
			nv = nv->p;
		}
	}

private:

	Node<T>* head = nullptr;
	int size = 0;
};
