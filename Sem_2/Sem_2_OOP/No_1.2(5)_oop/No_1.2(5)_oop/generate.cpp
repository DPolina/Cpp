//#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <string>
//#include <cstdint>
//#include <time.h>
//
//using namespace std;
//
//int main() {
//    srand(time(nullptr));
//    ofstream out("./f.txt",ios::binary);
//    int size = 100;
//    int max = 99;
//    int min = -99;
//    if (out.is_open()) {
//        for (int i = 0; i < size / 2; i++) {
//            int num = (rand() % (0 - min)) + min;
//            out.write(reinterpret_cast<char*>(&num), sizeof(num));
//        }
//        for (int i = (size / 2); i < size; i++) {
//            int num = (rand() % max);
//            out.write(reinterpret_cast<char*>(&num), sizeof(num));
//        }
//    }
//    return 0;
//}