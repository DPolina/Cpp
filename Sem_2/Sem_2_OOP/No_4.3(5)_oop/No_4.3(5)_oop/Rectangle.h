#pragma once

#include <iostream>
#include <fstream>
#include "Shape.h"

class Rectangle : public Shape {

public:

	Rectangle() : Shape() {}

	Rectangle(int x, int y, bool visible, int width, int height, const char* fillColor, const char* borderColor) : Shape(x, y, visible, width, height, fillColor, borderColor) {}

	Rectangle(const Rectangle& other) : Shape(other) {
	}

	~Rectangle() override {}

	void Print(std::ostream& str) const {
		Shape::Print(str);
	}

	Rectangle(std::ifstream& file) {
		Read(file);
	}
};

class RectangleFactory : public IFactory {
public:
	Object* CreateObject(std::ifstream& file) override {
		return new Button(file);
	}
};