#include <iostream>
#include <string>
using namespace std;

struct Pasien
{
    string nama;
    string nomorBPJS;
    string nomortelp;
    string desa;
    string kec;
    string kab;
    string prov;
    string umur;
    bool jenisKelamin;
};

class BPJS
{
public:
    bool cekKelayakan()
    {
        Pasien pasien;
        if (pasien.nomorBPJS.length() == 8)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void inputBJPS()
    {
        Pasien pasien;
        cout << "Masukkan Nama Pasien: ";
        getline(cin, pasien.nama);

        cout << "Masukkan umur : ";
        cin >> pasien.umur;

        cout << "Masukkan jenis kelamin (0 untuk perempuan, 1 untuk laki-laki): ";
        cin >> pasien.jenisKelamin;

        cout << "Masukkan Nomor BPJS (8 digit): ";
        cin >> pasien.nomorBPJS;

        cout << "Masukkan Nomor telepon : ";
        cin >> pasien.nomortelp;

        cout << "Masukkan alamat  " << endl;
        cout << "Masukkan Kel/Desa  : ";
        cin >> pasien.desa;
        cout << "Masukkan Kecamatan : ";
        cin >> pasien.kec;
        cout << "Masukkan Kabupaten : ";
        cin >> pasien.kab;
        cout << "Masukkan Provinsi  : ";
        cin >> pasien.prov;

        bool kelayakan = cekKelayakan();

        // Menampilkan informasi pasien
        cout << "\nInformasi Pasien:" << endl;
        cout << "Nama: " << pasien.nama << endl;
        cout << "Nomor BPJS: " << pasien.nomorBPJS << endl;
        cout << "Nomor telepon: " << pasien.nomortelp << endl;
        cout << "Umur: " << pasien.umur << " tahun" << endl;
        cout << "Jenis Kelamin: " << (pasien.jenisKelamin ? "Laki-laki" : "Perempuan") << endl;
        cout << "Alamat " << endl;
        cout << "\tKel/Desa: " << pasien.desa << endl;
        cout << "\tKecamatan: " << pasien.kec << endl;
        cout << "\tKabupaten: " << pasien.kab << endl;
        cout << "\tProvinsi : " << pasien.prov << endl;

        // Meminta pilihan layanan
        int pilihanLayanan;
        cout << "\nPilih jenis layanan: " << endl;
        cout << "1. Rawat Jalan" << endl;
        cout << "2. Operasi" << endl;
        cout << "3. Mengambil Obat" << endl;
        cout << "4. Pemeriksaan" << endl;
        cout << "Masukkan nomor layanan yang dipilih: ";
        cin >> pilihanLayanan;

        // Menampilkan layanan yang dipilih
        switch (pilihanLayanan)
        {
        case 1:
            cout << "Anda memilih layanan Rawat Jalan." << endl;
            break;
        case 2:
            cout << "Anda memilih layanan Operasi." << endl;
            break;
        case 3:
            cout << "Anda memilih layanan Mengambil Obat." << endl;
            break;
        case 4:
            cout << "Anda memilih layanan Pemeriksaan." << endl;
            break;
        default:
            cout << "Pilihan layanan tidak valid." << endl;
            break;
        }

        if (kelayakan)
        {
            cout << "Penggunaan BPJS di rumah sakit diterima." << endl;
        }
        else
        {
            cout << "Penggunaan BPJS di rumah sakit tidak diterima." << endl;
        }
    }

private:
    string nomorBPJS;
};

// int main()
// {
//     Pasien pasien;
//     cout << "Masukkan Nama Pasien: ";
//     getline(cin, pasien.nama);

//     cout << "Masukkan umur : ";
//     cin >> pasien.umur;

//     cout << "Masukkan jenis kelamin (0 untuk perempuan, 1 untuk laki-laki): ";
//     cin >> pasien.jenisKelamin;

//     cout << "Masukkan Nomor BPJS (8 digit): ";
//     cin >> pasien.nomorBPJS;

//     cout << "Masukkan Nomor telepon : ";
//     cin >> pasien.nomortelp;

//     cout << "Masukkan alamat  " << endl;
//     cout << "Masukkan Kel/Desa  : ";
//     cin >> pasien.desa;
//     cout << "Masukkan Kecamatan : ";
//     cin >> pasien.kec;
//     cout << "Masukkan Kabupaten : ";
//     cin >> pasien.kab;
//     cout << "Masukkan Provinsi  : ";
//     cin >> pasien.prov;

//     // Memeriksa kelayakan penggunaan BPJS
//     bool kelayakan = BPJS(pasien.nomorBPJS).cekKelayakan();

//     // Menampilkan informasi pasien
//     cout << "\nInformasi Pasien:" << endl;
//     cout << "Nama: " << pasien.nama << endl;
//     cout << "Nomor BPJS: " << pasien.nomorBPJS << endl;
//     cout << "Nomor telepon: " << pasien.nomortelp << endl;
//     cout << "Umur: " << pasien.umur << " tahun" << endl;
//     cout << "Jenis Kelamin: " << (pasien.jenisKelamin ? "Laki-laki" : "Perempuan") << endl;
//     cout << "Alamat " << endl;
//     cout << "\tKel/Desa: " << pasien.desa << endl;
//     cout << "\tKecamatan: " << pasien.kec << endl;
//     cout << "\tKabupaten: " << pasien.kab << endl;
//     cout << "\tProvinsi : " << pasien.prov << endl;

//     // Meminta pilihan layanan
//     int pilihanLayanan;
//     cout << "\nPilih jenis layanan: " << endl;
//     cout << "1. Rawat Jalan" << endl;
//     cout << "2. Operasi" << endl;
//     cout << "3. Mengambil Obat" << endl;
//     cout << "4. Pemeriksaan" << endl;
//     cout << "Masukkan nomor layanan yang dipilih: ";
//     cin >> pilihanLayanan;

//     // Menampilkan layanan yang dipilih
//     switch (pilihanLayanan)
//     {
//     case 1:
//         cout << "Anda memilih layanan Rawat Jalan." << endl;
//         break;
//     case 2:
//         cout << "Anda memilih layanan Operasi." << endl;
//         break;
//     case 3:
//         cout << "Anda memilih layanan Mengambil Obat." << endl;
//         break;
//     case 4:
//         cout << "Anda memilih layanan Pemeriksaan." << endl;
//         break;
//     default:
//         cout << "Pilihan layanan tidak valid." << endl;
//         break;
//     }

//     if (kelayakan)
//     {
//         cout << "Penggunaan BPJS di rumah sakit diterima." << endl;
//     }
//     else
//     {
//         cout << "Penggunaan BPJS di rumah sakit tidak diterima." << endl;
//     }

//     return 0;
// }
