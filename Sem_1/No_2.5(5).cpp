#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int k = 0;
	int num = 0;
	int len_sum = 0;

	cout << "k = ";
	cin >> k;

	while (true) {

		int len_num = 0;
		
		num++;

		int n = num;
		while (n) {
			n /= 10;
			len_num++;
		}

		cout << "len_num = " << len_num << "  num = " << num << endl;

		len_sum += len_num;

		if (len_sum < k) {
			continue;
		} else if (len_sum > k) {
			cout << num / (int)pow(10., len_num - (len_sum-k)) << endl;
			break;
		} else {
			if (num < 10)
				cout << num << endl;
			else
				cout << num % (int)pow(10., len_num - (len_sum-k)) << endl;
			break;
		}

	}


	system("pause");
	return 0;
}

