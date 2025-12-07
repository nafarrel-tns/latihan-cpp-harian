#include <iostream>
using namespace std;

int main(){
    int a;
    cout << "Masukkan nilai: ";
    cin >> a;

    int* p = &a;
    *p += 10;

    cout << "Nilai setelah ditambah 10: " << a << "\n";
}
