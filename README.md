# Smart Blind Stick

Prototype tongkat pintar berbasis **Arduino Nano** yang menggunakan sensor ultrasonik **HC-SR04** untuk mendeteksi objek di depan pengguna.

Sistem memberikan peringatan melalui:

- 🔊 Buzzer berdasarkan jarak objek
- 🔴 LED sebagai indikator visual
- 📟 Serial Monitor untuk melihat hasil pembacaan jarak

Project ini dikembangkan menggunakan **Arduino CLI**, **Arduino Nano**, dan disimulasikan menggunakan **Wokwi**.

---

## 1. Komponen

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

## 2. Pin Arduino Nano

Pin Arduino Nano yang digunakan dalam project:

| Pin Arduino Nano | Fungsi |
|---|---|
| D3 | Buzzer |
| D4 | LED |
| D9 | HC-SR04 TRIG |
| D10 | HC-SR04 ECHO |
| 5V | Sumber tegangan |
| GND | Ground |

---

# 3. Koneksi Komponen

## 3.1 Arduino Nano → Breadboard

Pertama, posisikan Arduino Nano melintang pada celah tengah breadboard.

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

# 4. Tahap Perakitan

Perakitan dilakukan secara bertahap agar setiap bagian rangkaian dapat diperiksa terlebih dahulu sebelum memasang komponen berikutnya.

---

## Tahap 1 — Membuat Jalur Power

Pastikan Arduino Nano sudah berada pada posisi yang benar di breadboard.

Kemudian hubungkan:

```text
Arduino Nano 5V
      │
      └──────────────► Rail +

Arduino Nano GND
      │
      └──────────────► Rail -
```

Pada tahap ini belum perlu memasang HC-SR04, buzzer, LED, atau resistor.

### Pemeriksaan

Pastikan:

```text
5V tidak terhubung langsung ke GND
```

Setelah yakin koneksi benar, Arduino Nano dapat dihubungkan ke USB untuk mendapatkan daya.

---

## Tahap 2 — Memasang HC-SR04

HC-SR04 memiliki empat pin:

```text
VCC
TRIG
ECHO
GND
```

Hubungkan sebagai berikut:

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

## Tahap 3 — Memasang Buzzer

Hubungkan buzzer sebagai berikut:

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

Buzzer akan menghasilkan bunyi berdasarkan jarak objek yang terdeteksi oleh HC-SR04.

---

## Tahap 4 — Memasang LED

LED digunakan sebagai indikator tambahan.

LED harus menggunakan **resistor 220Ω**.

Hubungkan dengan susunan:

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

### Koneksi

| Komponen | Terhubung ke |
|---|---|
| Arduino D4 | Resistor 220Ω |
| Resistor 220Ω | LED Anoda (+) |
| LED Katoda (-) | Rail `-` |

### Identifikasi kaki LED

Umumnya:

- Kaki panjang → Anoda (+)
- Kaki pendek → Katoda (-)
- Sisi bodi LED yang datar → Katoda (-)

---

# 5. Tabel Koneksi Lengkap

Berikut seluruh koneksi yang digunakan:

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

# 6. Struktur Project

Struktur project:

```text
smart-blind-stick/
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

Folder `build/` berisi hasil kompilasi project.

Folder tersebut dapat dimasukkan ke `.gitignore` jika project akan menggunakan Git.

---

# 7. Masuk ke Folder Project

Buka terminal dan jalankan:

```bash
cd ~/pemrograman/iot/smart-blind-stick
```

Untuk memastikan berada di folder yang benar:

```bash
pwd
```

Hasil yang diharapkan:

```text
/home/all/pemrograman/iot/smart-blind-stick
```

---

# 8. Mengecek Arduino Nano

Hubungkan Arduino Nano menggunakan kabel USB.

Kemudian jalankan:

```bash
arduino-cli board list
```

Contoh hasil:

```text
Port         Protocol Type              Board Name FQBN Core
/dev/ttyUSB0 serial   Serial Port       Unknown
```

Pada Arduino Nano clone, board dapat ditampilkan sebagai `Unknown`.

Hal tersebut tidak selalu berarti board bermasalah selama port seperti `/dev/ttyUSB0` terdeteksi.

---

# 9. Compile / Build Project

Untuk melakukan compile project:

```bash
arduino-cli compile \
  --fqbn arduino:avr:nano \
  --output-dir build/arduino.avr.nano \
  .
