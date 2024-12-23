#pragma once

#include <iostream>
#include <fstream>
#include "Object.h"
#include "Shape.h"

class Ellipse : public Shape {

public:

	Ellipse() : Shape() {}

	Ellipse(int x, int y, bool visible, int width, int height, char* fillColor, char* borderColor) : Shape(x, y, visible, width, height, fillColor, borderColor) {}
	
	Ellipse(const Ellipse& other) : Shape(other) {
		setFillColor(other.getFillColor());
		setBorderColor(other.getBorderColor());
	}

	~Ellipse() override {}

	void Print(std::ostream& str) const {
		Shape::Print(str);
	}
};