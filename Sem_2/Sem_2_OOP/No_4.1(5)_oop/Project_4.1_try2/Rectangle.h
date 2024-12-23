#pragma once

#include <iostream>
#include <fstream>

#include "Shape.h"

class Rectangle : public Shape {

public:

	Rectangle() : Shape() {}

	Rectangle(int x, int y, bool visible, int width, int height, char* fillColor, char* borderColor) : Shape(x, y, visible, width, height, fillColor, borderColor) {}

	Rectangle(const Rectangle& other) : Shape(other) {
	}

	~Rectangle() override {}

	virtual const char* GetType() const {
		return "Rectangle";
	}
};