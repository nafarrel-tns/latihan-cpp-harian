#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item{
    string nama;
    int harga;
};

int main(){
    vector<Item> cart;
    int pilihan;
    while(true){
        cout << "\n1. Tambah Item\n2. Lihat Cart\n3. Total Harga\n4. Keluar\nPilih: ";
        cin >> pilihan; cin.ignore();
        if(pilihan==1){
            Item it; cout << "Nama: "; getline(cin,it.nama);
            cout << "Harga: "; cin >> it.harga; cin.ignore();
            cart.push_back(it);
        } else if(pilihan==2){
            for(auto &it: cart) cout << it.nama << " - " << it.harga << "\n";
        } else if(pilihan==3){
            int total=0;
            for(auto &it: cart) total+=it.harga;
            cout << "Total harga: " << total << "\n";
        } else break;
    }
}
