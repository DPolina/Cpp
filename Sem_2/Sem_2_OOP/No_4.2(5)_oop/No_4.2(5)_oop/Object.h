#pragma once

#include <iostream>
#include <fstream>

class Object {

public:

	Object() = default;

	Object(int x, int y, bool visible, int width, int height) : x(x), y(y), visible(visible), width(width), height(height) {};

	Object(const Object& other) {
		x = other.x;
		y = other.y;
		Visible = other.Visible;
		Width = other.Width;
		Height = other.Height;
	}

	virtual ~Object() = default;

	friend std::ostream& operator << (std::ostream& str, const Object& obj);

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	bool getVisible() {
		return Visible;
	}

	void setVisible(bool visible) {
		this->Visible = visible;
	}

	void setWidth(int width) {
		this->Width = width;
	}

	void setHeight(int height) {
		this->Height = height;
	}

	int getWidth() const {
		return Width;
	}

	int getHeight() const {
		return Height;
	}

	virtual void Print(std::ostream& str) const {
		str << "X: " << x << ",  Y: " << y << std::endl;
		str << "Visible: " << Visible << std::endl;
		str << "Width: " << Width << ",  Height: " << Height << std::endl;
	}
	
	virtual const char* GetType() const {
		return "Object";
	}

protected:

	int x = 0;
	int y = 0;
	bool Visible = false;
	int Width = 0;
	int Height = 0;
};
