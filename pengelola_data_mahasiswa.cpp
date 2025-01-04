#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    double nilaiAkhir;
};

int main() {
    vector<Mahasiswa> mahasiswaList;
    int pilihan;

    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Data" << endl;
        cout << "3. Cari Data Mahasiswa" << endl;
        cout << "4. Simpan Data ke Berkas" << endl;
        cout << "5. Baca Data dari Berkas" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih opsi (1-6): ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: {
                Mahasiswa mhs;
                cout << "Masukkan NIM: ";
                cin >> mhs.nim;
                cout << "Masukkan Nama: ";
                cin >> mhs.nama;
                cout << "Masukkan Nilai Akhir: ";
                cin >> mhs.nilaiAkhir;
                mahasiswaList.push_back(mhs);
                break;
            }
            case 2:
                for (const auto& mhs : mahasiswaList) {
                    cout << "NIM: " << mhs.nim << ", Nama: " << mhs.nama << ", Nilai Akhir: " << mhs.nilaiAkhir << endl;
                }
                break;
            case 3: {
                string nimCari;
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> nimCari;
                bool ditemukan = false;
                for (const auto& mhs : mahasiswaList) {
                    if (mhs.nim == nimCari) {
                        cout << "Data ditemukan: NIM: " << mhs.nim << ", Nama: " << mhs.nama << ", Nilai Akhir: " << mhs.nilaiAkhir << endl;
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan) {
                    cout << "Data tidak ditemukan!" << endl;
                }
                break;
            }
            case 4: {
                ofstream outFile("data_mahasiswa.txt");
                for (const auto& mhs : mahasiswaList) {
                    outFile << mhs.nim << ", " << mhs.nama << ", " << mhs.nilaiAkhir << endl;
                }
                cout << "Data berhasil disimpan ke berkas!" << endl;
                break;
            }
            case 5: {
                ifstream inFile("data_mahasiswa.txt");
                mahasiswaList.clear();
                Mahasiswa mhs;
                while (inFile >> mhs.nim >> mhs.nama >> mhs.nilaiAkhir) {
                    mahasiswaList.push_back(mhs);
                }
                cout << "Data berhasil dibaca dari berkas!" << endl;
                break;
            }
            case 6:
                cout << "Terima kasih telah menggunakan Program Pengelolaan Data Mahasiswa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 6);

    return 0;
}
