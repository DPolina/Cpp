#pragma once

#include <iostream>
#include <fstream>
#include "Object.h"

class TextBox : public Object {

public:

	TextBox() : Object() {}

	TextBox(int x, int y, bool visible, int width, int height, const char* color, const char* text, bool readonly) : Object(x, y, visible, width, height) {
		setColor(color);
		setText(text);
		this->Readonly = true;
	}

	TextBox(const TextBox& other) : Object(other) {
		setColor(other.Color);
		setText(other.Text);
		Readonly = other.Readonly;
	}

	~TextBox() override {
		delete[] Color;
		delete[] Text;
	}

	void setColor(const char* color) {
		delete[] Color;
		if (color) {
			Color = _strdup(color);
		}
	}

	void setText(const char* text) {
		delete[] Text;
		if (text) {
			Text = _strdup(text);
		}
	}

	void setReadonly(bool readonly) {
		this->Readonly = readonly;
	}

	const char* getColor() const {
		return Color ? Color : "";
	}

	const char* getText() const {
		return Text ? Text : "";
	}

	const bool getReadonly() const {
		return Readonly;
	}

	virtual const char* GetType() const {
		return "TextBox";
	}

	void Print(std::ostream& str) const {
		Object::Print(str);
		std::cout << "Readonly: " << getReadonly() << std::endl;
		std::cout << "Color:    " << getColor() << std::endl;
		std::cout << "Text:     " << getText() << std::endl;
	}

	TextBox(std::ifstream& file) {
		Read(file);
	}

	void Read(std::ifstream& file) override {
		Object::Read(file);
		file >> Color;
		file >> Text;
		file >> Readonly;
	}

	void Write(std::ofstream& file) override {
		Object::Write(file);
		file << " " << getColor() << " " << getText() << " " << getReadonly();
	}

private:

	char* Color = nullptr;
	char* Text = nullptr;
	bool Readonly = true;
};

class TextBoxFactory : public IFactory {
	Object* CreateObject(std::ifstream& file) override {
		return new Button(file);
	}
};