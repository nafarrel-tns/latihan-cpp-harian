#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    float ipk;
};

void insertionSort(Mahasiswa mhs[], int n) {
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

int main() {
    int n;
    cout << "Jumlah mahasiswa: ";
    cin >> n;
    Mahasiswa mhs[100];
    cin.ignore();
    for(int i=0;i<n;i++){
        cout << "Nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, mhs[i].nama);
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    cout << "\nSebelum sorting (IPK):\n";
    for(int i=0;i<n;i++) cout << mhs[i].nama << " - " << mhs[i].ipk << "\n";

    insertionSort(mhs, n);

    cout << "\nSesudah sorting (IPK):\n";
    for(int i=0;i<n;i++) cout << mhs[i].nama << " - " << mhs[i].ipk << "\n";
}
