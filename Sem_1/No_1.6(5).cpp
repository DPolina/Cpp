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
	cout << "\n 0-й бит:  " << (n & 1) << endl;
	cout << " 7-й бит:  " << ((n >> 7) & 1) << endl;
	cout << "14-й бит:  " << ((n >> 14) & 1) << endl;
	cout << "\nИнвертрованный 7-й бит:  " << (n ^ (1 << 7)) << endl;
	cout << "Инвертрованный 8-й бит:  " << (((n >> 8) & 1) ^ 1) << endl;

	system("pause");
	return 0;
}

