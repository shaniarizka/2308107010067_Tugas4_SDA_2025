#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <string.h>

/*
 * Shell Sort untuk angka:
 * Menggunakan jarak (gap) untuk menyisipkan elemen lebih efisien dari Insertion Sort.
 * Gap dikurangi bertahap hingga 1, lalu dilakukan Insertion Sort biasa.
 */
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Sisipkan temp ke posisi yang tepat dalam gap
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

/*
 * Shell Sort untuk string:
 * Proses yang sama seperti angka, tapi menggunakan strcmp untuk membandingkan string.
 */
void shellSortStr(char arr[][21], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp[21];
            strcpy(temp, arr[i]);
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap) {
                strcpy(arr[j], arr[j - gap]);
            }
            strcpy(arr[j], temp);
        }
    }
}

#endif
