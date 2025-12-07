#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
using namespace std;

// ==================== Utility ==================== //
void loading(string msg="Processing") {
    cout << msg;
    for(int i=0;i<3;i++){cout << "."; cout.flush(); this_thread::sleep_for(chrono::milliseconds(300));}
    cout << endl;
}

void coinEffect() {
    for(int i=0;i<5;i++){cout << "💰 "; cout.flush(); this_thread::sleep_for(chrono::milliseconds(100));}
    cout << endl;
}

// ==================== Structs ==================== //
struct Product {
    string nama;
    double hargaBeli;
    double hargaJual;
    int stok;
    int terjualHariIni;
    vector<int> terjualPerHari; // multi-hari
};

struct Store {
    string nama;
    vector<Product> produk;
    vector<string> riwayat;
    int totalPembeli=0;
};

struct Business {
    vector<Store> toko;
    double modal;
    double saldo;
    int hari=1;
};

// ==================== Fungsi Bisnis ==================== //
void tambahProduk(Store &store, Business &biz) {
    Product p;
    cout << "Nama produk: "; cin.ignore(); getline(cin,p.nama);
    cout << "Harga beli: Rp "; cin >> p.hargaBeli;
    cout << "Harga jual: Rp "; cin >> p.hargaJual;
    cout << "Stok awal: "; cin >> p.stok;
    if(p.hargaBeli*p.stok>biz.saldo) {cout<<"Modal tidak cukup!\n"; return;}
    biz.saldo -= p.hargaBeli*p.stok;
    p.terjualHariIni=0;
    store.produk.push_back(p);
    store.riwayat.push_back("Beli "+to_string(p.stok)+" "+p.nama+" seharga Rp "+to_string((long long)(p.hargaBeli*p.stok)));
    cout<<"Produk berhasil ditambahkan. Sisa saldo: Rp "<<fixed<<setprecision(0)<<biz.saldo<<endl;
}

void lihatProduk(Store &store) {
    if(store.produk.empty()){cout<<"Belum ada produk.\n"; return;}
    cout<<"=== Produk di "<<store.nama<<" ===\n";
    for(size_t i=0;i<store.produk.size();i++){
        cout<<i+1<<". "<<store.produk[i].nama<<" | HargaB: Rp "<<fixed<<setprecision(0)<<store.produk[i].hargaBeli
            <<" | HargaJ: Rp "<<store.produk[i].hargaJual
            <<" | Stok: "<<store.produk[i].stok
            <<" | Terjual Total: "<<(store.produk[i].terjualPerHari.empty()?0:accumulate(store.produk[i].terjualPerHari.begin(),store.produk[i].terjualPerHari.end(),0))<<endl;
    }
}

// Simulasi pembeli & karyawan
void simulasi(Store &store, Business &biz) {
    if(store.produk.empty()) return;
    int pembeli=rand()%5+1;
    for(auto &p:store.produk) p.terjualHariIni=0;
    cout<<"=== Hari "<<biz.hari<<" di "<<store.nama<<" ===\n";
    for(int i=0;i<pembeli;i++){
        int idx=rand()%store.produk.size();
        int jumlah=rand()%3+1;
        if(store.produk[idx].stok>=jumlah){
            double harga=store.produk[idx].hargaJual;
            if(store.produk[idx].stok<5) harga*=1.2; else if(store.produk[idx].stok>20) harga*=0.9;
            store.produk[idx].stok-=jumlah;
            store.produk[idx].terjualHariIni+=jumlah;
            store.produk[idx].terjualPerHari.push_back(jumlah);
            double profit=jumlah*harga;
            biz.saldo+=profit;
            store.riwayat.push_back("Pembeli beli "+to_string(jumlah)+" "+store.produk[idx].nama+" -> Rp "+to_string((long long)profit));
            cout<<"Pembeli beli "<<jumlah<<" "<<store.produk[idx].nama<<" -> Rp "<<fixed<<setprecision(0)<<profit<<endl;
            coinEffect();
        }
    }
    store.totalPembeli+=pembeli;
}

