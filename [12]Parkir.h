#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>

using namespace std;

struct Kendaraan {
    string plat;
    string jenis;
    int waktu_masuk_tanggal;
    int waktu_masuk_bulan;
    int waktu_masuk_tahun;
    int waktu_masuk_jam;
    int waktu_masuk_menit;
};

const int harga_motor_per_jam = 2000;
const int harga_mobil_per_jam = 5000;

class ParkirRumahSakit {
private:
    Kendaraan daftarKendaraan[100]; 
    int jumlahKendaraan = 0;

public:
    bool isValidPlatNomor(const string &plat) {
        regex platNomorRegex("^[A-Z]{1,2}\\s\\d{1,4}\\s[A-Z]{1,3}$");
        return regex_match(plat, platNomorRegex);
    }

    ParkirRumahSakit() {
        ifstream file("data_masuk_parkir.txt");
        if (file.is_open()) {
            string plat, jenis;
            int tanggal, bulan, tahun, jam, menit;
            while (getline(file, plat) && getline(file, jenis) &&
                   file >> tanggal >> bulan >> tahun >> jam >> menit) {
                Kendaraan kendaraan;
                kendaraan.plat = plat;
                kendaraan.jenis = jenis;
                kendaraan.waktu_masuk_tanggal = tanggal;
                kendaraan.waktu_masuk_bulan = bulan;
                kendaraan.waktu_masuk_tahun = tahun;
                kendaraan.waktu_masuk_jam = jam;
                kendaraan.waktu_masuk_menit = menit;
                daftarKendaraan[jumlahKendaraan++] = kendaraan;
            }
            file.close();
        } else {
            cout << "Gagal membuka file data_masuk.txt." << endl;
        }
    }

    void masukParkir() {
        Kendaraan kendaraan;

        while (true) {
            cout << "Masukkan plat kendaraan (format: AB 1234 CD): ";
            cin.ignore();
            getline(cin, kendaraan.plat);

            if (isValidPlatNomor(kendaraan.plat)) {
                break;
            } else {
                cout << "Format plat nomor tidak valid. Coba lagi." << endl;
            }
        }

        int menu;
        cout << "Jenis kendaraan" << endl;
        cout << "1. Motor" << endl;
        cout << "2. Mobil" << endl;
        cout << "Pilih: ";
        cin >> menu;
        if (menu == 1) {
            kendaraan.jenis = "motor";
        } else if (menu == 2) {
            kendaraan.jenis = "mobil";
        } else {
            cout << "Pilihan tidak valid, otomatis dianggap motor." << endl;
            kendaraan.jenis = "motor";
        }

        int tanggal, bulan, tahun, jam, menit;
        cout << "Masukkan tanggal masuk (format: 07 07 2004)  : ";
        cin >> tanggal >> bulan >> tahun;
        cout << "Masukkan waktu masuk (format: 24 59): ";
        cin >> jam >> menit;

        kendaraan.waktu_masuk_tanggal = tanggal;
        kendaraan.waktu_masuk_bulan = bulan;
        kendaraan.waktu_masuk_tahun = tahun;
        kendaraan.waktu_masuk_jam = jam;
        kendaraan.waktu_masuk_menit = menit;

        cout << "Data kendaraan telah dimasukkan." << endl;

        daftarKendaraan[jumlahKendaraan++] = kendaraan;

        ofstream file("data_masuk_parkir.txt", ios::app); 
        if (file.is_open()) {
            file << kendaraan.plat << endl;
            file << kendaraan.jenis << endl;
            file << kendaraan.waktu_masuk_tanggal << " " << kendaraan.waktu_masuk_bulan << " " << kendaraan.waktu_masuk_tahun << " ";
            file << kendaraan.waktu_masuk_jam << " " << kendaraan.waktu_masuk_menit << endl;
            file.close();
        } else {
            cout << "Gagal membuka file data_masuk.txt." << endl;
        }
    }

    void simpanDataKeluar(const Kendaraan &kendaraan, double lama_parkir, int harga) {
        ofstream file("data_keluar_parkir.txt", ios::app);
        if (file.is_open()) {
            file << "Plat Kendaraan: " << kendaraan.plat << endl;
            file << "Jenis Kendaraan: " << kendaraan.jenis << endl;
            file << "Tanggal Masuk: " << kendaraan.waktu_masuk_tanggal << "/" << kendaraan.waktu_masuk_bulan << "/" << kendaraan.waktu_masuk_tahun << endl;
            file << "Waktu Masuk: " << kendaraan.waktu_masuk_jam << ":" << kendaraan.waktu_masuk_menit << endl;
            file << "Lama Waktu Parkir (jam): " << lama_parkir << endl;
            file << "Harga Parkir: " << harga << " rupiah" << endl;
            file << endl;
            file.close();
        } else {
            cout << "Gagal membuka file data_keluar.txt." << endl;
        }
    }

