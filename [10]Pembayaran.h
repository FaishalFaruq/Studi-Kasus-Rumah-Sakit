#include<iostream>
#include<string>
using namespace std;

class Pembayaran {
private:
    double obat, kontrol, rawatInap, operasi;
    string namaObat, jenisRawatInap, jenisKontrol, jenisOperasi;

public:
    Pembayaran() : obat(0), kontrol(0), rawatInap(0), operasi(0) {}

    void setObat(double harga, const string& nama) {
        obat = harga;
        namaObat = nama;
    }

    void setKontrol(double harga, const string& jenis) {
        kontrol = harga;
        jenisKontrol = jenis;
    }

    void setRawatInap(double harga, const string& jenis) {
        rawatInap = harga;
        jenisRawatInap = jenis;
    }

    void setOperasi(double harga, const string& jenis) {
        operasi = harga;
        jenisOperasi = jenis;
    }

    double getTotal() const {
        return obat + kontrol + rawatInap + operasi;
    }

    void printDetail() const {
        cout << "Nama Obat: " << namaObat << ", Harga: " << obat << endl;
        cout << "Jenis Kontrol: " << jenisKontrol << ", Harga: " << kontrol << endl;
        cout << "Jenis Rawat Inap: " << jenisRawatInap << ", Harga: " << rawatInap << endl;
        cout << "Jenis Operasi: " << jenisOperasi << ", Harga: " << operasi << endl;
        cout << "Total Harga: " << getTotal() << endl;
    }
    void menuPembayaran(){
    Pembayaran p;
    int pilihan;
    double harga;
    string detail;

    do {
        cout << "\nMenu Pembayaran:\n";
        cout << "1. Obat\n";
        cout << "2. Kontrol\n";
        cout << "3. Rawat Inap\n";
        cout << "4. Operasi\n";
        cout << "5. Total Harga\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        cin.ignore();
        switch (pilihan) {
        case 1:
            cout << "Masukkan nama obat: ";
            getline(cin , detail ) ;
            cout << "Masukkan harga obat: ";
            cin >> harga;
            p.setObat(harga, detail);
            break;
        case 2:
            cout << "Masukkan jenis pemeriksaan: ";
            getline(cin , detail ) ;
            cout << "Masukkan biaya pemeriksaan: ";
            cin >> harga;
            p.setKontrol(harga, detail);
            break;
        case 3:
            cout << "Masukkan jenis rawat inap: ";
            getline(cin , detail ) ;
            cout << "Masukkan biaya rawat inap: ";
            cin >> harga;
            p.setRawatInap(harga, detail);
            break;
        case 4:
            cout << "Masukkan jenis operasi: ";
            getline(cin , detail ) ;
            cout << "Masukkan biaya operasi: ";
            cin >> harga;
            p.setOperasi(harga, detail);
            break;
        case 5:
            p.printDetail();
            break;
        case 6:
            cout << "Terima kasih telah menggunakan layanan kami.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);
    }
};

// int main() {
//     Pembayaran p;
//     int pilihan;
//     double harga;
//     string detail;

//     do {
//         cout << "\nMenu Pembayaran:\n";
//         cout << "1. Obat\n";
//         cout << "2. Kontrol\n";
//         cout << "3. Rawat Inap\n";
//         cout << "4. Operasi\n";
//         cout << "5. Total Harga\n";
//         cout << "6. Keluar\n";
//         cout << "Pilih opsi: ";
//         cin >> pilihan;

//         cin.ignore();
//         switch (pilihan) {
//         case 1:
//             cout << "Masukkan nama obat: ";
//             getline(cin , detail ) ;
//             cout << "Masukkan harga obat: ";
//             cin >> harga;
//             p.setObat(harga, detail);
//             break;
//         case 2:
//             cout << "Masukkan jenis pemeriksaan: ";
//             getline(cin , detail ) ;
//             cout << "Masukkan biaya pemeriksaan: ";
//             cin >> harga;
//             p.setKontrol(harga, detail);
//             break;
//         case 3:
//             cout << "Masukkan jenis rawat inap: ";
//             getline(cin , detail ) ;
//             cout << "Masukkan biaya rawat inap: ";
//             cin >> harga;
//             p.setRawatInap(harga, detail);
//             break;
//         case 4:
//             cout << "Masukkan jenis operasi: ";
//             getline(cin , detail ) ;
//             cout << "Masukkan biaya operasi: ";
//             cin >> harga;
//             p.setOperasi(harga, detail);
//             break;
//         case 5:
//             p.printDetail();
//             break;
//         case 6:
//             cout << "Terima kasih telah menggunakan layanan kami.\n";
//             break;
//         default:
//             cout << "Pilihan tidak valid.\n";
//         }
//     } while (pilihan != 6);

//     return 0;
// }
