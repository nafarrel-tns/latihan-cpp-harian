#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX = 100;          // Maksimal 100 tugas
    string todos[MAX];
    int count = 0;                // Jumlah tugas yang tersimpan
    int pilihan;

    while (true) {
        cout << "\n--- Todo List ---\n1. Tambah\n2. Hapus\n3. Lihat\n4. Keluar\nPilih: ";
        cin >> pilihan; cin.ignore();

        if (pilihan == 1) {
            if (count >= MAX) {
                cout << "Todo list penuh!\n";
                continue;
            }
            string task;
            cout << "Masukkan tugas: ";
            getline(cin, task);
            todos[count] = task;
            count++;
        }
        else if (pilihan == 2) {
            string task;
            cout << "Masukkan tugas yang dihapus: ";
            getline(cin, task);
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (todos[i] == task) {
                    // Geser semua tugas setelahnya ke kiri
                    for (int j = i; j < count - 1; j++) {
                        todos[j] = todos[j + 1];
                    }
                    count--;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Tugas tidak ditemukan!\n";
        }
        else if (pilihan == 3) {
            if (count == 0) {
                cout << "Todo list kosong!\n";
            } else {
                cout << "Daftar tugas:\n";
                for (int i = 0; i < count; i++) {
                    cout << "- " << todos[i] << "\n";
                }
            }
        }
        else if (pilihan == 4) {
            break;
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}
