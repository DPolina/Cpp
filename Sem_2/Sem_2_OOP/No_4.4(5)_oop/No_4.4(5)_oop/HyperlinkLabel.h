#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Object.h"

class HyperlinkLabel : public Object {

public:

	HyperlinkLabel() : Object() {}

	HyperlinkLabel(int x, int y, bool visible, int width, int height, const char* url, const char* color, const char* text) : Object(x, y, visible, width, height) {
		setURL(url);
		setColor(color);
		setText(text);
	}

	HyperlinkLabel(const HyperlinkLabel& other) : Object(other) {
		setURL(other.URL);
		setColor(other.Color);
		setText(other.Text);
	}

	~HyperlinkLabel() override {
		delete[] URL;
		delete[] Color;
	}

	HyperlinkLabel* clone() override {
		return new HyperlinkLabel(*this);
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
		return URL ? URL : "";
	}

	const char* getColor() const {
		return Color ? Color : "";
	}

	const char* getText() const {
		return Text ? Text : "";
	}

	virtual const char* GetType() const {
		return "HyperlinkLabel";
	}

	void Print(std::ostream& str) const {
		Object::Print(str);
		std::cout << "URL:    " << getURL() << std::endl;
		std::cout << "Color:  " << getColor() << std::endl;
		std::cout << "Text:   " << getText() << std::endl;
	}

private:

	char* URL = nullptr;
	char* Color = nullptr;
	char* Text = nullptr;
};