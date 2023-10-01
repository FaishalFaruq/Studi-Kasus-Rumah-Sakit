#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pasien
{
    string nama;
    int umur;
    bool jenisKelamin;
    int tinggiBadan;
    int beratBadan;
    string riwayatPenyakit;
    string keluhanPenyakit;
    string diagnosa;
};

class ManajemenPasien
{
private:
    Pasien pasien;

public:
    void tambahPasien(Pasien p)
    {
        pasien = p;
    }

    void simpanDataKeFile()
    {
        ofstream file("penyakit.txt", ios::app);
        if (file.is_open())
        {
            file << "===================================" << endl;
            file << "Nama                : " << pasien.nama << endl;
            file << "Umur                : " << pasien.umur << endl;
            file << "Tinggi Badan        : " << pasien.tinggiBadan << endl;
            file << "Berat Badan         : " << pasien.beratBadan << endl;
            file << "Riwayat Penyakit    : " << pasien.riwayatPenyakit << endl;
            file << "Keluhan Penyakit    : " << pasien.keluhanPenyakit << endl;
            file << "Diagnosa            : " << pasien.diagnosa << endl;
            file << "===================================" << endl;
            file << endl;

            file.close();
            cout << "Data berhasil disimpan dalam penyakit.txt" << endl;
        }
        else
        {
            cout << "Gagal membuka file penyakit.txt" << endl;
        }
    }

    void tampilkanRiwayatPenyakit()
    {
        ifstream file("penyakit.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Gagal membuka file penyakit.txt" << endl;
        }
    }
    void tampilkanPengisianDataPenyakit()
    {
        ManajemenPasien manajemen;

        enum Menu
        {
            MASUKKAN_DATA = 1,
            LIHAT_RIWAYAT,
            KELUAR
        };
        int pilihan;
        char lanjut;

        do
        {
            cout << "=== Pendataan Penyakit Pasien ===" << endl;
            cout << "1. Masukkan Data Penyakit Pasien" << endl;
            cout << "2. Lihat Riwayat Penyakit Pasien" << endl;
            cout << "3. Keluar" << endl;
            cout << "Pilih menu (" << MASUKKAN_DATA << "/" << LIHAT_RIWAYAT << "/" << KELUAR << "): ";
            cin >> pilihan;

            cin.ignore();

            switch (pilihan)
            {
            case MASUKKAN_DATA:
            {
                Pasien pasien;
                cout << "Masukkan Nama Pasien: ";
                getline(cin, pasien.nama);
                cout << "Masukkan Umur Pasien: ";
                cin >> pasien.umur;
                cout << "Masukkan Tinggi Badan Pasien: ";
                cin >> pasien.tinggiBadan;
                cout << "Masukkan Berat Badan Pasien: ";
                cin >> pasien.beratBadan;
                cin.ignore();
                cout << "Masukkan Riwayat Penyakit Pasien: ";
                getline(cin, pasien.riwayatPenyakit);
                cout << "Masukkan Keluhan Pasien: ";
                getline(cin, pasien.keluhanPenyakit);
                cout << "Masukkan Diagnosa Pasien: ";
                getline(cin, pasien.diagnosa);
                manajemen.tambahPasien(pasien);
                manajemen.simpanDataKeFile();
                break;
            }

            case LIHAT_RIWAYAT:
                cout << "=== Riwayat Penyakit Pasien ===" << endl;
                manajemen.tampilkanRiwayatPenyakit();
                break;

            case KELUAR:
                cout << "Terima kasih. Keluar dari program." << endl;

            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
            }

            cout << "Apakah Anda ingin kembali ke menu? (y/n): ";
            cin >> lanjut;
        } while (lanjut == 'y' || lanjut == 'Y');
    }
};

// int main()
// {
//     ManajemenPasien manajemen;

//     enum Menu
//     {
//         MASUKKAN_DATA = 1,
//         LIHAT_RIWAYAT,
//         KELUAR
//     };
//     int pilihan;
//     char lanjut;

//     do
//     {
//         cout << "=== Menu ===" << endl;
//         cout << "1. Masukkan Data Penyakit Pasien" << endl;
//         cout << "2. Lihat Riwayat Penyakit Pasien" << endl;
//         cout << "3. Keluar" << endl;
//         cout << "Pilih menu (" << MASUKKAN_DATA << "/" << LIHAT_RIWAYAT << "/" << KELUAR << "): ";
//         cin >> pilihan;

//         cin.ignore();

//         switch (pilihan)
//         {
//         case MASUKKAN_DATA:
//         {
//             Pasien pasien;
//             cout << "Masukkan Nama Pasien: ";
//             getline(cin, pasien.nama);
//             cout << "Masukkan Umur Pasien: ";
//             cin >> pasien.umur;
//             cout << "Masukkan Tinggi Badan Pasien: ";
//             cin >> pasien.tinggiBadan;
//             cout << "Masukkan Berat Badan Pasien: ";
//             cin >> pasien.beratBadan;
//             cin.ignore();
//             cout << "Masukkan Riwayat Penyakit Pasien: ";
//             getline(cin, pasien.riwayatPenyakit);
//             cout << "Masukkan Keluhan Pasien: ";
//             getline(cin, pasien.keluhanPenyakit);
//             cout << "Masukkan Diagnosa Pasien: ";
//             getline(cin, pasien.diagnosa);
//             manajemen.tambahPasien(pasien);
//             manajemen.simpanDataKeFile();
//             break;
//         }

//         case LIHAT_RIWAYAT:
//             cout << "=== Riwayat Penyakit Pasien ===" << endl;
//             manajemen.tampilkanRiwayatPenyakit();
//             break;

//         case KELUAR:
//             cout << "Terima kasih. Keluar dari program." << endl;
//             return 0;

//         default:
//             cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
//         }

//         cout << "Apakah Anda ingin kembali ke menu? (y/n): ";
//         cin >> lanjut;
//     } while (lanjut == 'y' || lanjut == 'Y');

//     return 0;
// }
