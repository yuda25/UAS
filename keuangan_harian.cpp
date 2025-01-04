#include <iostream>
#include <string>
using namespace std;

int main() {
    double saldo, totalPengeluaran = 0.0;
    int pilihan;

    // Meminta saldo awal
    cout << "Selamat datang di Aplikasi Keuangan Harian!" << endl;
    cout << "Masukkan saldo awal Anda: ";
    cin >> saldo;

    do {
        // Menampilkan menu utama
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah Pengeluaran" << endl;
        cout << "2. Tampilkan Total Pengeluaran" << endl;
        cout << "3. Tampilkan Sisa Saldo" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: {
                double pengeluaran;
                cout << "Masukkan jumlah pengeluaran: ";
                cin >> pengeluaran;
                totalPengeluaran += pengeluaran;
                saldo -= pengeluaran;
                cout << "Pengeluaran berhasil ditambahkan!" << endl;
                break;
            }
            case 2:
                cout << "Total pengeluaran: " << totalPengeluaran << endl;
                break;
            case 3:
                cout << "Sisa saldo Anda: " << saldo << endl;
                break;
            case 4:
                cout << "Terima kasih telah menggunakan Aplikasi Keuangan Harian!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}
