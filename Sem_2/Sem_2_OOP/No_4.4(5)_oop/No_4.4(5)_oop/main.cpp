#include <iostream>

#include "List.h"
#include "Object.h"
#include "Button.h"
#include "TextBox.h"
#include "HyperlinkLabel.h"
#include "Shape.h"
#include "Ellipse.h"
#include "Rectangle.h"

using namespace std;

int main() {

	List<Object*> list1;

	list1.add(new Shape());
	list1.add(new Button(2, 2, true, 10, 10, "Hello", "World"));
	list1.add(new Ellipse(1, 1, false, 5, 5, "Red", "Black"));

	cout << "LIST: " << endl << list1 << endl;

	List<Object*> list2 = list1;
	
	cout << "CLEAR START" << endl;
	list1.clear();
	cout << "CLEAR END" << endl;


	cout << "LIST-1: " << endl << list1 << endl << "--------------- " << endl;

	cout << "LIST-2: " << endl << list2 << endl;

	system("pause");

	return 0;
}