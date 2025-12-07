#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tinggi = n; 
    int maxWidth = 2 * n - 1; 

    for (int bagian = 0; bagian < 3; bagian++) {
        for (int i = 1; i <= tinggi; i++) {
            int bintang = 2 * i - 1;
            int spasi = (maxWidth - bintang) / 2;
            for (int j = 0; j < spasi; j++) cout << " ";
            for (int j = 0; j < bintang; j++) cout << "*";
            cout << endl;
        }
        tinggi -= 2; 
    }

    int batang = n / 2; 
    for (int i = 0; i < batang; i++) {
        for (int j = 0; j < (maxWidth - 3) / 2; j++) cout << " ";
        cout << "***" << endl;
    }

    return 0;
}