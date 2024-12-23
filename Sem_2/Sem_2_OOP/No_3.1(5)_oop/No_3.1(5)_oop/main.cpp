#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void N41() {

	string str;
	cout << "Enter text: ";
	getline(cin, str);
	cin.get();

	int to_del[256] = { 0 };

	int length = str.size();

	for (int i = 0; i < length; i++) {
		char letter = str.at(i);
		to_del[letter]++;
	}

	for (int i = 0; i < length; i++) {
		char letter = str.at(i);
		if (to_del[letter] == 2) {
			str.erase(i,1);
			i--;
			length--;
		}
	}

	cout << str << endl;
}

void N42() {

	string num;
	cout << "Number in 16-s: ";
	getline(cin, num);
	cin.get();

	int length = num.size() - 1;
	int power = 0;
	int idx = 0;

	while (true) {
		power++;
		if (num[idx + 1] == '.') {
			break;
		}
		else {
			idx++;
		}
	}

	double answer = 0;
	double number = 0;

	for (int i = 0; i < length; i++) {

		char letter = toupper(num.at(i));
		if (letter == '.')
			continue;

		if (letter >= 'A' && letter <= 'F') {
			number = letter - 'A' + 10;
		}
		else {
			number = letter - '0';
		}

		cout << number << "*16^" << power - 1;
		if (i < length - 1)
			cout << " + ";
		answer += number * pow(16., power - 1);
		power--;
	}

	cout << endl << "Number is " << answer << endl;
}

string N43(const string& div, const string& vowels) {

	string str;
	string res;

	cout << "Enter text: ";
	getline(cin, str);
	cin.get();

	unsigned int wordBegin = 0, wordEnd = 0;
	int vow_size = vowels.size() - 1;

	int counter_max = 0;

	wordBegin = str.find_first_not_of(div, wordEnd);
	wordEnd = str.find_first_of(div, wordBegin);

	if (wordEnd >= str.length())
		wordEnd = str.length();
	while (wordBegin < str.length()) {

		string word = str.substr(wordBegin, wordEnd - wordBegin);
		cout << word << "    ";
		int word_len = word.size() - 1;

		int counter = 0;

		int word_size = word.size() - 1;
		int vow_size = vowels.size() - 1;

		for (int i = 0; i < word_size; i++) {
			for (int j = 0; j < vow_size; j++) {
				if (word.at(i) == vowels.at(j)) {
					counter++;
					break;
				}
			}
		}
		if (counter == counter_max) {
			res += word + " ";
		}
		else if (counter > counter_max) {
			counter_max = counter;
			res = word + " ";
		}

		wordBegin = str.find_first_not_of(div, wordEnd);

		wordEnd = str.find_first_of(div, wordBegin);
		if (wordEnd >= str.length())
			wordEnd = str.length();
	}
	cout << endl << res << endl;
	return res;
}

int main() {

	cout << "No 4.1(5)   From the given text, remove those characters that occur exactly twice." << endl << endl;
	N41();

	cout << endl << "No 4.2(5)   Write a program to convert real numbers from hexadecimal to decimal." << endl << endl;
	N42();

	cout << endl << "No 4.3(5)   Write in a new line the words of the original line, in which the number of vowels is maximum." << endl << endl;
	string div = " .,:;!?-()";
	string vowels = "aeiouy";
	cout <<  N43(div, vowels);

	system("pause");
	return 0;
}