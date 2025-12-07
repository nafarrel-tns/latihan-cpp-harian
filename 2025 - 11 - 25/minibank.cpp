#include <iostream>
#include <string>
using namespace std;

struct Account{
    string nama;
    int saldo;
};

int main(){
    int n=0, pilihan;
    Account accounts[10];

    while(true){
        cout << "\n--- Mini Bank ---\n1. Tambah Akun\n2. Cek Saldo\n3. Deposit\n4. Keluar\nPilih: ";
        cin >> pilihan;

        if(pilihan==1){
            if(n>=10){cout<<"Maksimal akun tercapai!\n"; continue;}
            cin.ignore();
            cout << "Nama: "; getline(cin,accounts[n].nama);
            cout << "Saldo awal: "; cin >> accounts[n].saldo;
            n++;
        }
        else if(pilihan==2){
            cin.ignore();
            string cari; cout << "Nama akun: "; getline(cin,cari);
            bool found=false;
            for(int i=0;i<n;i++){
                if(accounts[i].nama==cari){
                    cout << "Saldo: " << accounts[i].saldo << "\n";
                    found=true;
                }
            }
            if(!found) cout << "Akun tidak ditemukan!\n";
        }
        else if(pilihan==3){
            cin.ignore();
            string cari; cout << "Nama akun: "; getline(cin,cari);
            bool found=false;
            for(int i=0;i<n;i++){
                if(accounts[i].nama==cari){
                    int dep; cout << "Jumlah deposit: "; cin >> dep;
                    accounts[i].saldo += dep;
                    cout << "Saldo baru: " << accounts[i].saldo << "\n";
                    found=true;
                }
            }
            if(!found) cout << "Akun tidak ditemukan!\n";
        }
        else break;
    }
}
