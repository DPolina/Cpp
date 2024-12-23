#pragma once

#include <iostream>
#include <fstream>
#include "Object.h"

class Shape : public Object {

public:

	Shape() : Object() {}

	Shape(int x, int y, bool visible, int width, int height, const char* FillColor, const char* BorderColor) : Object(x, y, visible, width, height) {
		setFillColor(FillColor);
		setBorderColor(BorderColor);
	}

	Shape(const Shape& other) : Object(other) {}

	~Shape() override {
		delete[] FillColor;
		delete[] BorderColor;
	};

	Shape* clone() override {
		return new Shape(*this);
	}

	void setFillColor(const char* color) {
		delete[] FillColor;
		if (color) {
			FillColor = _strdup(color);
		}
	}

	void setBorderColor(const char* color) {
		delete[] BorderColor;
		if (color) {
			BorderColor = _strdup(color);
		}
	}

	const char* getFillColor() const {
		return FillColor ? FillColor : "";
	}

	const char* getBorderColor() const {
		return BorderColor ? BorderColor : "";
	}

	virtual const char* GetType() const {
		return "Shape";
	}

	void Print(std::ostream& str) const {
		Object::Print(str);
		std::cout << "FillColor:    " << getFillColor() << std::endl;
		std::cout << "BorderColor:  " << getBorderColor() << std::endl;
	}

private:

	char* FillColor = nullptr;
	char* BorderColor = nullptr;
};