```

Jika berhasil, akan muncul informasi penggunaan flash dan RAM, misalnya:

```text
Sketch uses 4972 bytes (16%) of program storage space.
Global variables use 270 bytes (13%) of dynamic memory.
```

File hasil compile akan berada di:

```text
build/arduino.avr.nano/
```

---

# 10. Upload Program ke Arduino Nano

Arduino Nano yang digunakan menggunakan bootloader lama, sehingga perintah upload yang digunakan adalah:

```bash
arduino-cli upload \
  --fqbn arduino:avr:nano:cpu=atmega328old \
  --port /dev/ttyUSB0 \
  .
```

Jika upload berhasil, Arduino Nano akan melakukan restart dan menjalankan program secara otomatis.

> Jika port Arduino berbeda, misalnya `/dev/ttyUSB1`, sesuaikan bagian `--port`.

Untuk mengetahui port yang digunakan:

```bash
arduino-cli board list
```

---

# 11. Melihat Log / Serial Monitor

Program mengirimkan hasil pembacaan jarak melalui komunikasi serial.

Untuk membuka Serial Monitor:

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

Jika HC-SR04 sudah terpasang, output akan terlihat seperti:

```text
Smart Blind Stick Ready!
Jarak objek: 52.31 cm
Jarak objek: 51.87 cm
Jarak objek: 51.42 cm
Jarak objek: 50.96 cm
```

Nilai jarak akan berubah sesuai dengan posisi objek di depan sensor.

### Baud Rate

Project menggunakan:

```text
9600 baud
```

Oleh karena itu Serial Monitor juga harus menggunakan:

```text
9600 baud
```

---

# 12. Serial Monitor dengan Timestamp

Untuk menampilkan timestamp pada setiap data:

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600 \
  --timestamp
```

---

# 13. Menghentikan Serial Monitor

Untuk menghentikan Serial Monitor, tekan:

```text
Ctrl + C
```

Perintah tersebut hanya menghentikan tampilan log.

Arduino Nano **tetap menjalankan program** selama masih mendapatkan daya.

Jika ingin melihat log kembali, jalankan lagi:

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

---

# 14. Mematikan Arduino Nano

Jika ingin benar-benar mematikan Arduino Nano:

1. Tekan `Ctrl + C` untuk menghentikan Serial Monitor.
2. Cabut kabel USB dari Arduino Nano.

Urutannya:

```text
Serial Monitor
      │
      ▼
Ctrl + C
      │
      ▼
Serial Monitor berhenti
      │
      ▼
Cabut USB
      │
      ▼
Arduino Nano mati
```

Jika hanya ingin berhenti melihat log, **tidak perlu mencabut USB**.

---

# 15. Perilaku Sistem

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

# 16. Alur Kerja Program

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

# 17. Urutan Penggunaan Project

Urutan penggunaan yang direkomendasikan:

## 1. Masuk ke folder project

```bash
cd ~/pemrograman/iot/smart-blind-stick
```

## 2. Hubungkan Arduino Nano

Hubungkan Arduino Nano menggunakan kabel USB.

## 3. Cek port Arduino

```bash
arduino-cli board list
```

Pastikan terdapat port seperti:

```text
/dev/ttyUSB0
```

## 4. Compile project

```bash
arduino-cli compile \
  --fqbn arduino:avr:nano \
  --output-dir build/arduino.avr.nano \
  .
```

## 5. Upload program

Karena Nano menggunakan bootloader lama:

```bash
arduino-cli upload \
  --fqbn arduino:avr:nano:cpu=atmega328old \
  --port /dev/ttyUSB0 \
  .
```

