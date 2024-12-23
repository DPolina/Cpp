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
//    ofstream out("./f.txt");
//    int size = 100;
//    int max = 99;
//    int min = -99;
//    if (out.is_open()) {
//        for (int i = 0; i < size / 2; i++) {
//            out << (rand() % (0 - min)) + min << endl;
//        }
//        for (int i = (size / 2); i < size; i++) {
//            out << (rand() % max) << endl;
//        }
//    }
//    return 0;
//}