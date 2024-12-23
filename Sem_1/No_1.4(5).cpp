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

	cout << "Координаты ладьи: l_x = ";
	cin >> l_x;

	cout << "                  l_y = ";
	cin >> l_y;

	cout << "\nКоординаты коня:  s_x = ";
	cin >> s_x;

	cout << "                  s_y = ";
	cin >> s_y;

	if (l_x == s_x || l_y == s_y) {
		cout << "\nЛадья угрожает коню.";
		U = true;
	} 
	if ((abs(l_x - s_x) == 2 && abs(l_y - s_y) == 1) || (abs(l_x - s_x) == 1 && abs(l_y - s_y) == 2)) {
		cout << "\nКонь угрожает ладье.";
		U = true;
	}
	if (U == false) {
		cout << "\nФигуры не угрожают друг другу, ";
		if (l_x == s_x || l_y == s_y) {
			cout << "oднако ладья имеет возможность напасть на коня." << endl;
		}
		else{
  		cout << "oднако ладья имеет возможность напасть на коня через клетку " << l_x << ", " << s_y << endl;
		}
	
	}

	system("pause");
	return 0;
}

