# Smart Blind Stick

Prototype tongkat pintar berbasis **Arduino Nano** yang menggunakan sensor ultrasonik **HC-SR04** untuk mendeteksi objek di depan pengguna.

Sistem memberikan peringatan melalui:

- 🔊 **Buzzer** berdasarkan jarak objek
- 🔴 **LED** sebagai indikator visual
- 📟 **Serial Monitor** untuk melihat hasil pembacaan jarak

Project ini dikembangkan menggunakan **Arduino CLI**, **Arduino IDE**, **Arduino Nano**, dan dapat disimulasikan menggunakan **Wokwi**.

---

## Daftar Isi

1. [Deskripsi Project](#1-deskripsi-project)
2. [Komponen](#2-komponen)
3. [Pin Arduino Nano](#3-pin-arduino-nano)
4. [Koneksi Komponen](#4-koneksi-komponen)
   - [4.1 Arduino Nano → Breadboard](#41-arduino-nano--breadboard)
   - [4.2 HC-SR04](#42-hc-sr04)
   - [4.3 Buzzer](#43-buzzer)
   - [4.4 LED dan Resistor](#44-led-dan-resistor)
5. [Tahap Perakitan](#5-tahap-perakitan)
   - [Tahap 1 — Jalur Power](#tahap-1--membuat-jalur-power)
   - [Tahap 2 — HC-SR04](#tahap-2--memasang-hc-sr04)
   - [Tahap 3 — Buzzer](#tahap-3--memasang-buzzer)
   - [Tahap 4 — LED](#tahap-4--memasang-led)
6. [Tabel Koneksi Lengkap](#6-tabel-koneksi-lengkap)
7. [Struktur Project](#7-struktur-project)
8. [Persiapan Software](#8-persiapan-software)
9. [Arduino CLI](#9-arduino-cli)
   - [9.1 Masuk ke Folder Project](#91-masuk-ke-folder-project)
   - [9.2 Mengecek Arduino Nano](#92-mengecek-arduino-nano)
   - [9.3 Compile Project](#93-compile-project)
   - [9.4 Upload Program](#94-upload-program)
   - [9.5 Serial Monitor](#95-serial-monitor)
   - [9.6 Serial Monitor dengan Timestamp](#96-serial-monitor-dengan-timestamp)
10. [Arduino IDE](#10-arduino-ide)
    - [10.1 Membuka Project](#101-membuka-project)
    - [10.2 Memilih Board](#102-memilih-board)
    - [10.3 Memilih Processor](#103-memilih-processor)
    - [10.4 Memilih Port](#104-memilih-port)
    - [10.5 Verify / Compile](#105-verify--compile)
    - [10.6 Upload](#106-upload)
    - [10.7 Serial Monitor](#107-serial-monitor)
11. [Perilaku Sistem](#11-perilaku-sistem)
12. [Alur Kerja Program](#12-alur-kerja-program)
13. [Urutan Penggunaan Project](#13-urutan-penggunaan-project)
14. [Troubleshooting](#14-troubleshooting)
    - [14.1 Arduino Tidak Terdeteksi](#141-arduino-tidak-terdeteksi)
    - [14.2 Permission Denied](#142-permission-denied)
    - [14.3 Upload Gagal](#143-upload-gagal)
    - [14.4 Serial Monitor Tidak Menampilkan Log](#144-serial-monitor-tidak-menampilkan-log)
15. [Catatan Perakitan](#15-catatan-perakitan)
16. [Catatan Keselamatan](#16-catatan-keselamatan)
17. [Informasi Project](#17-informasi-project)
18. [Quick Commands](#18-quick-commands)

---

# 1. Deskripsi Project

**Smart Blind Stick** merupakan prototype alat bantu berbasis Arduino Nano yang digunakan untuk mendeteksi keberadaan objek menggunakan sensor ultrasonik HC-SR04.

Ketika objek terdeteksi dalam jarak tertentu, sistem memberikan peringatan melalui buzzer dan LED.

Semakin dekat objek dengan sensor, semakin cepat interval bunyi buzzer dan kedipan LED.

Project ini dapat digunakan melalui:

- **Arduino CLI** untuk workflow berbasis terminal.
- **Arduino IDE** untuk workflow berbasis antarmuka grafis.
- **Wokwi** untuk simulasi rangkaian sebelum digunakan pada hardware fisik.

---

# 2. Komponen

Komponen yang digunakan:

| No. | Komponen | Jumlah |
|---|---|---:|
| 1 | Arduino Nano | 1 |
| 2 | Breadboard | 1 |
| 3 | HC-SR04 Ultrasonic Sensor | 1 |
| 4 | Buzzer | 1 |
| 5 | LED | 1 |
| 6 | Resistor 220Ω | 1 |
| 7 | Kabel jumper male-male | Secukupnya |
| 8 | Kabel USB Mini-B | 1 |

---

# 3. Pin Arduino Nano

Pin Arduino Nano yang digunakan:

| Pin Arduino Nano | Fungsi |
|---|---|
| D3 | Buzzer |
| D4 | LED |
| D9 | HC-SR04 TRIG |
| D10 | HC-SR04 ECHO |
| 5V | Sumber tegangan |
| GND | Ground |

---

# 4. Koneksi Komponen

## 4.1 Arduino Nano → Breadboard

Posisikan Arduino Nano melintang pada celah tengah breadboard.

Kemudian hubungkan:

| Arduino Nano | Breadboard |
|---|---|
| 5V | Rail `+` |
| GND | Rail `-` |

Diagram:

```text
Arduino Nano

5V  ─────────────────► Rail +

GND ─────────────────► Rail -
```

Rail `+` digunakan sebagai jalur tegangan 5V.

Rail `-` digunakan sebagai jalur GND.

> **Penting:** Jangan menghubungkan rail `+` dan rail `-` secara langsung karena dapat menyebabkan short circuit.

---

## 4.2 HC-SR04

HC-SR04 memiliki empat pin:

```text
VCC
TRIG
ECHO
GND
```

Hubungkan:

| HC-SR04 | Terhubung ke |
|---|---|
| VCC | Rail `+` |
| TRIG | Arduino D9 |
| ECHO | Arduino D10 |
| GND | Rail `-` |

Diagram:

```text
              HC-SR04
           ┌────────────┐
Rail + ───►│ VCC        │
D9 ───────►│ TRIG       │
D10 ──────►│ ECHO       │
Rail - ───►│ GND        │
           └────────────┘
```

---

## 4.3 Buzzer

Hubungkan buzzer:

| Buzzer | Terhubung ke |
|---|---|
| `+` | Arduino D3 |
| `-` | Rail `-` |

Diagram:

```text
Arduino D3
    │
    ▼
 Buzzer (+)

 Buzzer (-)
    │
    ▼
 Rail -
```

---

## 4.4 LED dan Resistor

LED digunakan sebagai indikator tambahan.

LED harus menggunakan **resistor 220Ω**.

Susunan rangkaian:

```text
Arduino D4
    │
    ▼
Resistor 220Ω
    │
    ▼
LED Anoda (+)
    │
LED Katoda (-)
    │
    ▼
Rail -
```

Koneksi:

| Komponen | Terhubung ke |
|---|---|
| Arduino D4 | Resistor 220Ω |
| Resistor 220Ω | LED Anoda (+) |
| LED Katoda (-) | Rail `-` |

### Identifikasi Kaki LED

Umumnya:

- Kaki panjang → Anoda (+)
- Kaki pendek → Katoda (-)
- Sisi bodi LED yang datar → Katoda (-)

---

# 5. Tahap Perakitan

Perakitan dilakukan secara bertahap agar setiap bagian rangkaian dapat diperiksa sebelum memasang komponen berikutnya.

> **Tips:** Saat memasang atau mengubah kabel, sebaiknya cabut USB Arduino Nano terlebih dahulu.

---

## Tahap 1 — Membuat Jalur Power

Pastikan Arduino Nano sudah berada pada posisi yang benar di breadboard.

Hubungkan:

```text
Arduino Nano 5V
      │
      └──────────────► Rail +

Arduino Nano GND
      │
      └──────────────► Rail -
```

Pada tahap ini belum perlu memasang:

- HC-SR04
- Buzzer
- LED
- Resistor

### Pemeriksaan

Pastikan:

```text
5V tidak terhubung langsung ke GND
```

Setelah yakin koneksi benar, Arduino Nano dapat dihubungkan ke USB untuk mendapatkan daya.

---

## Tahap 2 — Memasang HC-SR04

Hubungkan:

```text
HC-SR04 VCC
      │
      └──────────────► Rail +

HC-SR04 GND
      │
      └──────────────► Rail -

HC-SR04 TRIG
      │
      └──────────────► Arduino D9

HC-SR04 ECHO
      │
      └──────────────► Arduino D10
```

Tabel:

| HC-SR04 | Terhubung ke |
|---|---|
| VCC | Rail `+` |
| TRIG | Arduino D9 |
| ECHO | Arduino D10 |
| GND | Rail `-` |

---

## Tahap 3 — Memasang Buzzer

Hubungkan:

```text
Arduino D3
    │
    ▼
Buzzer (+)

Buzzer (-)
    │
    ▼
Rail -
```

Buzzer akan menghasilkan bunyi berdasarkan jarak objek yang terdeteksi.

---

## Tahap 4 — Memasang LED

Hubungkan:

```text
Arduino D4
    │
    ▼
Resistor 220Ω
    │
    ▼
LED Anoda (+)
    │
LED Katoda (-)
    │
    ▼
Rail -
```

Pastikan LED tidak dipasang langsung ke pin Arduino tanpa resistor.

---

# 6. Tabel Koneksi Lengkap

| No. | Komponen | Pin | Terhubung ke |
|---|---|---|---|
| 1 | Arduino Nano | 5V | Rail `+` |
| 2 | Arduino Nano | GND | Rail `-` |
| 3 | HC-SR04 | VCC | Rail `+` |
| 4 | HC-SR04 | TRIG | Arduino D9 |
| 5 | HC-SR04 | ECHO | Arduino D10 |
| 6 | HC-SR04 | GND | Rail `-` |
| 7 | Buzzer | `+` | Arduino D3 |
| 8 | Buzzer | `-` | Rail `-` |
| 9 | Resistor 220Ω | Kaki 1 | Arduino D4 |
| 10 | Resistor 220Ω | Kaki 2 | LED Anoda (+) |
| 11 | LED | Anoda (+) | Resistor 220Ω |
| 12 | LED | Katoda (-) | Rail `-` |

---

# 7. Struktur Project

Struktur project:

```text
smart-blind-stick/
├── .gitignore
├── diagram.json
├── README.md
├── smart-blind-stick.ino
├── wokwi.toml
└── build/
    └── arduino.avr.nano/
        ├── smart-blind-stick.ino.eep
        ├── smart-blind-stick.ino.elf
        ├── smart-blind-stick.ino.hex
        ├── smart-blind-stick.ino.with_bootloader.bin
        └── smart-blind-stick.ino.with_bootloader.hex
```

Folder `build/` berisi hasil kompilasi dan sebaiknya diabaikan oleh Git.

Contoh `.gitignore`:

```gitignore
/build/

*.hex
*.elf
*.eep
*.bin

*.tmp
*.bak
*.swp
*.swo

.DS_Store
Thumbs.db

.vscode/
.idea/
*.code-workspace

*.log
```

---

# 8. Persiapan Software

Project dapat digunakan melalui dua workflow:

| Tool | Kegunaan |
|---|---|
| Arduino CLI | Compile, upload, dan Serial Monitor melalui terminal |
| Arduino IDE | Compile, upload, dan Serial Monitor melalui GUI |
| Wokwi | Simulasi rangkaian |

Arduino CLI dan Arduino IDE dapat digunakan untuk project yang sama.

Tidak perlu menjalankan keduanya secara bersamaan ketika menggunakan port serial yang sama.

---

# 9. Arduino CLI

## 9.1 Masuk ke Folder Project

Buka terminal:

```bash
cd ~/pemrograman/iot/smart-blind-stick
```

Cek lokasi:

```bash
pwd
```

Hasil yang diharapkan:

```text
/home/all/pemrograman/iot/smart-blind-stick
```

---

## 9.2 Mengecek Arduino Nano

Hubungkan Arduino Nano menggunakan kabel USB.

Kemudian:

```bash
arduino-cli board list
```

Contoh:

```text
Port         Protocol Type              Board Name FQBN Core
/dev/ttyUSB0 serial   Serial Port       Unknown
```

Pada Arduino Nano clone, board dapat ditampilkan sebagai `Unknown`.

Hal tersebut tidak selalu berarti board bermasalah selama port seperti `/dev/ttyUSB0` terdeteksi.

---

## 9.3 Compile Project

Gunakan:

```bash
arduino-cli compile \
  --fqbn arduino:avr:nano \
  --output-dir build/arduino.avr.nano \
  .
```

Jika berhasil, akan muncul informasi penggunaan flash dan RAM.

Contoh:

```text
Sketch uses 4972 bytes (16%) of program storage space.
Global variables use 270 bytes (13%) of dynamic memory.
```

Hasil compile berada di:

```text
build/arduino.avr.nano/
```

---

## 9.4 Upload Program

Arduino Nano yang digunakan menggunakan bootloader lama.

Gunakan:

```bash
arduino-cli upload \
  --fqbn arduino:avr:nano:cpu=atmega328old \
  --port /dev/ttyUSB0 \
  .
```

Jika berhasil, Arduino Nano akan melakukan restart dan menjalankan program secara otomatis.

Jika port berbeda, misalnya:

```text
/dev/ttyUSB1
```

ubah:

```bash
--port /dev/ttyUSB0
```

menjadi:

```bash
--port /dev/ttyUSB1
```

Cek port dengan:

```bash
arduino-cli board list
```

---

## 9.5 Serial Monitor

Untuk melihat log:

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

Contoh output:

```text
Smart Blind Stick Ready!
Jarak objek: 52.31 cm
Jarak objek: 51.87 cm
Jarak objek: 51.42 cm
Jarak objek: 50.96 cm
```

Project menggunakan:

```text
9600 baud
```

---

## 9.6 Serial Monitor dengan Timestamp

Gunakan:

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600 \
  --timestamp
```

---

## Menghentikan Arduino CLI Monitor

Tekan:

```text
Ctrl + C
```

`Ctrl + C` hanya menghentikan Serial Monitor.

Program pada Arduino Nano tetap berjalan selama Nano masih mendapatkan daya.

Jika ingin mematikan Nano:

1. Tekan `Ctrl + C`.
2. Cabut kabel USB.

---

# 10. Arduino IDE

Arduino IDE dapat digunakan sebagai alternatif Arduino CLI.

Arduino IDE menyediakan antarmuka grafis untuk:

- Membuka project
- Memilih board
- Memilih processor
- Memilih port
- Verify / Compile
- Upload
- Serial Monitor

---

## 10.1 Membuka Project

Buka Arduino IDE.

Kemudian buka file:

```text
smart-blind-stick.ino
```

Lokasi:

```text
~/pemrograman/iot/smart-blind-stick/smart-blind-stick.ino
```

Project Arduino sebaiknya dibuka melalui file `.ino` utama.

---

## 10.2 Memilih Board

Pada Arduino IDE, pilih:

```text
Tools
→ Board
→ Arduino AVR Boards
→ Arduino Nano
```

Board yang dipilih:

```text
Arduino Nano
```

---

## 10.3 Memilih Processor

Karena Nano yang digunakan menggunakan bootloader lama, pilih:

```text
Tools
→ Processor
→ ATmega328P (Old Bootloader)
```

Jika Arduino IDE menggunakan tampilan baru, pilihan tersebut tetap berada di bagian pengaturan board/processor Nano.

> **Penting:** Pilihan `ATmega328P (Old Bootloader)` harus sesuai dengan konfigurasi yang berhasil digunakan melalui Arduino CLI.

---

## 10.4 Memilih Port

Hubungkan Arduino Nano ke USB.

Kemudian pilih:

```text
Tools
→ Port
→ /dev/ttyUSB0
```

Port dapat berbeda pada setiap komputer.

Jika tidak mengetahui port yang digunakan, cek melalui terminal:

```bash
arduino-cli board list
```

Contoh:

```text
/dev/ttyUSB0
```

Kemudian pilih port tersebut di Arduino IDE.

---

## 10.5 Verify / Compile

Untuk melakukan compile tanpa upload:

Klik tombol:

```text
✓ Verify
```

atau pilih:

```text
Sketch
→ Verify/Compile
```

Arduino IDE akan memeriksa kode dan melakukan compile.

Jika berhasil, akan muncul pesan seperti:

```text
Done compiling.
```

---

## 10.6 Upload

Setelah board, processor, dan port sudah benar:

Klik tombol:

```text
→ Upload
```

atau pilih:

```text
Sketch
→ Upload
```

Arduino IDE akan:

1. Compile sketch.
2. Menghubungkan ke Arduino Nano.
3. Meng-upload program.
4. Restart Arduino Nano.
5. Menjalankan program.

Jika berhasil, biasanya muncul:

```text
Done uploading.
```

---

## 10.7 Serial Monitor

Untuk melihat log melalui Arduino IDE:

Pilih:

```text
Tools
→ Serial Monitor
```

atau gunakan tombol Serial Monitor pada antarmuka Arduino IDE.

Atur baud rate menjadi:

```text
9600 baud
```

Output akan terlihat seperti:

```text
Smart Blind Stick Ready!
Jarak objek: 52.31 cm
Jarak objek: 51.87 cm
Jarak objek: 51.42 cm
Jarak objek: 50.96 cm
```

### Penting

Jangan menjalankan:

```text
Arduino IDE Serial Monitor
```

dan:

```text
arduino-cli monitor
```

secara bersamaan pada:

```text
/dev/ttyUSB0
```

Gunakan salah satu Serial Monitor saja.

---

# 11. Perilaku Sistem

Sistem menentukan kecepatan bunyi buzzer dan kedipan LED berdasarkan jarak objek.

| Jarak Objek | Buzzer | LED |
|---:|---|---|
| > 100 cm | Mati | Mati |
| 71–100 cm | Lambat | Berkedip lambat |
| 41–70 cm | Lebih cepat | Berkedip lebih cepat |
| 11–40 cm | Cepat | Berkedip cepat |
| ≤ 10 cm | Sangat cepat | Berkedip sangat cepat |

Semakin dekat objek dengan sensor, semakin cepat interval peringatan.

---

# 12. Alur Kerja Program

```text
Arduino Nano menyala
        │
        ▼
HC-SR04 mengukur jarak
        │
        ▼
Apakah objek terdeteksi?
        │
        ├── Tidak
        │     │
        │     ├── Buzzer OFF
        │     └── LED OFF
        │
        └── Ya
              │
              ▼
       Hitung jarak objek
              │
              ▼
     Tentukan interval peringatan
              │
              ├── Buzzer berbunyi
              │
              ├── LED berkedip
              │
              └── Jarak dikirim
                  ke Serial Monitor
```

---

# 13. Urutan Penggunaan Project

## 13.1 Menggunakan Arduino CLI

### 1. Masuk ke folder project

```bash
cd ~/pemrograman/iot/smart-blind-stick
```

### 2. Hubungkan Arduino Nano

Hubungkan Arduino Nano menggunakan USB.

### 3. Cek port

```bash
arduino-cli board list
```

Pastikan terdapat:

```text
/dev/ttyUSB0
```

### 4. Compile

```bash
arduino-cli compile \
  --fqbn arduino:avr:nano \
  --output-dir build/arduino.avr.nano \
  .
```

### 5. Upload

```bash
arduino-cli upload \
  --fqbn arduino:avr:nano:cpu=atmega328old \
  --port /dev/ttyUSB0 \
  .
```

### 6. Lihat log

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

### 7. Hentikan log

Tekan:

```text
Ctrl + C
```

---

## 13.2 Menggunakan Arduino IDE

### 1. Buka project

Buka:

```text
smart-blind-stick.ino
```

di Arduino IDE.

### 2. Pilih board

```text
Tools
→ Board
→ Arduino AVR Boards
→ Arduino Nano
```

### 3. Pilih processor

```text
Tools
→ Processor
→ ATmega328P (Old Bootloader)
```

### 4. Pilih port

```text
Tools
→ Port
→ /dev/ttyUSB0
```

### 5. Verify

Klik:

```text
✓ Verify
```

### 6. Upload

Klik:

```text
→ Upload
```

### 7. Buka Serial Monitor

Pilih:

```text
Tools
→ Serial Monitor
```

Atur:

```text
9600 baud
```

---

# 14. Troubleshooting

## 14.1 Arduino Tidak Terdeteksi

### Arduino CLI

Jalankan:

```bash
arduino-cli board list
```

Jika tidak muncul `/dev/ttyUSB0`, periksa:

- Kabel USB.
- Koneksi Arduino Nano.
- Port USB komputer.
- LED power Arduino Nano.
- Apakah kabel USB mendukung data.

### Arduino IDE

Periksa:

```text
Tools
→ Port
```

Jika tidak ada port Arduino:

1. Cabut USB.
2. Tunggu beberapa detik.
3. Hubungkan kembali USB.
4. Periksa kembali `Tools → Port`.

---

## 14.2 Permission Denied

Jika Arduino CLI menghasilkan:

```text
Permission denied
```

periksa:

```bash
ls -l /dev/ttyUSB0
```

Contoh:

```text
crw-rw---- 1 root dialout ...
```

Periksa group:

```bash
groups
```

Jika belum terdapat `dialout`:

```bash
sudo usermod -aG dialout $USER
```

Kemudian logout dan login kembali.

Untuk menerapkan group pada terminal saat ini:

```bash
newgrp dialout
```

Kemudian:

```bash
groups
```

Pastikan `dialout` sudah muncul.

---

## 14.3 Upload Gagal

Jika muncul:

```text
programmer is not responding
```

atau:

```text
not in sync
```

coba gunakan bootloader lama melalui Arduino CLI:

```bash
arduino-cli upload \
  --fqbn arduino:avr:nano:cpu=atmega328old \
  --port /dev/ttyUSB0 \
  .
```

Melalui Arduino IDE:

```text
Tools
→ Board
→ Arduino Nano

Tools
→ Processor
→ ATmega328P (Old Bootloader)

Tools
→ Port
→ /dev/ttyUSB0
```

Kemudian upload kembali.

---

## 14.4 Serial Monitor Tidak Menampilkan Log

Pastikan baud rate adalah:

```text
9600
```

### Arduino CLI

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

### Arduino IDE

Buka:

```text
Tools
→ Serial Monitor
```

Kemudian pilih:

```text
9600 baud
```

Pastikan tidak ada program lain yang sedang menggunakan `/dev/ttyUSB0`.

Jangan membuka dua Serial Monitor secara bersamaan.

---

# 15. Catatan Perakitan

Sebelum menghubungkan Arduino Nano ke USB, periksa kembali:

- `5V` tidak terhubung langsung ke `GND`.
- HC-SR04 `VCC` terhubung ke `5V`.
- HC-SR04 `GND` terhubung ke `GND`.
- HC-SR04 `TRIG` terhubung ke `D9`.
- HC-SR04 `ECHO` terhubung ke `D10`.
- Buzzer `+` terhubung ke `D3`.
- Buzzer `-` terhubung ke `GND`.
- LED menggunakan resistor `220Ω`.
- LED Anoda (+) terhubung melalui resistor ke `D4`.
- LED Katoda (-) terhubung ke `GND`.

Jika sedang mengubah atau memasang kabel, sebaiknya:

```text
Cabut USB
    ↓
Pasang / ubah kabel
    ↓
Periksa rangkaian
    ↓
Hubungkan USB kembali
```

---

# 16. Catatan Keselamatan

Project ini merupakan prototype sederhana untuk mendeteksi objek menggunakan sensor ultrasonik.

HC-SR04 memiliki keterbatasan dalam mendeteksi objek berdasarkan:

- Bentuk objek
- Material objek
- Sudut permukaan objek
- Posisi objek
- Kondisi lingkungan
- Jarak objek

Prototype ini **bukan pengganti alat bantu mobilitas yang telah diuji dan disertifikasi**.

Pengujian sebaiknya dilakukan pada lingkungan yang aman dan menggunakan objek yang mudah dideteksi oleh sensor.

---

# 17. Informasi Project

| Informasi | Detail |
|---|---|
| Nama Project | Smart Blind Stick |
| Mikrokontroler | Arduino Nano |
| Sensor | HC-SR04 Ultrasonic |
| Output | Buzzer + LED |
| Development Tool | Arduino CLI + Arduino IDE |
| Simulator | Wokwi |
| Serial Communication | 9600 baud |
| Port USB | `/dev/ttyUSB0` |
| Bootloader | ATmega328P Old Bootloader |

---

# 18. Quick Commands

Bagian ini berisi perintah Arduino CLI yang paling sering digunakan.

## Masuk ke project

```bash
cd ~/pemrograman/iot/smart-blind-stick
```

## Cek Arduino

```bash
arduino-cli board list
```

## Compile

```bash
arduino-cli compile \
  --fqbn arduino:avr:nano \
  --output-dir build/arduino.avr.nano \
  .
```

## Upload

```bash
arduino-cli upload \
  --fqbn arduino:avr:nano:cpu=atmega328old \
  --port /dev/ttyUSB0 \
  .
```

## Melihat log

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

## Melihat log dengan timestamp

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600 \
  --timestamp
```

## Menghentikan log

```text
Ctrl + C
```

---

# Smart Blind Stick

Prototype Arduino Nano untuk mendeteksi objek menggunakan **HC-SR04** dan memberikan peringatan melalui **buzzer** serta **LED**.