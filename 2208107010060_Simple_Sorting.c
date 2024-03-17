/*
Nama : Alhusna Hanifah
NPM  : 2208107010060
Program : Simple Sorting
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk menghasilkan angka acak
void generateRandomNumbers(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

// Fungsi BubbleSort
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1] 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi Selection Sort
void selectionSort(int *arr, int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap arr[i] and arr[min_idx]
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Fungsi Insertion Sort
void insertionSort(int *arr, int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fungsi untuk menyimpan bilangan
void saveArrayToFile(int *arr, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}

int main() {
    //Inisialisasi Variabel
    int max_numbers = 1000000;
    int increment = 100000;

    // Mengacak Bilangan hanya satu kali
    srand(time(NULL));
    int *random_numbers = (int *)malloc(max_numbers * sizeof(int));
    generateRandomNumbers(random_numbers, max_numbers);

    // Menyimpan file yang belum terurut
    for (int n = increment; n <= max_numbers; n += increment) {
        char unsorted_filename[50];
        sprintf(unsorted_filename, "unsorted_%d.txt", n);
        saveArrayToFile(random_numbers, n, unsorted_filename);
    }

    printf("| %15s | %18s | %20s |\n", "Jenis Algoritma", "Jumlah Bilangan", "Waktu Eksekusi (ms)");
    printf("|-----------------|--------------------|----------------------|\n");

    //Mengurutkan bilangan sesuai dengan kenaikan jumlah bilangan
    for (int n = increment; n <= max_numbers; n += increment) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Copy random numbers for sorting
        for (int i = 0; i < n; i++) {
            arr[i] = random_numbers[i];
        }

        clock_t start, end;
        double cpu_time_used;

        // Menggunakan Fungsi Bubble Sort untuk mengurutkan bilangan
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000); 
        printf("| %15s | %18d | %20.2f |\n", "Bubble Sort", n, cpu_time_used);
        char filename[50];
        sprintf(filename, "bubble_sorted_%d.txt", n);
        saveArrayToFile(arr, n, filename);

        free(arr);
    }

    printf("\n");

    //Mengurutkan bilangan sesuai dengan kenaikan jumlah bilangan
    for (int n = increment; n <= max_numbers; n += increment) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Copy random numbers for sorting
        for (int i = 0; i < n; i++) {
            arr[i] = random_numbers[i];
        }

        clock_t start, end;
        double cpu_time_used;

        // Menggunakan fungsi Selection Sort untuk mengurutkan bilangan
        start = clock();
        selectionSort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000); 
        printf("| %15s | %18d | %20.2f |\n", "Selection Sort", n, cpu_time_used);
        char filename[50];
        sprintf(filename, "selection_sorted_%d.txt", n);
        saveArrayToFile(arr, n, filename);

        free(arr);
    }

    printf("\n");

    //Mengurutkan bilangan sesuai dengan kenaikan jumlah bilangan
    for (int n = increment; n <= max_numbers; n += increment) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Copy random numbers for sorting
        for (int i = 0; i < n; i++) {
            arr[i] = random_numbers[i];
        }

        clock_t start, end;
        double cpu_time_used;

        // Menggunakan fungsi Insertion Sort untuk mengurutkan bilangan
        start = clock();
        insertionSort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000); 
        printf("| %15s | %18d | %20.2f |\n", "Insertion Sort", n, cpu_time_used);
        char filename[50];
        sprintf(filename, "insertion_sorted_%d.txt", n);
        saveArrayToFile(arr, n, filename);

        free(arr);
    }

    free(random_numbers); // Free allocated memory for random numbers

    return 0;
}