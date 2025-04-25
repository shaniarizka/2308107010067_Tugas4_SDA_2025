#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <string.h>

/*
 * Selection Sort untuk angka:
 * Algoritma ini bekerja dengan memilih elemen terkecil dari sisa array,
 * lalu menukarnya ke posisi yang sesuai (awal dari bagian yang belum terurut).
 * Kompleksitas Waktu: O(n^2) untuk semua kasus.
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

/*
 * Selection Sort untuk string:
 * Mencari string terkecil dari sisa array dan menukarnya ke posisi yang sesuai.
 */
void selectionSortStr(char arr[][21], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIdx]) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            char temp[21];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minIdx]);
            strcpy(arr[minIdx], temp);
        }
    }
}

#endif
