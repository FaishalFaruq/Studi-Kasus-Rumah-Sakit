#include <iostream>
#include <string>
#include <vector>

// Struktur data untuk obat
struct Obat
{
    std::string nama;
    int stok;

    Obat(const std::string &n, int s) : nama(n), stok(s) {}
};

// Class untuk manajemen obat
class ManajemenObat
{
private:
    std::vector<Obat> database;

public:
    // Menambahkan obat ke dalam database
    void tambahObat(const Obat &obat)
    {
        database.push_back(obat);
        std::cout << "Obat berhasil ditambahkan ke dalam database." << std::endl;
    }

    // Menampilkan semua obat dalam database
    void tampilkanObat()
    {
        std::cout << "Daftar Obat:" << std::endl;
        for (const Obat &obat : database)
        {
            std::cout << "Nama: " << obat.nama << ", Stok: " << obat.stok << std::endl;
        }
    }

    // Mengambil obat dari stok
    void ambilObat(const std::string &namaObat, int jumlah)
    {
        for (Obat &obat : database)
        {
            if (obat.nama == namaObat)
            {
                if (jumlah > 0 && jumlah <= obat.stok)
                {
                    obat.stok -= jumlah;
                    std::cout << "Obat berhasil diambil!" << std::endl;
                    std::cout << "Stok sisa untuk " << namaObat << ": " << obat.stok << std::endl;
                }
                else
                {
                    std::cout << "Jumlah tidak valid atau stok tidak mencukupi." << std::endl;
                }
                return;
            }
        }
        std::cout << "Obat dengan nama " << namaObat << " tidak ditemukan." << std::endl;
    }
    void pilihanObat()
    {
        ManajemenObat manajemen;

        // Menambahkan beberapa obat ke database
        Obat obat1("Paracetamol", 50);
        Obat obat2("Amoxicillin", 30);
        Obat obat3("Vitamin C", 100);

        manajemen.tambahObat(obat1);
        manajemen.tambahObat(obat2);
        manajemen.tambahObat(obat3);

        int pilihan;

        do
        {
            std::cout << "\nMenu:" << std::endl;
            std::cout << "1. Tampilkan Semua Obat" << std::endl;
            std::cout << "2. Ambil Obat" << std::endl;
            std::cout << "3. Keluar" << std::endl;
            std::cout << "Pilih menu (1/2/3): ";
            std::cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                manajemen.tampilkanObat();
                break;
            case 2:
            {
                std::string namaObat;
                int jumlah;
                std::cout << "Masukkan nama obat yang ingin diambil: ";
                std::cin >> namaObat;
                std::cout << "Masukkan jumlah obat yang ingin diambil: ";
                std::cin >> jumlah;
                manajemen.ambilObat(namaObat, jumlah);
                break;
            }
            case 3:
                std::cout << "Terima kasih! Program selesai." << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
                break;
            }

        } while (pilihan != 3);
    }
};

// int main()
// {
//     ManajemenObat manajemen;

//     // Menambahkan beberapa obat ke database
//     Obat obat1("Paracetamol", 50);
//     Obat obat2("Amoxicillin", 30);
//     Obat obat3("Vitamin C", 100);

//     manajemen.tambahObat(obat1);
//     manajemen.tambahObat(obat2);
//     manajemen.tambahObat(obat3);

//     int pilihan;

//     do
//     {
//         std::cout << "\nMenu:" << std::endl;
//         std::cout << "1. Tampilkan Semua Obat" << std::endl;
//         std::cout << "2. Ambil Obat" << std::endl;
//         std::cout << "3. Keluar" << std::endl;
//         std::cout << "Pilih menu (1/2/3): ";
//         std::cin >> pilihan;

//         switch (pilihan)
//         {
//         case 1:
//             manajemen.tampilkanObat();
//             break;
//         case 2:
//         {
//             std::string namaObat;
//             int jumlah;
//             std::cout << "Masukkan nama obat yang ingin diambil: ";
//             std::cin >> namaObat;
//             std::cout << "Masukkan jumlah obat yang ingin diambil: ";
//             std::cin >> jumlah;
//             manajemen.ambilObat(namaObat, jumlah);
//             break;
//         }
//         case 3:
//             std::cout << "Terima kasih! Program selesai." << std::endl;
//             break;
//         default:
//             std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
//             break;
//         }

//     } while (pilihan != 3);

//     return 0;
// }
