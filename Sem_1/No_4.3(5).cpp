#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	const int MAX = 100;

	char str[MAX] = { 0 };
	char str1[MAX] = { 0 };

	char div[] = " .,:;!?-()";
	char vowels[] = "aeiouy";

	int counter_max = 0;

	cout << "Enter text: ";
	cin.getline(str, MAX);

	char* word = strtok(str, div);
	
	while (word != nullptr) {

		int counter = 0;

		int word_len = strlen(word);
		for (int i = 0; i < word_len; i++) {
			for (int j = 0; j < sizeof(vowels); j++) {
				if (word[i] == vowels[j]) {
					counter++;
					break;
				}
			}
		}
		if (counter == counter_max) {
			strcat(str1, word);
			strcat(str1, " ");
		}
		else if (counter > counter_max) {
			counter_max = counter;
			strcpy(str1, word);
			strcat(str1, " ");
		}

		word = strtok(nullptr, div);
	}

	cout << str1 << endl;

	system("pause");
	return 0;
}



