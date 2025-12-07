#include <iostream>
using namespace std;

// Function untuk tiap minuman
void kopi() {
    cout << "Kamu memilih Kopi ☕, nikmati harimu dengan energi baru!" << endl;
}

void teh() {
    cout << "Kamu memilih Teh 🍵, segarkan pikiranmu." << endl;
}

void jusJeruk() {
    cout << "Kamu memilih Jus Jeruk 🍊, sehat dan segar!" << endl;
}

void airMineral() {
    cout << "Kamu memilih Air Mineral 💧, tetap terhidrasi ya." << endl;
}

int main() {
    int pilihan;

    cout << "=== Mesin Minuman Otomatis ===" << endl;
    cout << "Menu:\n";
    cout << "1. Kopi\n";
    cout << "2. Teh\n";
    cout << "3. Jus Jeruk\n";
    cout << "4. Air Mineral\n";
    cout << "0. Keluar\n";

    while (true) {
        cout << "\nPilih minuman (0 untuk keluar): ";
        cin >> pilihan;

        if (pilihan < 0 || pilihan > 4) {
            cout << "Menu tidak tersedia, coba lagi!" << endl;
            continue; // loncat ke loop berikutnya
        }

        if (pilihan == 0) {
            cout << "Terima kasih sudah menggunakan mesin minuman." << endl;
            break; // hentikan loop
        }

        // Panggil function sesuai pilihan
        if (pilihan == 1) {
            kopi();
        } else if (pilihan == 2) {
            teh();
        } else if (pilihan == 3) {
            jusJeruk();
        } else if (pilihan == 4) {
            airMineral();
        }
    }

    return 0;
}