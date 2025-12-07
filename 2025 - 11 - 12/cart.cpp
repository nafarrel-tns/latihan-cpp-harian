#include <iostream>
#include <string>
using namespace std;

struct Item {
    string nama;
    int harga;
};

int main() {
    const int MAX_ITEMS = 100;
    Item cart[MAX_ITEMS];
    int jumlah = 0;
    int pilihan;

    while(true) {
        cout << "\n1. Tambah Item\n2. Lihat Cart\n3. Total Harga\n4. Keluar\nPilih: ";
        cin >> pilihan; cin.ignore();

        if(pilihan == 1) {
            if(jumlah >= MAX_ITEMS) { 
                cout << "Cart penuh!\n"; 
                continue; 
            }
            cout << "Nama: "; getline(cin, cart[jumlah].nama);
            cout << "Harga: "; cin >> cart[jumlah].harga; cin.ignore();
            jumlah++;
        } 
        else if(pilihan == 2) {
            if(jumlah == 0) { cout << "Cart kosong!\n"; continue; }
            for(int i = 0; i < jumlah; i++)
                cout << cart[i].nama << " - " << cart[i].harga << "\n";
        } 
        else if(pilihan == 3) {
            int total = 0;
            for(int i = 0; i < jumlah; i++) total += cart[i].harga;
            cout << "Total harga: " << total << "\n";
        } 
        else break;
    }
}