## 6. Buka Serial Monitor

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

## 7. Hentikan Serial Monitor

Tekan:

```text
Ctrl + C
```

---

# 18. Troubleshooting

## 18.1 Arduino Tidak Terdeteksi

Jalankan:

```bash
arduino-cli board list
```

Jika tidak muncul `/dev/ttyUSB0`, periksa:

- Kabel USB
- Koneksi Arduino Nano
- Port USB komputer
- Apakah LED power Arduino menyala

---

## 18.2 Permission Denied

Jika muncul:

```text
Permission denied
```

periksa permission port:

```bash
ls -l /dev/ttyUSB0
```

Contoh:

```text
crw-rw---- 1 root dialout ...
```

Kemudian periksa group user:

```bash
groups
```

Jika belum terdapat `dialout`, jalankan:

```bash
sudo usermod -aG dialout $USER
```

Kemudian logout dan login kembali.

Untuk menerapkan group `dialout` pada terminal saat ini:

```bash
newgrp dialout
```

Kemudian cek:

```bash
groups
```

Pastikan `dialout` sudah muncul.

---

## 18.3 Upload Gagal / Programmer Tidak Merespons

Jika muncul:

```text
programmer is not responding
```

atau:

```text
not in sync
```

gunakan konfigurasi bootloader lama:

```bash
arduino-cli upload \
  --fqbn arduino:avr:nano:cpu=atmega328old \
  --port /dev/ttyUSB0 \
  .
```

---

## 18.4 Serial Monitor Tidak Menampilkan Log

Pastikan Serial Monitor menggunakan baud rate:

```text
9600
```

Jalankan:

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

Pastikan tidak ada program lain yang sedang menggunakan `/dev/ttyUSB0`.

Contohnya, jangan membuka:

```text
Arduino IDE Serial Monitor
```

dan:

```text
arduino-cli monitor
```

secara bersamaan pada port yang sama.

---

# 19. Catatan Perakitan

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

---

# 20. Catatan Keselamatan

Project ini merupakan prototype sederhana untuk mendeteksi objek menggunakan sensor ultrasonik.

HC-SR04 memiliki keterbatasan dalam mendeteksi objek berdasarkan:

- Bentuk objek
- Material objek
- Sudut permukaan objek
- Posisi objek
- Kondisi lingkungan
- Jarak objek

Prototype ini **bukan pengganti alat bantu mobilitas yang telah diuji dan disertifikasi**.

Pengujian sebaiknya dilakukan pada lingkungan yang aman dan dengan objek yang mudah dideteksi oleh sensor.

---

# 21. Informasi Project

| Informasi | Detail |
|---|---|
| Nama Project | Smart Blind Stick |
| Mikrokontroler | Arduino Nano |
| Sensor | HC-SR04 Ultrasonic |
| Output | Buzzer + LED |
| Development Tool | Arduino CLI |
| Simulator | Wokwi |
| Serial Communication | 9600 baud |
| Port USB | `/dev/ttyUSB0` |
| Bootloader | ATmega328P Old Bootloader |

---

## Quick Commands

Perintah utama yang paling sering digunakan:

### Masuk ke project

```bash
cd ~/pemrograman/iot/smart-blind-stick
```

### Cek Arduino

```bash
arduino-cli board list
```

### Compile

```bash
arduino-cli compile \
  --fqbn arduino:avr:nano \
  --output-dir build/arduino.avr.nano \
  .
```

### Upload

```bash
arduino-cli upload \
  --fqbn arduino:avr:nano:cpu=atmega328old \
  --port /dev/ttyUSB0 \
  .
```

### Melihat log

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600
```

### Melihat log dengan timestamp

```bash
arduino-cli monitor \
  --port /dev/ttyUSB0 \
  --config baudrate=9600 \
  --timestamp
```

### Menghentikan log

```text
Ctrl + C
```

---

# Smart Blind Stick

Prototype Arduino Nano untuk mendeteksi objek menggunakan HC-SR04 dan memberikan peringatan melalui buzzer serta LED.