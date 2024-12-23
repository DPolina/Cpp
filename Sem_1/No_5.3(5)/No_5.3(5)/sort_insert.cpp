#include "sort_insert.h"

using namespace std;

int* sort_insert(int* array_ptr, int isize, int* index) {
    for (int i = 1; i < isize; i++) {
        int iInd = index[i];
        int iTemper = array_ptr[i];
        int i_n = i - 1;
        for (; i_n >= 0; i_n--) {
            if (iTemper <= array_ptr[i_n]) {
                break;
            }
            array_ptr[i_n + 1] = array_ptr[i_n];
            index[i_n + 1] = index[i_n];
        }
        array_ptr[i_n + 1] = iTemper;
        index[i_n + 1] = iInd;
    }
    return array_ptr;
}