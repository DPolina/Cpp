#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

void replace(char* S, int idx, int len, const char* S2) {

    int i_ = 0;
    int S_len = strlen(S);
    int S2_len = strlen(S2);

    int delta = len - S2_len;

    if (delta < 0) {
        for (int i = S_len - delta; i > idx; i--) {
            S[i] = S[i - 1];
        }
    } else if (delta > 0) {
        for (int i = idx; i <= S_len + delta; i++) {
            S[i] = S[i + 1];
        }
    }
    for (int i = idx, j = 0; i < S_len && j < S2_len; i++, j++) {

         S[i] = S2[j];
    }

}

void unpacking(char* S3) {

    int len = strlen(S3);

    for (int i = 0; i < len; i++) {

        if (S3[i] == '(' && S3[i + 2] == ')') {
            int z = S3[i + 1] - '0';
            char b = S3[i + 3];

            char idx[10]{};

            for (int i = 0; i < z; i++) {
                idx[i] = b;
            }

            replace(S3, i, 4, idx);
            len = strlen(S3);
        }
    }
}

int main() {

    char c[100] = "Wel(4)come to the fr(6)eak sh(3)ow!";


    cout << c << endl;

    unpacking(c);

    cout << c << endl;

    system("pause");

    return 0;
}
