#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <string.h>

/*
 * Quick Sort untuk angka:
 * Algoritma ini menggunakan pendekatan divide and conquer.
 * Memilih elemen sebagai pivot, lalu membagi array menjadi dua bagian:
 * yang lebih kecil dan lebih besar dari pivot, dan memanggil quick sort secara rekursif.
 */

// Fungsi partisi array integer
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // elemen terakhir sebagai pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // tukar arr[i] dengan arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // tukar pivot ke posisi tengah
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Fungsi utama Quick Sort untuk angka
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partisi
        quickSort(arr, low, pi - 1);        // kiri
        quickSort(arr, pi + 1, high);       // kanan
    }
}

// Wrapper agar seragam dengan sorting lainnya
void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

/*
 * Quick Sort untuk string:
 * Menggunakan teknik yang sama, tapi membandingkan string secara leksikografis.
 */

int partitionStr(char arr[][21], int low, int high) {
    char pivot[21];
    strcpy(pivot, arr[high]);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char temp[21];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
    char temp[21];
    strcpy(temp, arr[i + 1]);
    strcpy(arr[i + 1], arr[high]);
    strcpy(arr[high], temp);

    return i + 1;
}

void quickSortStr(char arr[][21], int low, int high) {
    if (low < high) {
        int pi = partitionStr(arr, low, high);
        quickSortStr(arr, low, pi - 1);
        quickSortStr(arr, pi + 1, high);
    }
}

void quickSortStrWrapper(char arr[][21], int n) {
    quickSortStr(arr, 0, n - 1);
}

#endif
