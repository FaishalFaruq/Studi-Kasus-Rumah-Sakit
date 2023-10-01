#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class RumahSakitWiFi
{
private:
    bool wifiAktif;
    string password;
    int tingkatSinyal;

public:
    RumahSakitWiFi() : wifiAktif(false), tingkatSinyal(0) {}

    void aturPassword(const string &newPassword)
    {
        password = newPassword;
        cout << "Password WiFi berhasil diatur." << endl;
        getchar();
        system("clear");
    }

    void aktifkanWiFi(const string &inputPassword)
    {
        if (inputPassword == password)
        {
            wifiAktif = true;
            tingkatSinyal = rand() % 100 + 1;
            cout << "WiFi berhasil diaktifkan. Selamat berselancar di dunia maya!" << endl;
        }
        else
        {
            cout << "Password salah. WiFi tidak dapat diaktifkan." << endl;
        }
    }

    void nonAktifkanWiFi()
    {
        wifiAktif = false;
        tingkatSinyal = 0;
        cout << "WiFi berhasil dimatikan." << endl;
    }

    bool cekStatusWiFi() const
    {
        return wifiAktif;
    }

    int cekTingkatSinyal() const
    {
        return tingkatSinyal;
    }

    void tampilkanPesanSelamatDatang(const string &namaPengguna)
    {
        cout << "Selamat datang, " << namaPengguna << ", di Rumah Sakit XYZ!" << endl;
        cout << "===============================" << endl;
        cout << "Fasilitas WiFi saat ini ";
        if (wifiAktif)
        {
            cout << "AKTIF." << endl;
            cout << "Tingkat Sinyal WiFi: " << tingkatSinyal << "%" << endl;
        }
        else
        {
            cout << "TIDAK AKTIF." << endl;
            cout << "Maaf, WiFi sedang tidak tersedia." << endl;
        }
        cout << "===============================" << endl
             << endl;
    }
    void dataWifi()
    {
        RumahSakitWiFi rsWiFi;

        cout << "Masukkan nama Anda: ";
        string namaPengguna;
        cin >> namaPengguna;

        cout << "Selamat datang, " << namaPengguna << "!" << endl;

        // Menyediakan opsi untuk mengatur password WiFi
        cout << "Apakah Anda ingin mengatur password WiFi? (y/n): ";
        char opsi;
        cin >> opsi;
        if (opsi == 'y' || opsi == 'Y')
        {
            cout << "Masukkan password baru: ";
            string newPassword;
            cin >> newPassword;
            rsWiFi.aturPassword(newPassword);
        }

        rsWiFi.tampilkanPesanSelamatDatang(namaPengguna);

        // Memasukkan password dan mengaktifkan WiFi (simulasi)
        string inputPassword;
        cout << "Masukkan password untuk mengaktifkan WiFi: ";
        cin >> inputPassword;
        rsWiFi.aktifkanWiFi(inputPassword);
        rsWiFi.tampilkanPesanSelamatDatang(namaPengguna);

        // Mematikan WiFi (simulasi)
        cout << "Apakah Anda ingin mematikan WiFi? (y/n): ";
        char opsiMatikan;
        cin >> opsiMatikan;
        if (opsiMatikan == 'y' || opsiMatikan == 'Y')
        {
            rsWiFi.nonAktifkanWiFi();
            rsWiFi.tampilkanPesanSelamatDatang(namaPengguna);
        }
    }
};

// int main() {
//     RumahSakitWiFi rsWiFi;

//     cout << "Masukkan nama Anda: ";
//     string namaPengguna;
//     cin >> namaPengguna;

//     cout << "Selamat datang, " << namaPengguna << "!" << endl;

//     // Menyediakan opsi untuk mengatur password WiFi
//     cout << "Apakah Anda ingin mengatur password WiFi? (y/n): ";
//     char opsi;
//     cin >> opsi;
//     if (opsi == 'y' || opsi == 'Y') {
//         cout << "Masukkan password baru: ";
//         string newPassword;
//         cin >> newPassword;
//         rsWiFi.aturPassword(newPassword);
//     }

//     rsWiFi.tampilkanPesanSelamatDatang(namaPengguna);

//     // Memasukkan password dan mengaktifkan WiFi (simulasi)
//     string inputPassword;
//     cout << "Masukkan password untuk mengaktifkan WiFi: ";
//     cin >> inputPassword;
//     rsWiFi.aktifkanWiFi(inputPassword);
//     rsWiFi.tampilkanPesanSelamatDatang(namaPengguna);

//     // Mematikan WiFi (simulasi)
//     cout << "Apakah Anda ingin mematikan WiFi? (y/n): ";
//     char opsiMatikan;
//     cin >> opsiMatikan;
//     if (opsiMatikan == 'y' || opsiMatikan == 'Y') {
//         rsWiFi.nonAktifkanWiFi();
//         rsWiFi.tampilkanPesanSelamatDatang(namaPengguna);
//     }

//     return 0;
// }
