#include <iostream>
using namespace std;

int main(){
    int tebakan, jawaban = 7;
    cout << "tebak angka 1-10: " ;
    cin >> tebakan;

    if (tebakan == jawaban){
        cout << "BENER PINTER BANGET";
    }
    else {
        if (tebakan < jawaban){
            cout << "TEBAKAN ANDA KEKECILAN";
        }
        else if (tebakan > jawaban){
            cout << "TEBAKAN ANDA KEGEDEAN";
        }
        
    }
   
    return 0;
    }
