#include <iostream>
#include <string>
#include <vector>

class AntrianRumahSakit
{
private:
    std::vector<std::string> nama_pasien;
    int nomor_antrian;

public:
    AntrianRumahSakit() : nomor_antrian(1) {}

    void tambahPasien()
    {
        std::string nama;
        std::cout << "Masukkan nama pasien: ";
        std::cin >> nama;

        nama_pasien.push_back(nama);
        std::cout << "Nomor Antrian " << nomor_antrian << " atas nama " << nama << " berhasil ditambahkan." << std::endl;
        nomor_antrian++;
    }

    void panggilPasien()
    {
        if (!nama_pasien.empty())
        {
            std::cout << "Nomor Antrian " << nomor_antrian - nama_pasien.size() << " atas nama " << nama_pasien[0] << " dipanggil." << std::endl;
            nama_pasien.erase(nama_pasien.begin());
        }
        else
        {
            std::cout << "Tidak ada pasien dalam antrian." << std::endl;
        }
    }

    void tampilkanAntrian()
    {
        std::cout << "=================" << std::endl;
        std::cout << "     Antrian     " << std::endl;
        std::cout << "=================" << std::endl;

        if (!nama_pasien.empty())
        {
            std::cout << "NO  Nama" << std::endl;
            for (int i = 0; i < nama_pasien.size(); i++)
            {
                std::cout << i + nomor_antrian - nama_pasien.size() << ".  " << nama_pasien[i] << std::endl;
            }
            std::cout << "=================" << std::endl;
        }
        else
        {
            std::cout << "Tidak ada pasien dalam antrian." << std::endl;
        }
    }

    void clear()
    {
        nama_pasien.clear();
        nomor_antrian = 1;
        std::cout << "Antrian telah dihapus dan di-reset ke semula." << std::endl;
    }
    void inputAntrian()
    {
        AntrianRumahSakit antrian;
        char pilihan;

        while (true)
        {
            std::cout << std::endl;
            std::cout << "=================================" << std::endl;
            std::cout << "       Antrian Pasien            " << std::endl;
            std::cout << "=================================" << std::endl;
            std::cout << "1. Tambah Antrian Baru" << std::endl;
            std::cout << "2. Panggil Antrian" << std::endl;
            std::cout << "3. Tampilkan Antrian" << std::endl;
            std::cout << "4. Hapus & Reset Antrian" << std::endl;
            std::cout << "5. KELUAR" << std::endl;
            std::cout << "Pilihan [1-5]: ";
            std::cin >> pilihan;

            switch (pilihan)
            {
            case '1':
                antrian.tambahPasien();
                break;
            case '2':
                antrian.panggilPasien();
                break;
            case '3':
                antrian.tampilkanAntrian();
                break;
            case '4':
                antrian.clear();
                break;
            case '5':
                std::cout << "Program selesai." << std::endl;
            default:
                std::cout << "Input Salah." << std::endl;
                break;
            }
        }
    }
};

// int main() {
//     AntrianRumahSakit antrian;
//     char pilihan;

//     while (true) {
//         std::cout << std::endl;
//         std::cout << "=================================" << std::endl;
//         std::cout << "       Antrian Pasien            " << std::endl;
//         std::cout << "=================================" << std::endl;
//         std::cout << "1. Tambah Antrian Baru" << std::endl;
//         std::cout << "2. Panggil Antrian" << std::endl;
//         std::cout << "3. Tampilkan Antrian" << std::endl;
//         std::cout << "4. Hapus & Reset Antrian" << std::endl;
//         std::cout << "5. KELUAR" << std::endl;
//         std::cout << "Pilihan [1-5]: ";
//         std::cin >> pilihan;

//         switch (pilihan) {
//             case '1':
//                 antrian.tambahPasien();
//                 break;
//             case '2':
//                 antrian.panggilPasien();
//                 break;
//             case '3':
//                 antrian.tampilkanAntrian();
//                 break;
//             case '4':
//                 antrian.clear();
//                 break;
//             case '5':
//                 std::cout << "Program selesai." << std::endl;
//                 return 0;
//             default:
//                 std::cout << "Input Salah." << std::endl;
//                 break;
//         }
//     }

//     return 0;
// }
