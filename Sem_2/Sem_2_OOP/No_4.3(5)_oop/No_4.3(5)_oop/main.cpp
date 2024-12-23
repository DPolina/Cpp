#include <iostream>
#include <map>
#include <string>

#include "Array.h"
#include "Object.h"
#include "Button.h"
#include "TextBox.h"
#include "HyperlinkLabel.h"
#include "Shape.h"
#include "Ellipse.h"
#include "Rectangle.h"

using namespace std;

void read_file(const char* filename, Array<Object*>& a, map<string, IFactory*>& m) {
	ifstream f(filename);
	while (!f.eof()) {
		string type;
		f >> type;

		if (m.find(type) != m.end()) {
			a.push_back(m[type]->CreateObject(f));
		}
		else {
			break;
		}
	}
}

int main() {

	Array<Object*> a;

	map<string, IFactory*> m;
	m["Button"] = new ButtonFactory();
	m["HyperlinkLabel"] = new HyperlinkLabelFactory();
	m["TextBox"] = new TextBoxFactory();
	m["Shape"] = new ShapeFactory();
	m["Ellipse"] = new EllipseFactory();
	m["Rectangle"] = new RectangleFactory();
	read_file("file.txt", a, m);

	cout << "Array: " << endl << endl;
	a.print();

	cout << endl << endl << " ------------------------ " << endl << endl;

	a.clear();

	Shape shape;
	Button button;
	Ellipse ellipse;
	HyperlinkLabel link;

	a.push_back(&shape);
	a.push_back(&button);
	a.push_back(&ellipse);
	a.push_back(&link);

	cout << "Array: " << endl << endl;
	a.print();

	//a.del_element(&shape);
	//cout << "Array: " << endl << endl;
	//a.print();

	//a.clear();
	//cout << "Array: " << endl << endl;
	//a.print();


	system("pause");

	a.write("file.txt");
	return 0;
}