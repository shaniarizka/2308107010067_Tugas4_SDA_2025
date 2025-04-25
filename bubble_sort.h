#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <string.h>

/*
 * Bubble Sort untuk angka:
 * Algoritma ini bekerja dengan membandingkan setiap elemen bersebelahan dan menukarnya
 * jika dalam urutan yang salah. Proses ini diulang hingga seluruh array terurut.
 * Kompleksitas Waktu: O(n^2) worst-case dan best-case O(n) jika sudah terurut dengan flag optimasi.
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

/*
 * Bubble Sort untuk string:
 * Membandingkan string bersebelahan dan menukar posisi jika tidak dalam urutan leksikografis.
 * Proses diulang hingga array string terurut dari A-Z.
 */
void bubbleSortStr(char arr[][21], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[21];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

#endif