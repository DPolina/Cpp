#include<iostream>
#include<math.h>

using namespace std;

int main() /*
{
	setlocale(LC_ALL, "rus");

	int arr[10];
	int fib[30];

	cout << "Ðÿä Ôèáîíà÷÷è:  ";

	for (int i = 0; i < 30; i++) {

		if (i == 0)
			fib[i] = 0;
		else if (i == 1)
			fib[i] = 1;
		else
			fib[i] = fib[i - 1] + fib[i - 2];

		cout << fib[i] << " ";
	}

	cout << "\n" << endl;

	for (int i = 0; i < 10; i++) {

		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}

	
	int count = 0;
	int maxcount = 0;

	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 29; j++) {

			if (arr[i] == fib[j]) {

				count += 1;
				if (count > maxcount)
					maxcount = count;
			} 
		}
	}

	cout << "\nÐÿä:  " << maxcount << endl;

	system("pause");
	return 0;
} */

{
	int n;

	int seq_max = 0;
	int seq_curr = 0;

	while(cin >> n){

		int f1 = 1;
		int f2 = 1;

		while(f2<n){
			int f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}

		if(f2 == n){
			seq_curr++;
		}
		else{
			if(seq_curr > seq_max)
				seq_max = seq_curr;

			seq_curr = 0;
		}
	}

	if(seq_curr > seq_max)
		seq_max = seq_curr;

	cout << seq_max;
	system("pause");
} 