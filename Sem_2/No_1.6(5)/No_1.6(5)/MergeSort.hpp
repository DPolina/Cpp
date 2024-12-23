#pragma once

#include <iostream>
#include <string.h>



template <typename T>
void Merge(T* array, int left, int mid, int right) {
    int lSub = mid - left + 1;
    int rSub = right - mid;

    T* lArray = new T[lSub];
    T* rArray = new T[rSub];

    for (int i = 0; i < lSub; i++) {
        lArray[i] = array[left + i];
    }
    for (auto j = 0; j < rSub; j++) {
        rArray[j] = array[mid + 1 + j];
    }

    int lIndex = 0;
    int rIndex = 0;
    int mergedIndex = left;

    while (lIndex < lSub && rIndex < rSub) {
        if (lArray[lIndex] <= rArray[rIndex]) {
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

template <typename T>
void MergeSort(T* arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, begin, mid, end);
}


void Merge(char** array, int left, int mid, int right);