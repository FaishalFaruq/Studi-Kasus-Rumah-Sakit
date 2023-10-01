#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Deklarasi struktur data untuk Pasien
struct Pasien {
    string id;
    string nama;
    int umur;
    string diagnosis;
    Pasien* next; // Tautan ke pasien berikutnya dalam linked list
};

// Fungsi untuk mencari pasien berdasarkan ID
Pasien* cariPasien(Pasien* head, string id) {
    Pasien* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Pasien tidak ditemukan
}

// Fungsi untuk menghapus pasien dari linked list berdasarkan ID
void hapusPasien(Pasien*& head, string id) {
    Pasien* prev = nullptr;
    Pasien* current = head;

    while (current != nullptr) {
        if (current->id == id) {
            if (prev == nullptr) {
                // Kasus jika pasien yang dihapus adalah kepala (head) dari linked list
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Pasien dengan ID " << id << " telah dihapus." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Pasien dengan ID " << id << " tidak ditemukan." << endl;
}

// Fungsi untuk menyimpan daftar pasien ke dalam file teks
void simpanDaftarPasien(Pasien* head) {
    ofstream file("daftar_pasien.txt");

    if (!file.is_open()) {
        cerr << "Gagal membuka file daftar_pasien.txt." << endl;
        return;
    }

    Pasien* current = head;
    while (current != nullptr) {
        file << "ID: " << current->id << endl;
        file << "Nama: " << current->nama << endl;
        file << "Umur: " << current->umur << endl;
        file << "Diagnosis: " << current->diagnosis << endl;
        file << "====================" << endl;
        current = current->next;
    }

    file.close();
    cout << "Daftar pasien berhasil disimpan ke dalam file daftar_pasien.txt." << endl;
}

int main() {
    Pasien* head = nullptr; // Menunjuk ke simpul pertama dalam linked list

    while (true) {
        // Menu utama
        cout << "Rumah Sakit Kelas B" << endl;
        cout << "1. Tambah Pasien" << endl;
        cout << "2. Tampilkan Daftar Pasien" << endl;
        cout << "3. Cari Pasien" << endl;
        cout << "4. Hapus Pasien" << endl;
        cout << "5. Simpan Daftar Pasien ke File" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1: // Tambah Pasien
                {
                    string id, nama, diagnosis;
                    int umur;
                    cin.ignore(); // Membersihkan buffer dari newline sebelumnya
                    cout << "ID Pasien\t: ";
                    getline(cin, id);
                    cout << "Nama Pasien\t: ";
                    getline(cin, nama);
                    cout << "Umur Pasien\t: ";
                    cin >> umur;
                    cin.ignore();
                    cout << "Diagnosis\t: ";
                    getline(cin, diagnosis);

                    // Membuat simpul baru untuk pasien
                    Pasien* pasienBaru = new Pasien{id, nama, umur, diagnosis, nullptr};

                    // Menambahkan simpul ke linked list
                    if (head == nullptr) {
                        head = pasienBaru;
                    } else {
                        Pasien* current = head;
                        while (current->next != nullptr) {
                            current = current->next;
                        }
                        current->next = pasienBaru;
                    }

                    cout << "Pasien dengan ID " << id << " telah ditambahkan." << endl;
                }
                break;
            case 2: // Tampilkan Daftar Pasien
                if (head == nullptr) {
                    cout << "Belum ada pasien yang terdaftar." << endl;
                } else {
                    cout << "Daftar Pasien:" << endl;
                    Pasien* current = head;
                    int nomorPasien = 1;
                    while (current != nullptr) {
                        cout << "Pasien ke-" << nomorPasien << endl;
                        cout << "ID: " << current->id << endl;
                        cout << "Nama: " << current->nama << endl;
                        cout << "Umur: " << current->umur << endl;
                        cout << "Diagnosis: " << current->diagnosis << endl;
                        cout << "====================" << endl;
                        current = current->next;
                        nomorPasien++;
                    }
                }
                break;
            case 3: // Cari Pasien
                {
                    cin.ignore();
                    cout << "Masukkan ID pasien yang ingin dicari: ";
                    string id;
                    getline(cin, id);

                    Pasien* hasilPencarian = cariPasien(head, id);
                    if (hasilPencarian != nullptr) {
                        cout << "Pasien ditemukan:" << endl;
                        cout << "ID: " << hasilPencarian->id << endl;
                        cout << "Nama: " << hasilPencarian->nama << endl;
                        cout << "Umur: " << hasilPencarian->umur << endl;
                        cout << "Diagnosis: " << hasilPencarian->diagnosis << endl;
                        cout << "====================" << endl;
                    } else {
                        cout << "Pasien dengan ID " << id << " tidak ditemukan." << endl;
                    }
                }
                break;
            case 4: // Hapus Pasien
                {
                    cin.ignore();
                    cout << "Masukkan ID pasien yang ingin dihapus: ";
                    string id;
                    getline(cin, id);

                    hapusPasien(head, id);
                }
                break;
            case 5: // Simpan Daftar Pasien ke File
                simpanDaftarPasien(head);
                break;
            case 6: // Keluar
                // Membersihkan linked list
                while (head != nullptr) {
                    Pasien* temp = head;
                    head = head->next;
                    delete temp;
                }
                cout << "Terima kasih telah berobat disini. Semoga cepat sembuh!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}

