#include <iostream>    // cin cout
#include <math.h>      

using namespace std;

int main() {

	double x;
	double s;
	double t;

	cout << "x = ";
	cin >> x;

	cout << "s = ";
	cin >> s;

	cout << "t = ";
	cin >> t;

	double a = pow(x, t);
	double b = pow(x, 3);
	double c = sqrt(b + 1);
	double d = c + log(s);
	double y =  a / d;

	cout << y;

	system("pause");
	return 0;
}

