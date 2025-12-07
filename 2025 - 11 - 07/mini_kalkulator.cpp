#include <iostream>
using namespace std;

double tambah(double a,double b){ return a+b; }
double kurang(double a,double b){ return a-b; }
double kali(double a,double b){ return a*b; }
double bagi(double a,double b){ return b!=0 ? a/b : 0; }

int main(){
    double x,y; char op;
    cout << "Masukkan operasi (contoh: 5 + 3): ";
    cin >> x >> op >> y;

    switch(op){
        case '+': cout << "Hasil: " << tambah(x,y) << "\n"; break;
        case '-': cout << "Hasil: " << kurang(x,y) << "\n"; break;
        case '*': cout << "Hasil: " << kali(x,y) << "\n"; break;
        case '/': cout << "Hasil: " << bagi(x,y) << "\n"; break;
        default: cout << "Operator tidak valid\n";
    }
}
