#include <iostream>

using namespace std;

template <typename T>
class Node {

public:
	T el;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;

	Node(T el) {
		this->el = el;
	}
};


template <typename T>
class List {

public:
	List() = default;

	List(const List<T>& other) {
		Node<T>* it = other.head;
		while (it->next != nullptr) {
			add(it->el);
			it = it->next;
		}
	}

	List<T>& operator =(List<T>& other) {
		if (this == &other) {
			return *this;
		}

		clear();

		Node<T>* it = other.head;
		while (it->next != nullptr) {
			add(it->el);
			it = it->next;
		}

		return *this;
	}

	~List() {
		clear();
	}

	void add(const T& el) {

		if (!head) {
			tail = head = new Node<T>(el);
		}
		else {
			tail->next = new Node<T>(el);
			tail->next->prev = tail;
			tail = tail->next;

		}
		size++;
	}

	bool del_el(const T& el) {

		if (!head) {
			return false;
		}

		if (head->el == el) {
			Node<T>* to_delete = head;
			head = head->next;
			delete to_delete;
			size--;
			return true;
		}

		Node<T>* it = head;
		while (it->next) {
			if (it->next->el == el) {
				Node<T>* to_delete = it->next;
				it->next = it->next->next;
				it->prev->next = it->next;
				it->next->prev = it->prev;
				delete to_delete;
				size--;
				return true;
			}
			it = it->next;
		}

		return false;
	}

	friend ostream& operator << (ostream& stream, List<T>& list) {
		Node<T>* nv = list.head;
		while (nv) {
			stream << nv->el << " ";
			nv = nv->p;
		}
		stream << endl;

		return stream;
	}

	void clear() {
		while (head) {
			auto* to_delete = head;
			head = head->next;
			delete to_delete;
		}
		_tail = nullptr;
	}

	double get_mult() const {

		double result = 1;

		Node<T>* it_head = head;
		Node<T>* it_tail = tail;

		while (it_head && it_tail) {
			result *= (it_head->el - it_tail->el);

			cout << "result = it_head - it_tail = " << it_head->el << " - " << it_tail->el << " -----> " << result << ";" << endl;

			it_head = it_head->next->next;
			it_tail = it_tail->prev->prev;
		}

		return result;
	}

private:

	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size = 0;
};
