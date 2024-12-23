#include <iostream>
#include <math.h>

#include "complex.h"

using namespace std;

Complex::Complex() {
	r = 0;
	fi = 0;
}

Complex::Complex(int r, int fi) {
	this->r = r;
	this->fi = fi;
}

Complex::Complex(const Complex& other) {
	this->r = other.r;
	this->fi = other.fi;
}

// x + yi = (r cos θ) + (r sin θ)i = r(cos θ + isin θ)

Complex Complex::operator+(const Complex& other) { // z1 + z2 = (a + bi) + (c + di) = (a + c) + (b + d)i

	Complex result;

	double x_1 = this->r * cos(this->fi); // a
	double y_1 = this->r * sin(this->fi); // b
	double x_2 = other.r * cos(other.fi); // c
	double y_2 = other.r * sin(other.fi); // d

	double new_x = x_1 + x_2; // a + c
	double new_y = y_1 + y_2; // b + d

	result.r = ::sqrt(::pow(new_x, 2) + ::pow(new_y, 2));
	result.fi = (new_y) / (new_x);
	return result;
}

Complex Complex::operator-(const Complex& other) { // z1 - z2 = (a + bi) - (c + di) = (a - c) + (b - d)i

	Complex result;

	double x_1 = this->r * cos(this->fi); // a
	double y_1 = this->r * sin(this->fi); // b
	double x_2 = other.r * cos(other.fi); // c
	double y_2 = other.r * sin(other.fi); // d

	double new_x = x_1 - x_2; // a - c
	double new_y = y_1 - y_2; // b - d

	result.r = ::sqrt(::pow(new_x, 2) + ::pow(new_y, 2));
	result.fi = atan((new_y) / (new_x));
	return result;
}

Complex Complex::operator*(const Complex& other) { // z1 * z2 = (a + bi) * (c + di) = (ac - bd) + (ad + cb)i

	Complex result;

	double x_1 = this->r * cos(this->fi); // a
	double y_1 = this->r * sin(this->fi); // b
	double x_2 = other.r * cos(other.fi); // c
	double y_2 = other.r * sin(other.fi); // d

	double new_x = x_1 * x_2 - y_1 * y_2; // (ac - bd)
	double new_y = x_1 * y_2 + x_2 * y_1; // (ad + cb)

	result.r = ::sqrt(::pow(new_x, 2) + ::pow(new_y, 2));
	result.fi = atan((new_y) / (new_x));
	return result;
}

Complex Complex::operator/(const Complex& other) { // z1 / z2 = (ac + bd)/(c^2 + d^2) + (cb - ad)/(c^2 + d^2)

	Complex result;

	double x_1 = this->r * cos(this->fi); // a
	double y_1 = this->r * sin(this->fi); // b
	double x_2 = other.r * cos(other.fi); // c
	double y_2 = other.r * sin(other.fi); // d

	double new_x = (x_1 * x_2 + y_1 * y_2) / (::pow(x_2, 2) + ::pow(y_2, 2)); // (ac + bd)/(c^2 + d^2)
	double new_y = (x_2 * y_1 - x_1 * y_2) / (::pow(x_2, 2) + ::pow(y_2, 2)); // (cb - ad)/(c^2 + d^2)

	result.r = ::sqrt(::pow(new_x, 2) + ::pow(new_y, 2));
	result.fi = atan((new_y) / (new_x));
	return result;
}

Complex Complex::sqrt() {

	return pow(0.5);
}

Complex Complex::pow(double k) {
	Complex result;

	this->r = ::pow(r, k);
	this->fi = k * fi;

	return result;
}
