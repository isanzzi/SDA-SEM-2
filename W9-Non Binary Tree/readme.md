# Non-Binary Tree Implementation

Proyek ini berisi implementasi pohon non-biner menggunakan array statis. Pohon ini mendukung berbagai operasi seperti traversal, pencarian, dan analisis struktur pohon. Selain itu, proyek ini juga mendukung visualisasi pohon menggunakan Graphviz.

## Fitur Utama

1. **Traversal**:
   - PreOrder
   - InOrder
   - PostOrder
   - Level Order

2. **Operasi Lain**:
   - Pencarian node berdasarkan nilai.
   - Menghitung jumlah daun (leaf).
   - Menentukan level suatu node.
   - Menghitung kedalaman pohon.
   - Membandingkan dua node untuk mendapatkan nilai terbesar.

3. **Visualisasi**:
   - Pohon dapat diekspor ke format Graphviz (`tree.dot`) untuk divisualisasikan.

## Cara Menggunakan

### 1. Menjalankan Program
- Kompilasi program menggunakan GCC atau compiler C lainnya.
- Jalankan file `main.c` untuk memulai program.
- Pilih opsi untuk menggunakan pohon bawaan atau membuat pohon baru.

### 2. Visualisasi Pohon
Setelah memilih opsi "Print Tree", file `tree.dot` akan dihasilkan. Anda dapat memvisualisasikan file ini dengan dua cara:

#### Opsi 1: Menggunakan Graphviz di Lokal
1. Instal Graphviz dan tambahkan ke PATH.
2. Jalankan perintah berikut di terminal:
   ```
   dot -Tpng tree.dot -o tree.png
   ```
3. File `tree.png` akan berisi visualisasi pohon.

#### Opsi 2: Menggunakan Graphviz Online
1. Buka tautan berikut: [Graphviz Online](https://dreampuf.github.io/GraphvizOnline/).
2. Salin isi file `tree.dot` dan tempelkan ke editor di situs tersebut.
3. Visualisasi pohon akan ditampilkan.

## Struktur File

- `tree.h`: Header file yang mendefinisikan struktur data dan fungsi untuk pohon non-biner.
- `tree.c`: Implementasi fungsi-fungsi yang dideklarasikan di `tree.h`.
- `main.c`: Program utama untuk menjalankan berbagai operasi pada pohon.
- `tree.dot`: File keluaran untuk visualisasi pohon menggunakan Graphviz.

## Catatan

- Maksimal jumlah node dalam pohon adalah 20 (dapat diubah dengan mengedit konstanta `jml_maks` di `tree.h`).
- Pastikan jumlah node yang dimasukkan valid saat membuat pohon baru.

## Referensi

- [Graphviz Documentation](https://graphviz.org/documentation/)
