#include <iostream>
#include <cstring>


using namespace std;

void zamena(char* s, const char* s2, int startChar, int count) {

    int s_len = strlen(s);
    int s2_len = strlen(s2);

    int delta = s2_len - count;
    if (delta >= 0) {
        for (int i = s_len - 1; i >= startChar; i--) {
            s[i + delta] = s[i];
        }
    }
    else {
        cout << "vi hotite shtobi programma slomalas?" << endl;
    }

    for (int i = 0; i < s2_len; i++) {
        s[startChar + i] = s2[i];
    }
}

void raspakovka(char* s3) {

    int len = strlen(s3);
    for (int i = 0; i < len; i++)
    {
        if (s3[i] == '(' && s3[i + 2] == ')') {
            int z = s3[i + 1] - '0';
            char b = s3[i + 3];

            char tmp[10]{};

            for (int i = 0; i < z; i++) {
                tmp[i] = b;
            }


            zamena(s3, tmp, i, 4);
            len = strlen(s3);
        }
    }

}



int main() {

    char c[100] = "priv(4)et mikha(7)il adreevich";

    cout << c << endl;

    raspakovka(c);

    cout << c << endl;

}