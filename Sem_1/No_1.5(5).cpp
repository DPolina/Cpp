#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	double a, b, c, d, e, f, s, t, u;

	cout << "����: 1) ����������� ���" << endl;
	cout << "      2) ������ sx + ty + u = 0\n" << endl;

	cout << "s = ";
	cin >> s;
	cout << "t = ";
	cin >> t;
	cout << "u = ";
	cin >> u;

	cout << "\n������� �: a = ";
	cin >> a;
	cout << "           b = ";
	cin >> b;
	cout << "������� B: c = ";
	cin >> c;
	cout << "           d = ";
	cin >> d;
	cout << "������� C: e = ";
	cin >> e;
	cout << "           f = ";
	cin >> f;

	bool A_above_L = false;
	bool B_above_L = false;
	bool C_above_L = false;

	if (b + ((s * a + u) / t) > 0) {
		A_above_L = true;
	}
	if (d + ((s * c + u) / t) > 0) {
		B_above_L = true;
	}
	if (f + ((s * e + u) / t) > 0) {
		C_above_L = true;
	}

	if (A_above_L == true && B_above_L == true && C_above_L == true) {
		cout << "\n����������� ����� ���� ������ " << s << "x + " << t << "y + " << u << " = 0" << endl;
	} else if (A_above_L == false && B_above_L == false && C_above_L == false) {
		cout << "\n����������� ����� ���� ������ " << s << "x + " << t << "y + " << u << " = 0" << endl;
	} else {
		cout << "\n����������� ���������� ������ " << s << "x + " << t << "y + " << u << " = 0" << endl;
	}

	system("pause");
	return 0;
}

