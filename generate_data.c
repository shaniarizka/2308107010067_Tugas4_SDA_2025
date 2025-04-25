/*
 * File: generate_data.c
 * Deskripsi: Program untuk membangkitkan data angka dan kata acak
 * Digunakan untuk menyiapkan file data_angka.txt dan data_kata.txt
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 
 // Fungsi untuk membangkitkan angka acak dan menyimpannya ke file
 void generate_random_numbers(const char *filename, int count, int max_value) {
     FILE *fp = fopen(filename, "w");
     if (!fp) {
         perror("File tidak dapat dibuka");
         return;
     }
     srand(time(NULL));
     for (int i = 0; i < count; i++) {
         int num = rand() % max_value;
         fprintf(fp, "%d\n", num);
     }
     fclose(fp);
     printf("Data angka disimpan ke %s (%d angka)\n", filename, count);
 }
 
 // Fungsi untuk membangkitkan kata acak
 void random_word(char *word, int length) {
     static const char charset[] = "abcdefghijklmnopqrstuvwxyz";
     for (int i = 0; i < length; i++) {
         int key = rand() % (int)(sizeof(charset) - 1);
         word[i] = charset[key];
     }
     word[length] = '\0';
 }
 
 // Fungsi untuk membangkitkan kata acak dan menyimpannya ke file
 void generate_random_words(const char *filename, int count, int max_word_length) {
     FILE *fp = fopen(filename, "w");
     if (!fp) {
         perror("File tidak dapat dibuka");
         return;
     }
     srand(time(NULL) + 1); // Agar hasil tidak sama dengan angka
     char word[100];
     for (int i = 0; i < count; i++) {
         int length = (rand() % (max_word_length - 3)) + 3; // panjang minimal 3
         random_word(word, length);
         fprintf(fp, "%s\n", word);
     }
     fclose(fp);
     printf("Data kata disimpan ke %s (%d kata)\n", filename, count);
 }
 
 int main() {
     generate_random_numbers("data_angka.txt", 2000000, 2000000);
     generate_random_words("data_kata.txt", 2000000, 20);
     return 0;
 }
 