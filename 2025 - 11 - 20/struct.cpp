#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
};

int main() {
    Mahasiswa mhs;
    cout << "Masukkan nama mahasiswa: ";
    getline(cin, mhs.nama);
    cout << "Masukkan umur: ";
    cin >> mhs.umur;
    cout << "Masukkan IPK: ";
    cin >> mhs.ipk;

    cout << "\nData Mahasiswa:\n";
    cout << "Nama: " << mhs.nama << "\n";
    cout << "Umur: " << mhs.umur << "\n";
    cout << "IPK: " << mhs.ipk << "\n";
}
