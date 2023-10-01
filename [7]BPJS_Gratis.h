#include <iostream>
#include <string>
using namespace std;

struct BPJSPasien
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
private:
    BPJSPasien BPJSPasien;

public:
    bool cekKelayakan()
    {

        if (BPJSPasien.nomorBPJS.length() == 8)
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
        cout << "Masukkan Nama BPJSPasien: ";
        getline(cin, BPJSPasien.nama);

        cout << "Masukkan umur : ";
        cin >> BPJSPasien.umur;

        cout << "Masukkan jenis kelamin (0 untuk perempuan, 1 untuk laki-laki): ";
        cin >> BPJSPasien.jenisKelamin;

        cout << "Masukkan Nomor BPJS (8 digit): ";
        cin >> BPJSPasien.nomorBPJS;

        cout << "Masukkan Nomor telepon : ";
        cin >> BPJSPasien.nomortelp;

        cout << "Masukkan alamat  " << endl;
        cout << "Masukkan Kel/Desa  : ";
        cin >> BPJSPasien.desa;
        cout << "Masukkan Kecamatan : ";
        cin >> BPJSPasien.kec;
        cout << "Masukkan Kabupaten : ";
        cin >> BPJSPasien.kab;
        cout << "Masukkan Provinsi  : ";
        cin >> BPJSPasien.prov;

        bool kelayakan = cekKelayakan();

        // Menampilkan informasi BPJSPasien
        cout << "\nInformasi BPJSPasien:" << endl;
        cout << "Nama: " << BPJSPasien.nama << endl;
        cout << "Nomor BPJS: " << BPJSPasien.nomorBPJS << endl;
        cout << "Nomor telepon: " << BPJSPasien.nomortelp << endl;
        cout << "Umur: " << BPJSPasien.umur << " tahun" << endl;
        cout << "Jenis Kelamin: " << (BPJSPasien.jenisKelamin ? "Laki-laki" : "Perempuan") << endl;
        cout << "Alamat " << endl;
        cout << "\tKel/Desa: " << BPJSPasien.desa << endl;
        cout << "\tKecamatan: " << BPJSPasien.kec << endl;
        cout << "\tKabupaten: " << BPJSPasien.kab << endl;
        cout << "\tProvinsi : " << BPJSPasien.prov << endl;

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
};

// int main()
// {
//     BPJSPasien BPJSPasien;
//     cout << "Masukkan Nama BPJSPasien: ";
//     getline(cin, BPJSPasien.nama);

//     cout << "Masukkan umur : ";
//     cin >> BPJSPasien.umur;

//     cout << "Masukkan jenis kelamin (0 untuk perempuan, 1 untuk laki-laki): ";
//     cin >> BPJSPasien.jenisKelamin;

//     cout << "Masukkan Nomor BPJS (8 digit): ";
//     cin >> BPJSPasien.nomorBPJS;

//     cout << "Masukkan Nomor telepon : ";
//     cin >> BPJSPasien.nomortelp;

//     cout << "Masukkan alamat  " << endl;
//     cout << "Masukkan Kel/Desa  : ";
//     cin >> BPJSPasien.desa;
//     cout << "Masukkan Kecamatan : ";
//     cin >> BPJSPasien.kec;
//     cout << "Masukkan Kabupaten : ";
//     cin >> BPJSPasien.kab;
//     cout << "Masukkan Provinsi  : ";
//     cin >> BPJSPasien.prov;

//     // Memeriksa kelayakan penggunaan BPJS
//     bool kelayakan = BPJS(BPJSPasien.nomorBPJS).cekKelayakan();

//     // Menampilkan informasi BPJSPasien
//     cout << "\nInformasi BPJSPasien:" << endl;
//     cout << "Nama: " << BPJSPasien.nama << endl;
//     cout << "Nomor BPJS: " << BPJSPasien.nomorBPJS << endl;
//     cout << "Nomor telepon: " << BPJSPasien.nomortelp << endl;
//     cout << "Umur: " << BPJSPasien.umur << " tahun" << endl;
//     cout << "Jenis Kelamin: " << (BPJSPasien.jenisKelamin ? "Laki-laki" : "Perempuan") << endl;
//     cout << "Alamat " << endl;
//     cout << "\tKel/Desa: " << BPJSPasien.desa << endl;
//     cout << "\tKecamatan: " << BPJSPasien.kec << endl;
//     cout << "\tKabupaten: " << BPJSPasien.kab << endl;
//     cout << "\tProvinsi : " << BPJSPasien.prov << endl;

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
