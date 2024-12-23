//No_1.2(5)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip> 

using namespace std;

bool is_not_separator(const char* div, char c) {
	return strchr(div, c) == 0;
}

int count_words(const char* str, const char* div) {

	int n = 0; // number of words

	int str_len = strlen(str);
	for (int i = 0; i < str_len; i++) {

		if (i == str_len - 1 && is_not_separator(div, str[i]) == true) {
			n++;
		}
		else if (i < str_len - 1 && is_not_separator(div, str[i]) != is_not_separator(div, str[i + 1]) 
			&& is_not_separator(div, str[i]) > is_not_separator(div, str[i + 1])) {
			n++;
		}
	}

	return n;
}

int main() {

	setlocale(LC_ALL, "rus");

	const int MAX = 100;

	char str[MAX] = { 0 };
	char str_res[MAX] = { 0 };
	
	char div[] = " .,:;!?-()";

	cout << "Enter text: ";
	cin.getline(str, MAX);

	int str_len = strlen(str);
	
	int n = count_words(str, div);
	cout << "n = " << n << endl;

	if (n == 0) {
		return 1;
	}

	char** words = new char* [n] {};

	int word_count = 0;
	char* word = strtok(str, div);
	while (word != nullptr) {
		words[word_count++] = word;
		word = strtok(nullptr, div);
	}

	int counter_max = 0;
	for (int i = 0; i < word_count; i++) {
		char* word = words[i];

		int counter = 0;
		for (int j = 0; j < n; j++) {
			if (strcmp(words[i], words[j]) == 0) {
				counter++;
			}
		}

		if (counter > counter_max) {
			counter_max = counter;
		}
	}

	for (int i = 0; i < word_count; i++) {
		char* word = words[i];

		bool unique = true;
		for (int j = 0; j < i; j++) {
			if (strcmp(words[i], words[j]) == 0) {
				unique = false;
			}
		}

		if (!unique) {
			continue;
		}

		int counter = 0;
		for (int j = 0; j < n; j++) {
			if (strcmp(words[i], words[j]) == 0) {
				counter++;
			}
		}

		if (counter == counter_max) {
			strcat(str_res, word);
			strcat(str_res, " ");
		}

	}
	cout << "result: " << str_res << endl;

	system("pause");
	return 0;
}