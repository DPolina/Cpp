#pragma once

#include <iostream>
#include <fstream>
#include "Object.h"

class Button : public Object {

public:

	Button() : Object() {}

	Button(int x, int y, bool visible, int width, int height, char* text, char* toolTipText) : Object(x, y, visible, width, height) {
		setText(text);
		setToolTipText(toolTipText);
	}

	Button(const Button& other) : Object(other) {
		setText(other.Text);
		setToolTipText(other.ToolTipText);
	}

	~Button() override {
		delete[] Text;
		delete[] ToolTipText;
	}

	void setText(const char* text) {
		delete[] Text;
		if (text) {
			Text = _strdup(text);
		}
	}

	void setToolTipText(const char* text) {
		delete[] ToolTipText;
		if (text) {
			ToolTipText = _strdup(text);
		}
	}

	const char* getText() const {
		return Text;
	}

	const char* getToolTipText() const {
		return ToolTipText;
	}

	virtual const char* GetType() const {
		return "Button";
	}

	void Print(std::ostream& str) const {
		Object::Print(str);
		std::cout << "Text:  " << Text << std::endl;
		std::cout << "ToolTipText:  " << ToolTipText << std::endl;
	}

private:

	char* Text = nullptr;
	char* ToolTipText = nullptr;
};