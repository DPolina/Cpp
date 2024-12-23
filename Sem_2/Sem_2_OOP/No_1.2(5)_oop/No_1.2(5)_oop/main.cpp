#include <iostream>
#include <fstream>

using namespace std;

int main() {


    ifstream in_1("f.txt");
    ifstream in_2("f.txt");

    ofstream out("./g.txt");

    while (in_1 || in_2) {
        while (in_1) {
            int num;
            in_1.read(reinterpret_cast<char*>(&num), sizeof(num));
            
            if (num > 0) {
                out.write(reinterpret_cast<char*>(&num), sizeof(num));
                break;
            }
        }

        while (in_2) {
            int num;
            in_2.read(reinterpret_cast<char*>(&num), sizeof(num));

            if (num < 0) {
                out.write(reinterpret_cast<char*>(&num), sizeof(num));
                break;
            }
        }
    }

    return 0;
}