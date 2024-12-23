#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Object.h"
#include "Shape.h"

class Rectangle : public Shape {

public:

	Rectangle() : Shape() {}

	Rectangle(int x, int y, bool visible, int width, int height, char* fillColor, char* borderColor) : Shape(x, y, visible, width, height, fillColor, borderColor) {}

	Rectangle(const Rectangle& other) : Shape(other) {
		setFillColor(other.getFillColor());
		setBorderColor(other.getBorderColor());
	}

	~Rectangle() override {}

	void Print(std::ostream& str) const {
		Shape::Print(str);
	}
};