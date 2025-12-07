#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama;
    int harga;
};

int main() {
    int n;
    cout << "Jumlah barang: ";
    cin >> n;
    cin.ignore();

    Barang daftar[100];
    Barang* ptr;

    for(int i=0;i<n;i++){
        ptr = &daftar[i];
        cout << "Nama barang ke-" << i+1 << ": ";
        getline(cin, ptr->nama);
        cout << "Harga: ";
        cin >> ptr->harga;
        cin.ignore();
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(daftar[j].harga < daftar[j+1].harga){
                Barang temp = daftar[j];
                daftar[j] = daftar[j+1];
                daftar[j+1] = temp;
            }
        }
    }

    cout << "\n=== Daftar Barang setelah sorting (harga tertinggi) ===\n";
    for(int i=0;i<n;i++){
        ptr = &daftar[i];
        cout << ptr->nama << " - Rp " << ptr->harga << "\n";
    }

    int total = 0;
    for(ptr = daftar; ptr < daftar+n; ptr++){
        total += ptr->harga;
    }
    cout << "Total harga semua barang: Rp " << total << "\n";
}
