
#include "MergeSort.hpp"


void Merge(char** array, int left, int mid, int right) {
    int lSub = mid - left + 1;
    int rSub = right - mid;

    char** lArray = new char* [lSub];
    char** rArray = new char* [rSub];

    for (int i = 0; i < lSub; i++) {
        lArray[i] = array[left + i];
    }
    for (auto j = 0; j < rSub; j++) {
        rArray[j] = array[mid + 1 + j];
    }

    int lIndex = 0;
    int rIndex = 0;
    int mergedIndex = left;
    char ch1 = '0';
    char ch2 = '0';

    while (lIndex < lSub && rIndex < rSub) {
        ch1 = lArray[0][0];
        ch2 = rArray[0][0];
        if (ch1 <= ch2) {
            array[mergedIndex] = lArray[lIndex];
            lIndex++;
        }
        else {
            array[mergedIndex] = rArray[rIndex];
            rIndex++;
        }
        mergedIndex++;
    }
    while (lIndex < lSub) {
        array[mergedIndex] = lArray[lIndex];
        lIndex++;
        mergedIndex++;
    }
    while (rIndex < rSub) {
        array[mergedIndex] = rArray[rIndex];
        rIndex++;
        mergedIndex++;
    }
    delete[] lArray;
    delete[] rArray;
}