// Lihat riwayat transaksi
void lihatRiwayat(Store &store) {
    if(store.riwayat.empty()){cout<<"Belum ada transaksi.\n"; return;}
    cout<<"=== Riwayat "<<store.nama<<" ===\n";
    for(auto &s:store.riwayat) cout<<"- "<<s<<endl;
}

// Grafik multi-hari
void grafik(Store &store) {
    if(store.produk.empty()){cout<<"Belum ada produk.\n"; return;}
    cout<<"=== Grafik Penjualan Multi-Hari "<<store.nama<<" ===\n";
    for(auto &p:store.produk){
        cout<<p.nama<<" | ";
        for(auto x:p.terjualPerHari){
            for(int i=0;i<x;i++) cout<<"#";
        }
        cout<<" ("<<accumulate(p.terjualPerHari.begin(),p.terjualPerHari.end(),0)<<" unit)"<<endl;
    }
}

// Laporan keuangan
void laporan(Store &store,Business &biz){
    double totalBeli=0,totalJual=0;
    for(auto &p:store.produk){
        totalBeli+=p.hargaBeli*(accumulate(p.terjualPerHari.begin(),p.terjualPerHari.end(),0)+p.stok);
        totalJual+=p.hargaJual*accumulate(p.terjualPerHari.begin(),p.terjualPerHari.end(),0);
    }
    cout<<"=== Laporan "<<store.nama<<" ===\n";
    cout<<"Saldo: Rp "<<fixed<<setprecision(0)<<biz.saldo<<endl;
    cout<<"Total Penjualan: Rp "<<totalJual<<endl;
    cout<<"Total Belanja Produk: Rp "<<totalBeli<<endl;
    cout<<"Profit: Rp "<<biz.saldo-biz.modal<<endl;
}

// ==================== Menu ==================== //
void menu(Business &biz){
    int pilih;
    srand(time(0));
    do{
        cout<<"\n=== SIMULASI BISNIS SUPER ULTIMATE ===\n";
        cout<<"Hari: "<<biz.hari<<" | Saldo: Rp "<<fixed<<setprecision(0)<<biz.saldo<<endl;
        cout<<"Toko tersedia:\n";
        for(size_t i=0;i<biz.toko.size();i++) cout<<i+1<<". "<<biz.toko[i].nama<<endl;
        cout<<"0. Tambah Toko\n";
        cout<<"Pilih toko (nomor): "; cin>>pilih;

        if(pilih==0){
            Store s; cout<<"Nama toko baru: "; cin.ignore(); getline(cin,s.nama); biz.toko.push_back(s);
        }
        else if(pilih>0 && pilih<=(int)biz.toko.size()){
            Store &store=biz.toko[pilih-1];
            int menuToko;
            cout<<"1. Lihat Produk\n2. Tambah Produk\n3. Simulasi Hari (Pembeli+Karyawan)\n4. Riwayat\n5. Grafik Penjualan\n6. Laporan Keuangan\n7. Kembali\nPilih: "; cin>>menuToko;
            switch(menuToko){
                case 1: lihatProduk(store); break;
                case 2: tambahProduk(store,biz); break;
                case 3: simulasi(store,biz); biz.hari++; break;
                case 4: lihatRiwayat(store); break;
                case 5: grafik(store); break;
                case 6: laporan(store,biz); break;
                case 7: break;
                default: cout<<"Pilihan tidak valid\n";
            }
        }
        else{cout<<"Pilihan tidak valid\n";}
    }while(true);
}

// ==================== Main ==================== //
int main(){
    Business biz;
    biz.modal=5000000;
    biz.saldo=biz.modal;
    cout<<"=== SELAMAT DATANG DI SIMULASI BISNIS SUPER ULTIMATE ===\n";
    menu(biz);
    return 0;
}