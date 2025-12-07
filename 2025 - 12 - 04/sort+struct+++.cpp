#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Mahasiswa{
    string nama;
    float ipk;
};

void insertionSort(vector<Mahasiswa>& mhs){
    int n = mhs.size();
    for(int i=1;i<n;i++){
        Mahasiswa key = mhs[i];
        int j = i-1;
        while(j>=0 && mhs[j].ipk > key.ipk){
            mhs[j+1] = mhs[j];
            j--;
        }
        mhs[j+1] = key;
    }
}

int main(){
    int n;
    cout << "Jumlah mahasiswa: ";
    cin >> n;
    vector<Mahasiswa> mhs(n);
    cin.ignore();
    for(int i=0;i<n;i++){
        cout << "Nama mahasiswa ke-" << i+1 << ": ";
        getline(cin,mhs[i].nama);
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    cout << "\nSebelum sorting (IPK):\n";
    for(auto &m: mhs) cout << m.nama << " - " << m.ipk << "\n";

    insertionSort(mhs);

    cout << "\nSesudah sorting (IPK):\n";
    for(auto &m: mhs) cout << m.nama << " - " << m.ipk << "\n";
}
