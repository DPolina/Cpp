#include <cstring>
#include <iostream>

using namespace std;

int main() {

	const int MAX = 100;

	char str[MAX] = {0};
	cout << "Enter text: ";
	cin.getline(str, MAX);

    int to_del[256] = { 0 };
	//index -- letter
	//value -- count
    //to_del['a']++
	//if(to_del['a'] == 2

	int length = strlen(str);
	int index = 0;

	for (int i = 0; i < length; i++) {
		char letter = str[i];
		to_del[letter]++;
	}

	for (int i = 0; i < length; i++) {
		char letter = str[i];
		if(to_del[letter] == 2){
			for (int j = i; j < length; j++) {
				str[j] = str[j + 1];
			}
			
		    i--;
		    length--;
		}

	}

	cout << str;

	system("pause");
	return 0;
}

