// #include <fstream>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// class RumahSakit {
// private:
//   struct Pasien {
//     string nama;
//     string alasan;
//     int lamaMenginap;
//     int ruangan;
//     double biaya;

//     Pasien(string n, string a, int lm, int r)
//         : nama(n), alasan(a), lamaMenginap(lm), ruangan(r) {
//       biaya = 2000 * lamaMenginap;
//     }
//   };

//   vector<Pasien> pasienList;

// public:
//   RumahSakit() {
//     ifstream file("data_pasien_inap.txt");

//     if (file.is_open()) {
//       string nama, alasan;
//       int lamaMenginap, ruangan;
//       double biaya;

//       while (getline(file, nama)) {
//         getline(file, alasan);
//         file >> lamaMenginap;
//         file >> ruangan;
//         file >> biaya;
//         file.ignore();

//         Pasien pasien(nama, alasan, lamaMenginap, ruangan);
//         pasienList.push_back(pasien);
//       }

//       file.close();
//     }
//   }

//   void tambahPasien() {
//     string nama, alasan;
//     int lamaMenginap, ruangan;

//     cout << endl;
//     cout << "Masukkan nama pasien: ";
//     cin.ignore();
//     getline(cin, nama);

//     cout << "Alasan pasien rawat inap: ";
//     getline(cin, alasan);

//     cout << "Berapa lama pasien menginap (hari): ";
//     cin >> lamaMenginap;

//     cout << "Pilih nomor ruangan (1-20): ";
//     cin >> ruangan;

//     bool ruanganTersedia = true;
//     for (const Pasien &pasien : pasienList) {
//       if (pasien.ruangan == ruangan) {
//         ruanganTersedia = false;
//         break;
//       }
//     }

//     if (!ruanganTersedia || ruangan < 1 || ruangan > 20) {
//       cout << "Ruangan tidak tersedia atau nomor ruangan tidak valid." << endl;
//       return;
//     }

//     Pasien pasien(nama, alasan, lamaMenginap, ruangan);
//     pasienList.push_back(pasien);

//     cout << "Pasien berhasil ditambahkan ke dalam sistem." << endl;
//   }

//   void tampilkanPasien() {
//     cout << "Data Pasien Rawat Inap:" << endl;
//     for (const Pasien &pasien : pasienList) {
//       cout << "---------------------------" << endl;
//       cout << "Nama: " << pasien.nama << endl;
//       cout << "Alasan Rawat Inap: " << pasien.alasan << endl;
//       cout << "Lama Menginap (hari): " << pasien.lamaMenginap << endl;
//       cout << "Ruangan: " << pasien.ruangan << endl;
//       cout << "Biaya: Rp" << pasien.biaya << endl;
//       cout << "---------------------------" << endl;
//       cout << endl;
//     }
//   }

//   void keluarProgram() {
//     ofstream file("data_pasien_inap.txt");

//     for (const Pasien &pasien : pasienList) {
//       file << pasien.nama << endl;
//       file << pasien.alasan << endl;
//       file << pasien.lamaMenginap << endl;
//       file << pasien.ruangan << endl;
//       file << pasien.biaya << endl;
//     }

//     file.close();
//     exit(0);
//   }

//   void run() {
//     while (true) {
//       cout << "Menu Utama:" << endl;
//       cout << "1. Tambah Pasien Rawat Inap" << endl;
//       cout << "2. Tampilkan Pasien Rawat Inap" << endl;
//       cout << "3. Keluar" << endl;

//       int pilihan;
//       cout << "Pilih menu: ";
//       cin >> pilihan;

//       switch (pilihan) {
//       case 1:
//         tambahPasien();
//         break;
//       case 2:
//         tampilkanPasien();
//         break;
//       case 3:
//         keluarProgram();
//         break;
//       default:
//         cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
//       }
//     }
//   }
// };

// int main() {
//   RumahSakit rumahSakit;
//   rumahSakit.run();
//   return 0;
// }
