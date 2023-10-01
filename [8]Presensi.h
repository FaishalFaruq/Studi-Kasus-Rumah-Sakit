#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Employee {
    string name;
    bool present;
};

int main() {
    const int numEmployees = 10; 
    vector<Employee> employees(numEmployees);

    employees[0] = {"Karyawan 1", false};
    employees[1] = {"Karyawan 2", false};
    employees[2] = {"Karyawan 3", false};
    employees[3] = {"Karyawan 4", false};
    employees[4] = {"Karyawan 5", false};
    employees[5] = {"Karyawan 6", false};
    employees[6] = {"Karyawan 7", false};
    employees[7] = {"Karyawan 8", false};
    employees[8] = {"Karyawan 9", false};
    employees[9] = {"Karyawan 10", false};

    while (true) {
        cout << "Menu Presensi Karyawan:" << endl;
        cout << "1. Cek Presensi Karyawan" << endl;
        cout << "2. Presensi" << endl;
        cout << "3. Keluar" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Daftar Karyawan dan Presensi:" << endl;
                for (int i = 0; i < numEmployees; ++i) {
                    cout << employees[i].name << ": ";
                    if (employees[i].present) {
                        cout << "Hadir" << endl;
                    } else {
                        cout << "Tidak Hadir" << endl;
                    }
                }
                break;

            case 2:
                cout << "Masukkan nomor karyawan (1-" << numEmployees << "): ";
                int employeeNumber;
                cin >> employeeNumber;

                if (employeeNumber >= 1 && employeeNumber <= numEmployees) {
                    employees[employeeNumber - 1].present = true;
                    cout << "Presensi berhasil dicatat." << endl;
                } else {
                    cout << "Nomor karyawan tidak valid." << endl;
                }
                break;

            case 3:
                cout << "Terima kasih! Sampai jumpa." << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                break;
        }
    }

    return 0;
}
