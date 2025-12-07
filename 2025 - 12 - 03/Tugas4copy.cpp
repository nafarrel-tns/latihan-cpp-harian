#include <iostream>
using namespace std;

void kopi() {
    cout << "Kamu memilih Kopi, nikmati harimu dengan energi baru!" << endl;
}

void teh() {
    cout << "Kamu memilih Teh, segarkan pikiranmu." << endl;
}

void esJeruk() {
    cout << "Kamu memilih Jus Jeruk, sehat dan segar!" << endl;
}

int main() {
    int pilihan;

    cout << "=== Mesin Minuman Otomatis ===" << endl;
    cout << "Menu:\n";
    cout << "1. Kopi\n";
    cout << "2. Teh\n";
    cout << "3. Es Jeruk\n";
    cout << "0. Keluar\n";

    while (true) {
        cout << "\nPilih minuman (0 untuk keluar): ";
        cin >> pilihan;

        if (pilihan < 0 || pilihan > 3) {
            cout << "Menu tidak tersedia, coba lagi!" << endl;
            continue; 
        }

        if (pilihan == 0) {
            cout << "Terima kasih sudah menggunakan mesin minuman." << endl;
            break; 
        }

        if (pilihan == 1) {
            kopi();
        } else if (pilihan == 2) {
            teh();
        } else if (pilihan == 3) {
            esJeruk(); 
        }
    }

    return 0;
}