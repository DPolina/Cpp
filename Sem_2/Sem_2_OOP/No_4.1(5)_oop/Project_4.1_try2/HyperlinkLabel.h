#pragma once

#include <iostream>
#include <fstream>
#include "Object.h"

class HyperlinkLabel : public Object {

public:

	HyperlinkLabel() : Object() {}

	HyperlinkLabel(int x, int y, bool visible, int width, int height, char* url, char* color, char* text) : Object(x, y, visible, width, height) {
		setURL(url);
		setColor(color);
		setText(text);
	}

	HyperlinkLabel(const HyperlinkLabel& other) : Object(other) {
		setURL(other.getURL());
		setColor(other.getColor());
		setText(other.getText());
	}

	~HyperlinkLabel() override {
		delete[] URL;
		delete[] Color;
	}

	void setURL(const char* url) {
		delete[] URL;
		if (url) {
			URL = _strdup(url);
		}
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

	const char* getURL() const {
		return URL;
	}

	const char* getColor() const {
		return Color;
	}

	const char* getText() const {
		return Text;
	}

	virtual const char* GetType() const {
		return "HyperlinkLabel";
	}

	void Print(std::ostream& str) const {
		Object::Print(str);
		std::cout << "URL:    " << URL << std::endl;
		std::cout << "Color:  " << Color << std::endl;
		std::cout << "Text:   " << Text << std::endl;
	}

private:

	char* URL = nullptr;
	char* Color = nullptr;
	char* Text = nullptr;
};