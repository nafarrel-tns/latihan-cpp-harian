#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUK = 50;
const int MAX_TOKO = 10;
const int MAX_RIWAYAT = 100;

struct Product {
    string nama;
    double hargaBeli;
    double hargaJual;
    int stok;
    int terjualHariIni;
    int terjualTotal;
};

struct Store {
    string nama;
    Product produk[MAX_PRODUK];
    int jumlahProduk;
    string riwayat[MAX_RIWAYAT];
    int jumlahRiwayat;
    int totalPembeli;
};

struct Business {
    Store toko[MAX_TOKO];
    int jumlahToko;
    double modal;
    double saldo;
    int hari;
};

// ================= Fungsi ================= //
void tambahProduk(Store &store, Business &biz) {
    if(store.jumlahProduk >= MAX_PRODUK) {
        cout << "Produk penuh!\n";
        return;
    }
    Product p;
    cout << "Nama produk: "; cin.ignore(); getline(cin, p.nama);
    cout << "Harga beli: Rp "; cin >> p.hargaBeli;
    cout << "Harga jual: Rp "; cin >> p.hargaJual;
    cout << "Stok awal: "; cin >> p.stok;
    if(p.hargaBeli*p.stok > biz.saldo) {cout<<"Modal tidak cukup!\n"; return;}
    biz.saldo -= p.hargaBeli*p.stok;
    p.terjualHariIni = 0;
    p.terjualTotal = 0;
    store.produk[store.jumlahProduk++] = p;
    store.riwayat[store.jumlahRiwayat++] = "Beli "+p.nama+" x"+to_string(p.stok)+" seharga Rp "+to_string((long long)(p.hargaBeli*p.stok));
    cout << "Produk berhasil ditambahkan. Sisa saldo: Rp " << (long long)biz.saldo << endl;
}

void lihatProduk(Store &store) {
    if(store.jumlahProduk==0){cout<<"Belum ada produk.\n"; return;}
    cout<<"=== Produk di "<<store.nama<<" ===\n";
    for(int i=0;i<store.jumlahProduk;i++){
        Product &p = store.produk[i];
        cout<<i+1<<". "<<p.nama
            <<" | HargaB: Rp "<<(long long)p.hargaBeli
            <<" | HargaJ: Rp "<<(long long)p.hargaJual
            <<" | Stok: "<<p.stok
            <<" | Terjual Total: "<<p.terjualTotal
            <<endl;
    }
}

void simulasi(Store &store, Business &biz) {
    if(store.jumlahProduk==0) return;
    int pembeli = rand()%5 + 1;
    for(int i=0;i<store.jumlahProduk;i++) store.produk[i].terjualHariIni=0;
    cout << "=== Hari "<<biz.hari<<" di "<<store.nama<<" ===\n";
    for(int i=0;i<pembeli;i++){
        int idx = rand() % store.jumlahProduk;
        int jumlah = rand()%3+1;
        if(store.produk[idx].stok >= jumlah){
            store.produk[idx].stok -= jumlah;
            store.produk[idx].terjualHariIni += jumlah;
            store.produk[idx].terjualTotal += jumlah;
            double profit = jumlah*store.produk[idx].hargaJual;
            biz.saldo += profit;
            store.riwayat[store.jumlahRiwayat++] = "Pembeli beli "+to_string(jumlah)+" "+store.produk[idx].nama+" -> Rp "+to_string((long long)profit);
            cout<<"Pembeli beli "<<jumlah<<" "<<store.produk[idx].nama<<" -> Rp "<<(long long)profit<<endl;
        }
    }
    store.totalPembeli += pembeli;
}

void lihatRiwayat(Store &store) {
    if(store.jumlahRiwayat==0){cout<<"Belum ada transaksi.\n"; return;}
    cout<<"=== Riwayat "<<store.nama<<" ===\n";
    for(int i=0;i<store.jumlahRiwayat;i++) cout<<"- "<<store.riwayat[i]<<endl;
}

void laporan(Store &store, Business &biz){
    double totalBeli=0,totalJual=0;
    for(int i=0;i<store.jumlahProduk;i++){
        Product &p = store.produk[i];
        totalBeli += p.hargaBeli*(p.terjualTotal + p.stok);
        totalJual += p.hargaJual*p.terjualTotal;
    }
    cout<<"=== Laporan "<<store.nama<<" ===\n";
    cout<<"Saldo: Rp "<<(long long)biz.saldo<<endl;
    cout<<"Total Penjualan: Rp "<<(long long)totalJual<<endl;
    cout<<"Total Belanja Produk: Rp "<<(long long)totalBeli<<endl;
    cout<<"Profit: Rp "<<(long long)(biz.saldo - biz.modal)<<endl;
}

// ================= Menu ================= //
void menu(Business &biz){
    int pilih;
    do{
        cout<<"\n=== SIMULASI BISNIS SEDERHANA ===\n";
        cout<<"Hari: "<<biz.hari<<" | Saldo: Rp "<<(long long)biz.saldo<<endl;
        cout<<"Toko tersedia:\n";
        for(int i=0;i<biz.jumlahToko;i++) cout<<i+1<<". "<<biz.toko[i].nama<<endl;
        cout<<"0. Tambah Toko\n";
        cout<<"Pilih toko (nomor): "; cin>>pilih;

        if(pilih==0){
            if(biz.jumlahToko>=MAX_TOKO){cout<<"Toko penuh!\n"; continue;}
            Store s; cout<<"Nama toko baru: "; cin.ignore(); getline(cin,s.nama);
            s.jumlahProduk=0; s.jumlahRiwayat=0; s.totalPembeli=0;
            biz.toko[biz.jumlahToko++] = s;
        }
        else if(pilih>0 && pilih<=biz.jumlahToko){
            Store &store = biz.toko[pilih-1];
            int menuToko;
            cout<<"1. Lihat Produk\n2. Tambah Produk\n3. Simulasi Hari\n4. Riwayat\n5. Laporan\n6. Kembali\nPilih: "; cin>>menuToko;
            switch(menuToko){
                case 1: lihatProduk(store); break;
                case 2: tambahProduk(store,biz); break;
                case 3: simulasi(store,biz); biz.hari++; break;
                case 4: lihatRiwayat(store); break;
                case 5: laporan(store,biz); break;
                case 6: break;
                default: cout<<"Pilihan tidak valid\n";
            }
        }
        else{cout<<"Pilihan tidak valid\n";}
    }while(true);
}

// ================= Main ================= //
int main(){
    srand(time(0));
    Business biz;
    biz.modal = 5000000;
    biz.saldo = biz.modal;
    biz.jumlahToko = 0;
    biz.hari = 1;
    cout<<"=== SELAMAT DATANG DI SIMULASI BISNIS SEDERHANA ===\n";
    menu(biz);
    return 0;
}
