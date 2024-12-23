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
		visible = other.visible;
		width = other.width;
		height = other.height;
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

	bool Visible() {
		return visible;
	}

	void setWidth(int width) {
		this->width = width;
	}

	void setHeight(int height) {
		this->height = height;
	}

	int getWidth() const {
		return width;
	}

	int getHeight() const {
		return height;
	}

	virtual void Print(std::ostream& str) const {
		str << "X: " << x << ",  Y: " << y << std::endl;
		str << "Visible: " << visible << std::endl;
		str << "Width: " << width << ",  Height: " << height << std::endl;
	}
	
	virtual const char* GetType() const {
		return "Object";
	}

	Object(std::ifstream& file) {
		Read(file);
	}

	virtual void Read(std::ifstream& file) {
		file >> x;
		file >> y;
		file >> visible;
		file >> width;
		file >> height;
	}

	virtual void Write(std::ofstream& file) {
		file << GetType() << " " << x << " " << y << " " << visible << " " << width << " " << height;
	}

protected:

	int x = 0;
	int y = 0;
	bool visible = false;
	int width = 0;
	int height = 0;
};

class IFactory {
public:
	virtual ~IFactory() = default;

	virtual Object* CreateObject(std::ifstream& file) = 0;
};
