#pragma once

#include <iostream>
#include <fstream>
#include "Object.h"

class TextBox : public Object {

public:

	TextBox() : Object() {}

	TextBox(int x, int y, bool visible, int width, int height, char* color, char* text, bool readonly) : Object(x, y, visible, width, height) {
		setColor(color);
		setText(text);
		setReadonly(readonly);
	}

	TextBox(const TextBox& other) : Object(other) {
		setColor(other.getColor());
		setText(other.getText());
		setReadonly(other.getReadonly());
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
		return Color;
	}

	const char* getText() const {
		return Text;
	}

	const bool getReadonly() const {
		return Readonly;
	}

	virtual const char* GetType() const {
		return "TextBox";
	}

	void Print(std::ostream& str) const {
		Object::Print(str);
		std::cout << "Readonly: " << Readonly << std::endl;
		std::cout << "Color:    " << Color << std::endl;
		std::cout << "Text:     " << Text << std::endl;
	}

private:

	char* Color = nullptr;
	char* Text = nullptr;
	bool Readonly = true;
};