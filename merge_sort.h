#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Merge Sort untuk angka:
 * Menggunakan teknik divide and conquer.
 * Array dibagi dua secara rekursif, disortir, lalu digabung (merge) kembali.
 */

// Fungsi untuk menggabungkan dua bagian array yang telah terurut
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Alokasi array sementara
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    if (L == NULL || R == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        exit(EXIT_FAILURE);
    }

    // Salin elemen ke array sementara
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Proses penggabungan array sementara ke array utama
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Salin sisa elemen jika ada
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    // Bebaskan memori sementara
    free(L);
    free(R);
}

// Fungsi utama merge sort untuk array angka
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // cari titik tengah
        mergeSort(arr, l, m);    // urutkan bagian kiri
        mergeSort(arr, m + 1, r); // urutkan bagian kanan
        merge(arr, l, m, r);     // gabungkan keduanya
    }
}

// Wrapper agar bisa dipanggil dari main
void mergeSortWrapper(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}

/*
 * Merge Sort untuk string:
 * Proses sama dengan merge sort angka, tapi membandingkan string.
 */

void mergeStr(char arr[][21], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    char (*L)[21] = malloc(n1 * 21);
    char (*R)[21] = malloc(n2 * 21);

    if (!L || !R) {
        printf("Gagal mengalokasikan memori untuk string.\n");
        exit(EXIT_FAILURE);
    }

    // Salin ke array sementara
    for (int i = 0; i < n1; i++) strcpy(L[i], arr[l + i]);
    for (int j = 0; j < n2; j++) strcpy(R[j], arr[m + 1 + j]);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) strcpy(arr[k++], L[i++]);
        else strcpy(arr[k++], R[j++]);
    }

    while (i < n1) strcpy(arr[k++], L[i++]);
    while (j < n2) strcpy(arr[k++], R[j++]);

    free(L);
    free(R);
}

void mergeSortStr(char arr[][21], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortStr(arr, l, m);
        mergeSortStr(arr, m + 1, r);
        mergeStr(arr, l, m, r);
    }
}

void mergeSortStrWrapper(char arr[][21], int n) {
    mergeSortStr(arr, 0, n - 1);
}

#endif
