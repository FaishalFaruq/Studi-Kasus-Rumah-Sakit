#include "[1]dataPenyakitPasien.h"
#include "[2]pendataanObat.h"
#include "[4]wifi.h"
#include "[7]BPJS_Gratis.h"
#include "[10]Pembayaran.h"
#include "[11]Antrian.h"
#include "[12]Parkir.h"
#include "[13]CS.h"
#include <iostream>
using namespace std;

int main()
{
    int pilihan;
    ManajemenPasien dataPenyakit;
    Pembayaran pembayaran;
    RumahSakitWiFi rumahsakitWifi;
    ManajemenObat pendataanObat;
    AntrianRumahSakit antrianRs;
    ParkirRumahSakit parkirRs;
    Cstmr_srvc Cs;
    BPJS bpjs;

    cout << "Rumah Sakit Sejahtera" << endl;
    cout << endl;
    // UNTUK PILIHAN MENU TOLONG SAMAKAN DENGAN NOMOR KELOMPOK
    cout << "Silahkan pilih menu!" << endl;
    cout << "1. Data Penyakit Pasien" << endl;
    cout << "2. Pendataan Obat" << endl;
    cout << "4. Fasilitas Wifi RS" << endl;
    cout << "7. BPJS Gratis" << endl;
    cout << "10. Pembayaran" << endl;
    cout << "11. Antrian" << endl;
    cout << "12. Parkir" << endl;
    cout << "13. Customer Service" << endl;
    cout << endl;
    cout << "Pilihan Menu : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        dataPenyakit.tampilkanPengisianDataPenyakit();
        break;
    case 2:
        pendataanObat.pilihanObat();
        break;
    case 4:
        rumahsakitWifi.dataWifi();
        break;
    case 7:
        bpjs.inputBJPS();
        break;
    case 10:
        pembayaran.menuPembayaran();
        break;
    case 11:
        antrianRs.inputAntrian();
    case 12:
        parkirRs.output();
        break;
    case 13:
        Cs.pilih();
        break;
    }
}

// #include "obat.h"
// #include <iostream>

// // Inisialisasi array data obat dan jumlah obat
// Obat database[] = {
//     {"Obat1", 20}, {"Obat2", 15}, {"Obat3", 30},
//     // Tambahkan data obat yang sudah ada di sini
// };
// int jumlahObat = sizeof(database) / sizeof(database[0]);

// // Fungsi untuk menampilkan semua obat dalam database
// void tampilkanObat() {
//   std::cout << "Daftar Obat:" << std::endl;
//   for (int i = 0; i < jumlahObat; i++) {
//     std::cout << "Nama: " << database[i].nama << ", Stok: " << database[i].stok
//               << std::endl;
//   }
//   std::cout << std::endl;
// }

// // Fungsi untuk mengambil obat dari stok
// void ambilObat() {
//   std::string namaObat;
//   std::cout << "Masukkan nama obat yang ingin diambil: ";
//   std::cin >> namaObat;

//   bool ditemukan = false;

//   for (int i = 0; i < jumlahObat; i++) {
//     if (database[i].nama == namaObat) {
//       int jumlah;
//       std::cout << "Masukkan jumlah obat yang ingin diambil: ";
//       std::cin >> jumlah;

//       if (jumlah > 0 && jumlah <= database[i].stok) {
//         database[i].stok -= jumlah;
//         std::cout << "Obat berhasil diambil!" << std::endl;
//         std::cout << "Stok sisa: " << database[i].stok << std::endl;
//       } else {
//         std::cout << "Jumlah tidak valid atau stok tidak mencukupi."
//                   << std::endl;
//       }

//       ditemukan = true;
//       break;
//     }
//   }

//   if (!ditemukan) {
//     std::cout << "Obat tidak ditemukan." << std::endl;
//   }
//   std::cout << std::endl;
// }

// int main() {
//   int pilihan;

//   do {
//     std::cout << "Menu:" << std::endl;
//     std::cout << "1. Tampilkan Semua Obat" << std::endl;
//     std::cout << "2. Ambil Obat" << std::endl;
//     std::cout << "3. Keluar" << std::endl;
//     std::cout << "Pilih menu (1/2/3): ";
//     std::cin >> pilihan;

//     switch (pilihan) {
//     case 1:
//       tampilkanObat();
//       break;
//     case 2:
//       ambilObat();
//       break;
//     case 3:
//       std::cout << "Terima kasih! Program selesai." << std::endl;
//       break;
//     default:
//       std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
//       break;
//     }

//   } while (pilihan != 3);

//   return 0;
// }
