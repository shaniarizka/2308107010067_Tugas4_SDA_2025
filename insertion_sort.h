#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <string.h>

/*
 * Insertion Sort untuk angka:
 * Algoritma ini menyusun array dengan membangun bagian yang sudah terurut satu per satu.
 * Untuk setiap elemen, algoritma akan menyisipkannya ke posisi yang tepat dalam bagian yang sudah terurut.
 * Kompleksitas waktu:
 * - Best case (sudah terurut): O(n)
 * - Worst case (terbalik): O(n^2)
 * Efisien untuk array kecil atau hampir terurut.
 */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Geser elemen yang lebih besar ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Sisipkan key ke posisi yang tepat
        arr[j + 1] = key;
    }
}

/*
 * Insertion Sort untuk string:
 * Menyisipkan setiap kata ke posisi yang tepat dalam array string terurut (berbasis leksikografis).
 */
void insertionSortStr(char arr[][21], int n) {
    for (int i = 1; i < n; i++) {
        char key[21];
        strcpy(key, arr[i]);
        int j = i - 1;

        // Geser string yang lebih besar ke kanan
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }

        // Sisipkan key ke posisi yang tepat
        strcpy(arr[j + 1], key);
    }
}

#endif