#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double R;
	double x;
	double y;

	cout << "R = ";
	cin >> R;

	cout << "x = ";
	cin >> x;

	cout << "y = ";
	cin >> y;

	bool i;
	double g = pow(x, 2) + pow(y, 2);

	if ((g <= R && x >= 0 && y <= 0) || (g >= R && x <= 0 && y >= 0)) {
		i = true;
	} else {
		i = false;
	}

	cout << i;
	system("pause");
	
	return 0;
}

