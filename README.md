# Program Simple Sorting
Program ini adalah implementasi dari tiga algoritma pengurutan sederhana, yaitu Bubble Sort, Selection Sort, dan Insertion Sort. Program ini akan menghasilkan bilangan acak, menyimpannya dalam file teks, mengurutkan bilangan tersebut menggunakan ketiga algoritma, menyimpan hasil pengurutan dalam file teks, dan mencatat waktu eksekusi untuk setiap pengurutan.

# Cara Menjalankan Kode Program
1. Pastikan Anda memiliki compiler C yang terpasang di sistem Anda. Jika belum, Anda dapat menginstal GCC di sistem Linux atau MinGW di Windows.
2. Salin atau download kode program yang terdapat pada file di atas ke dalam sebuah berkas sumber dengan nama simple_sorting.c
3. Buka terminal atau command prompt dan arahkan ke direktori tempat Anda menyimpan berkas simple_sorting.c.
4. Compile program dengan menjalankan perintah
    #### gcc simple_sorting.c -o simple_sorting
5. Setelah berhasil dikompilasi, jalankan program dengan mengetikkan perintah
    #### .\simple_sorting

# Fungsi yang Digunakan
### 1. Fungsi generateRandomNumbers(int *arr, int n)
    Fungsi yang digunakan untuk menghasilkan bilangan acak dalam array arr dengan ukuran n.
### 2. Fungsi bubbleSort(int *arr, int n) 
    Fungsi ini mengurutkan array arr menggunakan algoritma Bubble Sort.
### 3. Fungsi selectionSort(int *arr, int n)
    Fungsi ini mengurutkan array arr menggunakan algoritma Selection Sort.
### 4. Fungsi insertionSort(int *arr, int n)
    Fungsi ini mengurutkan array arr menggunakan algoritma Insertion Sort.
### 5. Fungsi saveArrayToFile(int *arr, int n, const char *filename)
    Fungsi ini digunakan untuk menyimpan isi array arr dengan ukuran n ke dalam file dengan nama filename.
### 6. Fungsi main()
    Fungsi utama yang mengatur jalannya program.
