#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x1;
	double x2;
	double x3;
	double x4;
	double num = 0;

	cout << "x1 = ";
	cin >> x1;

	cout << "x2 = ";
	cin >> x2;

	cout << "x3 = ";
	cin >> x3;

	cout << "x4 = ";
	cin >> x4;

	if (x2 > x1) {
		num = x1;
		x1 = x2;
		x2 = num;
	}

	if (x2 > x3) {
		num = x2;
		x2 = x3;
		x3 = num;
	}

	if (x3 < x4) {
		num = x3;
		x3 = x4;
		x4 = num;
	}

	cout << x1 << " >= " << x2 << " < " << x3 << " >= " << x4;

	system("pause");
	return 0;
}

