#include<iostream>
#include<math.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	int n = 0;
	cout << "n = ";
	cin >> n;

	if (n < 2)
		cout << "-" << endl;

	int count = 0; // счтает простые числа

	for (int i = 0; i <= n; i+=10) { 
		int prost = 0;
		int prost_arr[10];

		for (int j = 0; j < 10; j++) { 
			int num = i + j;
					
			if (num < 2){
				continue;
			}
			if (num > n){
				break;
			}

			bool is_prime = true;
			if (num > 2){
				for (int k = 2; k <= sqrt(double(num)); k++) {
					if (num % k == 0) {
						is_prime = false;
						break;
					}
				}
			}

			if (is_prime) {
				prost_arr[prost++] = num;
			}

		}

		if(prost == 4){
			for(int w = 0; w < prost; w++){
				cout << prost_arr[w] << " ";
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}

