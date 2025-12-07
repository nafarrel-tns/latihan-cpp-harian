#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Masukkan jumlah baris: ";
    cin >> rows;
    cout << "Masukkan jumlah kolom: ";
    cin >> cols;

    // Membuat tabel perkalian
    cout << "\n--- Tabel Perkalian ---\n";
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=cols; j++){
            cout << i*j << "\t";
        }
        cout << "\n";
    }

    // Mencetak pola segitiga angka berdasarkan kolom
    cout << "\n--- Pola Segitiga Angka ---\n";
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << "\n";
    }

    // Checker: print angka ganjil di tabel perkalian
    cout << "\n--- Angka Ganjil di Tabel ---\n";
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            if((i*j) % 2 != 0){
                cout << i*j << "\t";
            } else {
                cout << "-\t"; // tanda untuk angka genap
            }
        }
        cout << "\n";
    }

    // Hitung jumlah angka genap dan ganjil
    int countEven=0, countOdd=0;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            if((i*j) % 2 == 0) countEven++;
            else countOdd++;
        }
    }
    cout << "\nJumlah angka genap: " << countEven << "\n";
    cout << "Jumlah angka ganjil: " << countOdd << "\n";

    // Bonus: cari angka terbesar di tabel perkalian
    int maxNum=0;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            if(i*j > maxNum) maxNum = i*j;
        }
    }
    cout << "Angka terbesar di tabel perkalian: " << maxNum << "\n";
}
