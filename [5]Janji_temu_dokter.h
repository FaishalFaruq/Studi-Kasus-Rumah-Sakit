#include <iostream>
#include <string>

using namespace std;

struct Waktu
{
    int jam;
    int menit;
};

class JanjiTemu
{
private:
    string namaDokter;
    string spesialis;
    Waktu waktuJanji;

public:
    JanjiTemu(const string &nama, const string &spesialis, int jam, int menit)
    {
        this->namaDokter = nama;
        this->spesialis = spesialis;
        this->waktuJanji.jam = jam;
        this->waktuJanji.menit = menit;
    }

    void tampilkanJanji()
    {
        cout << "Janji temu dengan Dokter " << namaDokter << " (" << spesialis << ") pada jam "
             << waktuJanji.jam << ":" << waktuJanji.menit << endl;
    }
};

class TemuDokter
{
private:
    string nama;
    int usia;
    float tinggi;
    float berat;
    string alamat;
    string riwayatPenyakit;
    string keluhan;

public:
    TemuDokter(const string &nama, int usia, float tinggi, float berat, const string &alamat,
               const string &riwayatPenyakit, const string &keluhan)
    {
        this->nama = nama;
        this->usia = usia;
        this->tinggi = tinggi;
        this->berat = berat;
        this->alamat = alamat;
        this->riwayatPenyakit = riwayatPenyakit;
        this->keluhan = keluhan;
    }

    void tampilkanInfoTemuDokter()
    {
        cout << "\nIdentitas TemuDokter:\n";
        cout << "Nama: " << nama << endl;
        cout << "Usia: " << usia << " tahun" << endl;
        cout << "Tinggi: " << tinggi << " cm" << endl;
        cout << "Berat: " << berat << " kg" << endl;
        cout << "Alamat: " << alamat << endl;
        cout << "Riwayat Penyakit: " << riwayatPenyakit << endl;
        cout << "Keluhan: " << keluhan << endl;
    }
    void janjiTemuDokter()
    {
        string namaTemuDokter, alamatTemuDokter, riwayatPenyakit, keluhanTemuDokter;
        int usiaTemuDokter;
        float tinggiTemuDokter, beratTemuDokter;

        cout << "Masukkan nama TemuDokter: ";
        getline(cin, namaTemuDokter);

        cout << "Masukkan usia TemuDokter: ";
        cin >> usiaTemuDokter;
        cin.ignore();

        cout << "Masukkan tinggi TemuDokter (cm): ";
        cin >> tinggiTemuDokter;
        cin.ignore();

        cout << "Masukkan berat TemuDokter (kg): ";
        cin >> beratTemuDokter;
        cin.ignore();

        cout << "Masukkan alamat TemuDokter: ";
        getline(cin, alamatTemuDokter);

        cout << "Masukkan riwayat penyakit TemuDokter: ";
        getline(cin, riwayatPenyakit);

        cout << "Masukkan keluhan TemuDokter: ";
        getline(cin, keluhanTemuDokter);

        TemuDokter TemuDokter(namaTemuDokter, usiaTemuDokter, tinggiTemuDokter, beratTemuDokter, alamatTemuDokter, riwayatPenyakit, keluhanTemuDokter);
        TemuDokter.tampilkanInfoTemuDokter();

        JanjiTemu janji1("Dr. Smith", "Dokter Umum", 10, 30);
        JanjiTemu janji2("Dr. Johnson", "Dokter Gigi", 14, 15);

        cout << "\nPilihan Dokter Spesialis:\n";
        cout << "1. ";
        janji1.tampilkanJanji();
        cout << "2. ";
        janji2.tampilkanJanji();

        int pilihan;
        cout << "\nPilih dokter spesialis (1-2): ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << "\nAnda telah memilih dokter spesialis:\n";
            janji1.tampilkanJanji();
        }
        else if (pilihan == 2)
        {
            cout << "\nAnda telah memilih dokter spesialis:\n";
            janji2.tampilkanJanji();
        }
        else
        {
            cout << "Pilihan tidak valid.\n";
        }
    }
};

// int main() {
//     string namaTemuDokter, alamatTemuDokter, riwayatPenyakit, keluhanTemuDokter;
//     int usiaTemuDokter;
//     float tinggiTemuDokter, beratTemuDokter;

//     cout << "Masukkan nama TemuDokter: ";
//     getline(cin, namaTemuDokter);

//     cout << "Masukkan usia TemuDokter: ";
//     cin >> usiaTemuDokter;
//     cin.ignore();

//     cout << "Masukkan tinggi TemuDokter (cm): ";
//     cin >> tinggiTemuDokter;
//     cin.ignore();

//     cout << "Masukkan berat TemuDokter (kg): ";
//     cin >> beratTemuDokter;
//     cin.ignore();

//     cout << "Masukkan alamat TemuDokter: ";
//     getline(cin, alamatTemuDokter);

//     cout << "Masukkan riwayat penyakit TemuDokter: ";
//     getline(cin, riwayatPenyakit);

//     cout << "Masukkan keluhan TemuDokter: ";
//     getline(cin, keluhanTemuDokter);

//     TemuDokter TemuDokter(namaTemuDokter, usiaTemuDokter, tinggiTemuDokter, beratTemuDokter, alamatTemuDokter, riwayatPenyakit, keluhanTemuDokter);
//     TemuDokter.tampilkanInfoTemuDokter();

//     JanjiTemu janji1("Dr. Smith", "Dokter Umum", 10, 30);
//     JanjiTemu janji2("Dr. Johnson", "Dokter Gigi", 14, 15);

//     cout << "\nPilihan Dokter Spesialis:\n";
//     cout << "1. "; janji1.tampilkanJanji();
//     cout << "2. "; janji2.tampilkanJanji();

//     int pilihan;
//     cout << "\nPilih dokter spesialis (1-2): ";
//     cin >> pilihan;

//     if (pilihan == 1) {
//         cout << "\nAnda telah memilih dokter spesialis:\n";
//         janji1.tampilkanJanji();
//     } else if (pilihan == 2) {
//         cout << "\nAnda telah memilih dokter spesialis:\n";
//         janji2.tampilkanJanji();
//     } else {
//         cout << "Pilihan tidak valid.\n";
//     }

//     return 0;
// }
