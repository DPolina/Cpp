//#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(0));
	unsigned short int n = rand();

	cout << "n = " << n << endl;
	cout << "\n 0-� ���:  " << (n & 1) << endl;
	cout << " 7-� ���:  " << ((n >> 7) & 1) << endl;
	cout << "14-� ���:  " << ((n >> 14) & 1) << endl;
	cout << "\n�������������� 7-� ���:  " << (n ^ (1 << 7)) << endl;
	cout << "�������������� 8-� ���:  " << (((n >> 8) & 1) ^ 1) << endl;

	system("pause");
	return 0;
}

