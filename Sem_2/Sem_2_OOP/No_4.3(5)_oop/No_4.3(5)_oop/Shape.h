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
			BorderColor = _strdup(color);
		}
	}

	const char* getFillColor() const {
		return FillColor ? FillColor : "none";
	}

	const char* getBorderColor() const {
		return BorderColor ? BorderColor : "none";
	}

	virtual const char* GetType() const {
		return "Shape";
	}

	void Print(std::ostream& str) const {
		Object::Print(str);
		std::cout << "FillColor:    " << getFillColor() << std::endl;
		std::cout << "BorderColor:  " << getBorderColor() << std::endl;
	}

	Shape(std::ifstream& file) {
		Read(file);
	}

	void Read(std::ifstream& file) override {
		Object::Read(file);
		file >> FillColor;
		file >> BorderColor;
	}

	void Write(std::ofstream& file) override {
		Object::Write(file);
		file << " " << getFillColor() << " " << getBorderColor();
	}

private:

	char* FillColor = nullptr;
	char* BorderColor = nullptr;
};

class ShapeFactory : public IFactory {
public:
	Object* CreateObject(std::ifstream& file) override {
		return new Button(file);
	}
};
