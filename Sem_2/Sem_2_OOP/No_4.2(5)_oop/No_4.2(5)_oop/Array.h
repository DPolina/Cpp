#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

template<typename T>
class Array {

public:

	Array() = default;

	Array(int isize) {
		size = isize;
		arr = new int[size] {};
	}

	Array(const Array& other) {
		size = other.size;
		arr = new T[size];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}

	Array(Array&& other) {
		size = other.size;
		other.size = 0;

		arr = other.arr;
		other.arr = nullptr;
	}

	~Array() {
		clear();
	}

	Array& operator= (const Array& other) {
		if (this != &other) {
			clear();
			
			size = other.size;
			arr = new T[size];
			for (int i = 0; i < size; i++) {
				arr[i] = other.arr[i];
			}
		}

		return *this;
	}

	Array& operator= (Array&& other) {
		if (this != &other) {
			clear();

			size = other.size;
			other.size = 0;

			arr = other.arr;
			other.arr = nullptr;
		}

		return *this;
	}

	void set_size(int size_new) {
		if (size == size_new) {
			return;
		}

		T* arr_new = new T[size_new]{};
		if (arr) {
			for (int i = 0; i < min(size,size_new); i++) {
				arr_new[i] = arr[i];
			}
		}
		
		clear();
		arr = arr_new;
		size = size_new;
	}

	int get_size() const {
		return size;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << *arr[i] << endl;
		}
	}


	T& operator[](int index) {
		return arr[index];
	}

	const T& operator[] (int index) const {
		return arr[index];
	}

	void push_back(T el) {
		set_size(get_size() + 1);
		this->arr[size-1] = el;
	}

	void del_element(T el) {
		int pos = -1;
		for (int i = 0; i < size; i++) {
			if (arr[i] == el) {
				pos = i;
				break;
			}
		}

		if (pos < 0) {
			return;
		}

		T* arr2 = new T[this->size-1];
		for (int i = 0; i < pos; i++) {
			arr2[i] = arr[i];
		}
		for (int i = pos + 1; i < size; i++) {
			arr2[i - 1] = arr[i];
		}

		delete[] arr;
		arr = arr2;
		size--;
	}

	void clear() {
		delete[] arr;
		arr = nullptr;
		size = 0;
	}

private:

	int size = 0;
	T* arr = nullptr;
};