#include <iostream>

#include "Array.h"
#include "Object.h"
#include "Button.h"
#include "TextBox.h"
#include "HyperlinkLabel.h"
#include "Shape.h"
#include "Ellipse.h"
#include "Rectangle.h"


using namespace std;

int main() {

	Array<Object*> arr;
	Shape shape;
	Button button(3, 2, true, 5, 10, "text", "tooltiptext");
	Ellipse ellipse(1, 1, false, 3, 3, "Blue", "Black");

	arr.push_back(&shape);
	arr.push_back(&button); 
	arr.push_back(&ellipse);
	cout << "Array: " << endl << endl;
	arr.print();

	arr.del_element(&shape);
	cout << "Array: " << endl << endl;
	arr.print();

	arr.clear();
	cout << "Array: " << endl << endl;
	arr.print();

	system("pause");

	return 0;
}