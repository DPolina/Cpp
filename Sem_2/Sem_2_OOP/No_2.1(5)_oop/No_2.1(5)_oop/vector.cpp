#include <iostream>
#include <fstream>
#include <exception>
#include <time.h>
#include "vector.h"

using namespace std;

Vector::Vector() {
	this->size = 0;
	this->arr = new int[size];
}

Vector::Vector(int isize) {
	size = isize;
	arr = new int[size]{};
}

Vector::Vector(const Vector& other) {
	size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
}

Vector::~Vector() {
	delete[] arr;
}

void Vector::set_size(int isize) {
	size = isize;
	arr = new int[size];
}

int Vector::get_size() const {
	return size;
}

void Vector::fill(int min, int max) {
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % (max - min)) + min;
	}
}

void Vector::fill(int max) {
	fill(0, max);
}

void Vector::print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int& Vector::operator[](int index) {
	return arr[index];
}

const int& Vector::operator[]  (int index) const {
	return arr[index];
}

Vector& Vector::operator++(int index) {
	arr[index]++;
	return *this;
}

void Vector::push_back(int el) {

	this->size = size + 1;
	int* arr2 = new int[this->size];
	for (int i = 0; i < size - 1; i++) {
		arr2[i] = arr[i];
	}
	delete[] arr;
	this->arr = arr2;
	this->arr[size - 1] = el;
}