    void keluarParkir() {
        string platNomorInput;
        cout << "Masukkan Plat Nomor: ";
        cin.ignore();
        getline(cin, platNomorInput);

        int indexKendaraan = -1;

        for (int i = 0; i < jumlahKendaraan; i++) {
            if (daftarKendaraan[i].plat == platNomorInput) {
                indexKendaraan = i;
                break;
            }
        }

        if (indexKendaraan == -1) {
            cout << "Plat nomor tidak ditemukan dalam daftar kendaraan yang telah masuk." << endl;
            return;
        }

        Kendaraan &kendaraan = daftarKendaraan[indexKendaraan];

        int tanggal, bulan, tahun, jam, menit;
        cout << "Masukkan tanggal masuk (format: 07 07 2004)  : ";
        cin >> tanggal >> bulan >> tahun;
        cout << "Masukkan waktu masuk (format: 24 59): ";
        cin >> jam >> menit;

        double lama_parkir;
        lama_parkir = (double)((jam - kendaraan.waktu_masuk_jam) * 60 + (menit - kendaraan.waktu_masuk_menit)) / 60;

        transform(kendaraan.jenis.begin(), kendaraan.jenis.end(), kendaraan.jenis.begin(), ::tolower);

        int harga;
        if (kendaraan.jenis == "motor") {
            harga = lama_parkir * harga_motor_per_jam;
        } else if (kendaraan.jenis == "mobil") {
            harga = lama_parkir * harga_mobil_per_jam;
        } else {
            cout << "Jenis kendaraan tidak valid." << endl;
            return;
        }

        cout << "Data kendaraan telah ditemukan." << endl;
        cout << "Plat Kendaraan: " << kendaraan.plat << endl;
        cout << "Jenis Kendaraan: " << kendaraan.jenis << endl;
        cout << "Tanggal Masuk: " << kendaraan.waktu_masuk_tanggal << "/" << kendaraan.waktu_masuk_bulan << "/" << kendaraan.waktu_masuk_tahun << endl;
        cout << "Waktu Masuk: " << kendaraan.waktu_masuk_jam << ":" << kendaraan.waktu_masuk_menit << endl;
        cout << "Tanggal Keluar: " << tanggal << "/" << bulan << "/" << tahun << endl;
        cout << "Waktu Keluar: " << jam << ":" << menit << endl;
        cout << "Lama Waktu Parkir (jam): " << lama_parkir << endl;
        cout << "Harga Parkir: " << harga << " rupiah" << endl;

        simpanDataKeluar(kendaraan, lama_parkir, harga);

        for (int i = indexKendaraan; i < jumlahKendaraan - 1; i++) {
            daftarKendaraan[i] = daftarKendaraan[i + 1];
        }
        jumlahKendaraan--;

        ofstream file("data_masuk.txt", ios::out);
        if (file.is_open()) {
            for (int i = 0; i < jumlahKendaraan; i++) {
                file << daftarKendaraan[i].plat << endl;
                file << daftarKendaraan[i].jenis << endl;
                file << daftarKendaraan[i].waktu_masuk_tanggal << " " << daftarKendaraan[i].waktu_masuk_bulan << " " << daftarKendaraan[i].waktu_masuk_tahun << " ";
                file << daftarKendaraan[i].waktu_masuk_jam << " " << daftarKendaraan[i].waktu_masuk_menit << endl;
            }
            file.close();
        } else {
            cout << "Gagal membuka file data_masuk.txt." << endl;
        }
    }

    void output(){
      ParkirRumahSakit parkir;

    while (true) {
        cout << "PARKIR RUMAH SAKIT" << endl;
        cout << "1. Masuk Parkir" << endl;
        cout << "2. Keluar Parkir" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih tindakan: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 0) {
            break;
        } else if (pilihan == 1) {
            parkir.masukParkir();
        } else if (pilihan == 2) {
            parkir.keluarParkir();
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    }
};

