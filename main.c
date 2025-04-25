/*
 * File: main.c
 * Deskripsi: Program utama untuk menguji performa 6 algoritma sorting terhadap data besar
 * Menulis hasil pengujian waktu dan memori ke file log
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include <windows.h>
 #include <psapi.h>
 
 // Header untuk semua algoritma sorting
 #include "bubble_sort.h"
 #include "selection_sort.h"
 #include "insertion_sort.h"
 #include "merge_sort.h"
 #include "quick_sort.h"
 #include "shell_sort.h"
 
 #define MAX 2000000
 #define MAX_WORD 21
 
 int angka[MAX], backupAngka[MAX];
 char kata[MAX][MAX_WORD], backupKata[MAX][MAX_WORD];
 
 // Fungsi untuk membaca data angka dari file
 void load_data_angka(const char *filename, int count) {
     FILE *fp = fopen(filename, "r");
     if (!fp) {
         perror("File angka tidak bisa dibuka");
         exit(EXIT_FAILURE);
     }
     for (int i = 0; i < count; i++) {
         fscanf(fp, "%d", &angka[i]);
         backupAngka[i] = angka[i];
     }
     fclose(fp);
 }
 
 // Fungsi untuk membaca data kata dari file
 void load_data_kata(const char *filename, int count) {
     FILE *fp = fopen(filename, "r");
     if (!fp) {
         perror("File kata tidak bisa dibuka");
         exit(EXIT_FAILURE);
     }
     for (int i = 0; i < count; i++) {
         fscanf(fp, "%s", kata[i]);
         strcpy(backupKata[i], kata[i]);
     }
     fclose(fp);
 }
 
 void reset_data_angka(int count) {
     for (int i = 0; i < count; i++) angka[i] = backupAngka[i];
 }
 
 void reset_data_kata(int count) {
     for (int i = 0; i < count; i++) strcpy(kata[i], backupKata[i]);
 }
 
 void printMemoryUsage(FILE *log, const char *nama, int n) {
     PROCESS_MEMORY_COUNTERS memCounter;
     if (GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter))) {
         double memMB = memCounter.WorkingSetSize / (1024.0 * 1024.0);
         printf("%s (%d data): Memori digunakan: %.2f MB\n", nama, n, memMB);
         fprintf(log, "%s,%d,%.2f MB\n", nama, n, memMB);
     }
 }
 
 void ukur_waktu_angka(void (*sort_func)(int[], int), const char *nama, int n, FILE *log_time, FILE *log_mem) {
     reset_data_angka(n);
     clock_t start = clock();
     sort_func(angka, n);
     clock_t end = clock();
     double waktu = (double)(end - start) / CLOCKS_PER_SEC;
     printf("[ANGKA] %s (%d): %.2f detik\n", nama, n, waktu);
     fprintf(log_time, "%s,%d,%.4f\n", nama, n, waktu);
     printMemoryUsage(log_mem, nama, n);
 }
 
 void ukur_waktu_kata(void (*sort_func)(char[][MAX_WORD], int), const char *nama, int n, FILE *log_time, FILE *log_mem) {
     reset_data_kata(n);
     clock_t start = clock();
     sort_func(kata, n);
     clock_t end = clock();
     double waktu = (double)(end - start) / CLOCKS_PER_SEC;
     printf("[KATA ] %s (%d): %.2f detik\n", nama, n, waktu);
     fprintf(log_time, "%s,%d,%.4f\n", nama, n, waktu);
     printMemoryUsage(log_mem, nama, n);
 }
 
 int main() {
     const char *file_angka = "data_angka.txt";
     const char *file_kata  = "data_kata.txt";
     int sizes[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};
     int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
 
     printf("Membaca data angka dan kata...\n");
     load_data_angka(file_angka, MAX);
     load_data_kata(file_kata, MAX);
 
     FILE *log_time = fopen("log_waktu.txt", "w");
     FILE *log_mem = fopen("log_memori.txt", "w");
     if (!log_time || !log_mem) {
         perror("Tidak bisa membuat file log.");
         return 1;
     }
     fprintf(log_time, "Algoritma,Ukuran,WaktuDetik\n");
     fprintf(log_mem, "Algoritma,Ukuran,MemoriDigunakan\n");
 
     for (int i = 0; i < num_sizes; i++) {
         int n = sizes[i];
 
         // Sorting Angka
         ukur_waktu_angka(bubbleSort, "Bubble Sort", n, log_time, log_mem);
         ukur_waktu_angka(selectionSort, "Selection Sort", n, log_time, log_mem);
         ukur_waktu_angka(insertionSort, "Insertion Sort", n, log_time, log_mem);
         ukur_waktu_angka(mergeSortWrapper, "Merge Sort", n, log_time, log_mem);
         ukur_waktu_angka(quickSortWrapper, "Quick Sort", n, log_time, log_mem);
         ukur_waktu_angka(shellSort, "Shell Sort", n, log_time, log_mem);
 
         // Sorting Kata
         ukur_waktu_kata(bubbleSortStr, "Bubble Sort Str", n, log_time, log_mem);
         ukur_waktu_kata(selectionSortStr, "Selection Sort Str", n, log_time, log_mem);
         ukur_waktu_kata(insertionSortStr, "Insertion Sort Str", n, log_time, log_mem);
         ukur_waktu_kata(mergeSortStrWrapper, "Merge Sort Str", n, log_time, log_mem);
         ukur_waktu_kata(quickSortStrWrapper, "Quick Sort Str", n, log_time, log_mem);
         ukur_waktu_kata(shellSortStr, "Shell Sort Str", n, log_time, log_mem);
 
         printf("--------------------------\n");
     }
 
     fclose(log_time);
     fclose(log_mem);
     printf("Hasil waktu ditulis ke log_waktu.txt\n");
     printf("Hasil memori ditulis ke log_memori.txt\n");
     return 0;
 }
 