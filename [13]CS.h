#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

class Cstmr_srvc {
private:
    struct Customer {
        string nama, keluhan, kritik, nomorTelepon, email;
    };

    Customer customer;

public:
    Cstmr_srvc() {}

    void tampil() {
        cout << "=================================================" << endl;
        cout << "\t\t\t\t Customer Service" << endl;
        cout << "=================================================" << endl;
        cout << "Terimakasih telah menghubungi customer service." << endl;
        cout << "Ada yang dapat saya bantu?" << endl;
        cout << endl;
        cout << "1. Info Nomor Layanan" << endl;
        cout << "2. Kritik dan saran" << endl;
        cout << "3. Keluhan Pasien" << endl;
        cout << "4. Keluar" << endl;
    }

    void pilih() {
        int pilihan;
        do {tampil();
            cout << "Masukkan pilihan Anda : ";
            cin >> pilihan;
            cin.ignore();

            switch (pilihan) {
            case 1:
                infoLayanan();
                break;
            case 2:
                inputDataKritikSaran();
                SimpanKritikSaran();
                cout << "Terima kasih atas kritik dan saran Anda. Kami akan memperbaiki pelayanan kami." << endl;
                tunggu();
                break;
            case 3:
                inputDataKeluhan();
                SimpanKeluhan();
                cout << "Terima kasih atas keluhan Anda, " << customer.nama << ". Kami akan segera menangani keluhan Anda tentang : " << customer.keluhan << endl;
                tunggu();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan layanan customer service. Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                tunggu();
            }
        } while (pilihan != 4);
    }

    void infoLayanan() {
        cout << "Layanan Pendaftaran pasien \t: 082330602071(Lisa)" << endl;
        cout << "Layanan Pembayaran \t\t\t: 083870239357(Tatang)" << endl;
        cout << "Layanan Kehilangan Barang \t: 083871576645(Jean)" << endl;
        tunggu();
    }

    void inputDataKritikSaran() {
        cout << "Nama : ";
        getline(cin, customer.nama);
        cout << "Nomor Telepon : ";
        getline(cin, customer.nomorTelepon);
        cout << "Email : ";
        getline(cin, customer.email);
        cout << "Masukkan kritik dan saran : ";
        getline(cin, customer.kritik);
    }

    void inputDataKeluhan() {
        cout << "Masukkan nama Pasien : ";
        getline(cin, customer.nama);
        cout << "Masukkan keluhan : ";
        getline(cin, customer.keluhan);
    }

    void SimpanKritikSaran() {
        ofstream file("kritik_saran.txt", ios::app); 
        if (file.is_open()) {
            file << "Nama: " << customer.nama << endl;
            file << "Nomor Telepon: " << customer.nomorTelepon << endl;
            file << "Email: " << customer.email << endl;
            file << "Kritik dan Saran: " << customer.kritik << endl;
            file << "=============================" << endl;
            file.close();
        }
        else {
            cout << "Gagal membuka file kritik_saran.txt." << endl;
        }
    }

    void SimpanKeluhan() {
        ofstream file("keluhan.txt", ios::app); 
        if (file.is_open()) {
            file << "Nama Pasien: " << customer.nama << endl;
            file << "Keluhan: " << customer.keluhan << endl;
            file << "=============================" << endl;
            file.close();
        }
        else {
            cout << "Gagal membuka file keluhan.txt." << endl;
        }
    }

    void tunggu() {
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    }
};

// int main() {
//     Cstmr_srvc customerService;
//     customerService.pilih();

//     return 0;
// }
