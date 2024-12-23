#pragma once

#include <iostream>
#include <fstream>
#include "Shape.h"

class Ellipse : public Shape {

public:

	Ellipse() : Shape() {}

	Ellipse(int x, int y, bool visible, int width, int height, const char* fillColor, const char* borderColor) : Shape(x, y, visible, width, height, fillColor, borderColor) {}
	
	Ellipse(const Ellipse& other) : Shape(other) {}

	~Ellipse() override {}

	Ellipse* clone() override {
		return new Ellipse(*this);
	}

	void Print(std::ostream& str) const {
		Shape::Print(str);
	}

	virtual const char* GetType() const {
		return "Ellipse";
	}
};