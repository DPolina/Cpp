#pragma once

#include <iostream>
#include <fstream>
#include "Object.h"

class Shape : public Object {

public:

	Shape() : Object() {}

	Shape(int x, int y, bool visible, int width, int height, char* FillColor, char* BorderColor) : Object(x, y, visible, width, height) {
		setFillColor(FillColor);
		setBorderColor(BorderColor);
	}

	Shape(const Shape& other) : Object(other) {
		setFillColor(other.getFillColor());
		setBorderColor(other.getBorderColor());
	}

	~Shape() override {
		delete[] FillColor;
		delete[] BorderColor;
	};

	void setFillColor(const char* color) {
		delete[] FillColor;
		if (color) {
			FillColor = _strdup(color);
		}
	}

	void setBorderColor(const char* color) {
		delete[] BorderColor;
		if (color) {
			strcpy(BorderColor, color);
		}
	}

	const char* getFillColor() const {
		return FillColor;
	}

	const char* getBorderColor() const {
		return BorderColor;
	}

	virtual const char* GetType() const {
		return "Shape";
	}

	void Print(std::ostream& str) const {
		Object::Print(str);
		std::cout << "FillColor:    " << FillColor << std::endl;
		std::cout << "BorderColor:  " << BorderColor << std::endl;
	}

private:

	char* FillColor = nullptr;
	char* BorderColor = nullptr;
};