# Single Linked List Mahasiswa

## Deskripsi
Implementasi struktur data Single Linked List untuk manajemen data mahasiswa dengan bahasa C. Program ini menyediakan operasi-operasi dasar manipulasi linked list serta beberapa fitur tambahan seperti pengurutan, penyalinan dengan kondisi, dan penghapusan duplikat.

## Struktur Program

### Komponen Utama
1. **Type Data Mahasiswa** (`mahasiswa.h` dan `mahasiswa.c`)
   - Mendefinisikan struktur data mahasiswa dengan atribut nama dan nilai
   - Implementasi fungsi-fungsi untuk manipulasi data mahasiswa

2. **Single Linked List** (`linked.h` dan `linked.c`)
   - Implementasi struktur data linked list dan node
   - Fungsi-fungsi manipulasi linked list (insert, delete, traversal)

3. **Program Utama** (`main.c`)
   - Mendemonstrasikan penggunaan ADT Linked List Mahasiswa

### Fitur Program
- Pembuatan dan penghapusan linked list
- Penyisipan data mahasiswa secara terurut (ascending) berdasarkan nama
- Pencetakan data mahasiswa (ascending nama dan descending nilai)
- Penghitungan jumlah elemen dalam linked list
- Penyalinan data mahasiswa dengan nilai di atas threshold tertentu
- Penghapusan data mahasiswa duplikat berdasarkan nama

## Operasi-operasi Linked List
1. **Operasi Dasar**
   - `CreateEmpty`: Membuat list kosong
   - `isEmpty`: Mengecek apakah list kosong
   - `isOneElmt`: Mengecek apakah list hanya memiliki satu elemen
   - `DeAlokasi`: Menghapus seluruh elemen list

2. **Operasi Insert**
   - `InsVFirst`: Menyisipkan elemen di awal list
   - `InsVLast`: Menyisipkan elemen di akhir list
   - `InsertAscending`: Menyisipkan elemen secara terurut berdasarkan nama

3. **Operasi Delete**
   - `DelVFirst`: Menghapus elemen di awal list
   - `DelVLast`: Menghapus elemen di akhir list

4. **Operasi Lainnya**
   - `PrintInfo`: Menampilkan list mahasiswa berurutan ascending berdasarkan nama
   - `PrintInfoDescendingByNilai`: Menampilkan list mahasiswa berurutan descending berdasarkan nilai
   - `CopyGreaterThan`: Menyalin mahasiswa dengan nilai di atas threshold ke list baru
   - `RemoveDuplicates`: Menghapus nama mahasiswa yang duplikat

## Cara Penggunaan
1. Compile program dengan menjalankan:
   ```
   gcc -o program main.c linked.c mahasiswa.c
   ```

2. Jalankan program:
   ```
   ./program
   ```

3. Program akan menjalankan serangkaian operasi linked list dan menampilkan hasilnya.

## Contoh Alur Penggunaan dalam `main.c`
1. Membuat dua linked list kosong (L1 dan L2)
2. Menambahkan data mahasiswa ke L1 secara terurut berdasarkan nama
3. Menampilkan data mahasiswa dalam L1 (berurut berdasarkan nama)
4. Menampilkan data mahasiswa dalam L1 (berurut berdasarkan nilai, descending)
5. Menghitung jumlah mahasiswa dalam L1
6. Menyalin mahasiswa dengan nilai > 70 ke L2
7. Menambahkan beberapa data mahasiswa duplikat ke L2
8. Menghapus nama duplikat dari L2
9. Menghapus kedua linked list

