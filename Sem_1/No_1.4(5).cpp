#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int l_x;
	int l_y;
	int s_x; 
	int s_y;
	bool U = false;

	cout << "���������� �����: l_x = ";
	cin >> l_x;

	cout << "                  l_y = ";
	cin >> l_y;

	cout << "\n���������� ����:  s_x = ";
	cin >> s_x;

	cout << "                  s_y = ";
	cin >> s_y;

	if (l_x == s_x || l_y == s_y) {
		cout << "\n����� �������� ����.";
		U = true;
	} 
	if ((abs(l_x - s_x) == 2 && abs(l_y - s_y) == 1) || (abs(l_x - s_x) == 1 && abs(l_y - s_y) == 2)) {
		cout << "\n���� �������� �����.";
		U = true;
	}
	if (U == false) {
		cout << "\n������ �� �������� ���� �����, ";
		if (l_x == s_x || l_y == s_y) {
			cout << "o����� ����� ����� ����������� ������� �� ����." << endl;
		}
		else{
  		cout << "o����� ����� ����� ����������� ������� �� ���� ����� ������ " << l_x << ", " << s_y << endl;
		}
	
	}

	system("pause");
	return 0;
}

