#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Shape.h"

class Rectangle : public Shape {

public:

	Rectangle() : Shape() {}

	Rectangle(int x, int y, bool visible, int width, int height, const char* fillColor, const char* borderColor) : Shape(x, y, visible, width, height, fillColor, borderColor) {}

	Rectangle(const Rectangle& other) : Shape(other) {}

	~Rectangle() override {}

	Rectangle* clone() override {
		return new Rectangle(*this);
	}

	void Print(std::ostream& str) const {
		Shape::Print(str);
	}
};