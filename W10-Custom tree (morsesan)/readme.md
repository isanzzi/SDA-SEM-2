
Custom tree (morsesan)

---

# Konverter Kode Morse Menggunakan Binary Tree

## Gambaran Umum

Aplikasi ini mengimplementasikan konversi kode Morse menggunakan struktur data pohon biner (binary tree). Aplikasi ini memungkinkan konversi dua arah antara teks dan kode Morse. Pohon biner merepresentasikan pengkodean Morse, di mana pergerakan ke kiri mewakili titik (ditandai dengan `'r'`) dan pergerakan ke kanan mewakili garis (ditandai dengan `'n'`).

## Fitur

* Mengubah string teks menjadi kode Morse
* Mengubah kode Morse menjadi string teks
* Memproses file teks untuk konversi massal
* Visualisasi struktur pohon biner dengan traversal in-order

## Detail Implementasi

### Struktur Data

Proyek ini menggunakan pohon biner di mana:

* Setiap simpul (node) menyimpan satu karakter
* Pergerakan ke kiri mewakili titik dalam kode Morse (dilambangkan dengan `'r'`)
* Pergerakan ke kanan mewakili garis dalam kode Morse (dilambangkan dengan `'n'`)
* Jalur dari root ke simpul menentukan kode Morse dari karakter tersebut

### Komponen Utama

#### Struktur Pohon Biner

* `nbtree` – Struktur utama pohon dengan pointer ke kiri, kanan, dan induk (parent)
* `Create_node` – Membuat simpul baru dengan karakter tertentu
* `initialize_tree` – Membangun pohon kode Morse dengan seluruh huruf, angka, dan spasi

#### Fungsi Konversi

* `stringtomorse` – Mengubah string teks menjadi kode Morse
* `morsetostring` – Mengubah kode Morse menjadi string teks
* `txtmorsetostring` – Memproses input/output dari file untuk konversi massal

#### Fungsi Pembantu

* `toupperstring` – Mengubah string menjadi huruf kapital
* `findcharintree` – Mencari karakter dalam pohon dan merekam jalur Morse-nya

### Gambaran Algoritma

#### Konversi Teks ke Morse

1. Untuk setiap karakter dalam string input:
   * Cari karakter tersebut dalam pohon biner
   * Lacak jalur dari root ke simpul karakter menggunakan stack
   * Ubah jalur menjadi simbol Morse ('r' untuk titik, 'n' untuk garis)
   * Tambahkan pemisah (`/`) antar karakter

#### Konversi Morse ke Teks

1. Untuk setiap simbol kode Morse dalam input:
   * Mulai dari root pohon
   * Untuk setiap `'r'` (titik), bergerak ke kiri
   * Untuk setiap `'n'` (garis), bergerak ke kanan
   * Saat menemukan pemisah (`/`), keluarkan karakter dari simpul saat ini
   * Kembali ke root untuk karakter berikutnya

## Penggunaan

Aplikasi ini menggunakan antarmuka berbasis menu dengan pilihan sebagai berikut:

1. **Traversal In-order** – Menampilkan struktur pohon dengan traversal in-order
2. **Teks ke Morse** – Mengubah contoh string ("JTK Politeknik Negeri Bandung") menjadi kode Morse
3. **Morse ke Teks** – Mengubah input Morse dari pengguna menjadi teks
4. **Pemrosesan File** – Mengubah teks dari `input.txt` menjadi Morse dan menyimpan ke `output.txt`
5. **Keluar** – Mengakhiri program

## Format Input/Output

* Kode Morse menggunakan `'r'` untuk titik dan `'n'` untuk garis
* `'/'` digunakan sebagai pemisah antar karakter
* Untuk pemrosesan file, input dibaca dari "input.txt" dan output ditulis ke "output.txt"

## Contoh

Teks input: "JTK"

Output kode Morse: `rnnnrrrn/r/nrn/`

## Catatan

* Implementasi ini menangani huruf kapital, angka 0–9, dan spasi
* Karakter khusus belum didukung dalam versi saat ini
