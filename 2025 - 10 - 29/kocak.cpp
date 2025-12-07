#include <iostream>
using namespace std;

void judulGame() {
    cout << "=============================================\n";
    cout << "             BATTLESHIP WAR ZONE             \n";
    cout << "=============================================\n";
    cout << " Misi: Hancurkan semua kapal musuh!       \n";
    cout << " Tebak koordinat baris & kolom dengan jitu\n";
    cout << " Kapal ditaruh rahasia, cari & tenggelamkan\n";
    cout << " Ada 3 level dengan masing - masing 2 kapal\n";
    cout << "=============================================\n\n";
}

int main() {
    judulGame();
    int tebakan, level = 1, percobaan, skor;
    int n = 5;                 
    int nyawa = 5; 

    bool kena32 = false, kena33 = false;    
    bool kena54 = false, kena55 = false;    
    bool kena21 = false, kena22 = false;    

    cout << "Papan awal:\n  ";
    for (int j = 1; j <= n; j++) cout << j << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
        for (int j = 1; j <= n; j++) cout << "* ";
        cout << endl;
    }
    cout << endl;

    // ==================== LEVEL 1 ====================
    cout << "--- LEVEL 1 ---\n";
    percobaan = 0;    
    skor = 0;

    while (skor < 2 && nyawa > 0) {
        cout << "Masukkan tebakan Level 1 (misal 32 untuk baris 3 kolom 2): ";
        cin >> tebakan;
        percobaan++;

        if (tebakan == 32) {
            if (!kena32) {
                kena32 = true;
                skor++;
                cout << "Tebakan Benar! Kapal di (3,2)\n";
            } else {
                cout << "Kapal di (3,2) sudah ditemukan!\n";
            }
        }
        else if (tebakan == 33) {
            if (!kena33) {
                kena33 = true;
                skor++;
                cout << "Tebakan Benar! Kapal di (3,3)\n";
            } else {
                cout << "Kapal di (3,3) sudah ditemukan!\n";
            }
        }
        else {
            cout << "Tebakan Salah!\n";
            nyawa--;
            cout << "Nyawa tersisa: " << nyawa << endl;
        }

        cout << "  ";
        for (int j = 1; j <= n; j++) cout << j << " ";
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
            for (int j = 1; j <= n; j++) {
                if ((i == 3 && j == 2 && kena32) || (i == 3 && j == 3 && kena33))
                    cout << "X ";
                else
                    cout << "* ";
            }
            cout << endl;
        }
    }

    if (skor < 2) {
        cout << "Game Over di Level 1!\n";
        return 0;
    }
    cout << "Selamat! Lanjut ke Level 2!\n\n";

    // ==================== LEVEL 2 ====================
    cout << "--- LEVEL 2 ---\n";
    percobaan = 0;    
    skor = 0;

    while (skor < 2 && nyawa > 0) {
        cout << "Masukkan tebakan Level 2 (misal 54 untuk baris 5 kolom 4): ";
        cin >> tebakan;
        percobaan++;

        if (tebakan == 54) {
            if (!kena54) {
                kena54 = true;
                skor++;
                cout << "Tebakan Benar! Kapal di (5,4)\n";
            } else {
                cout << "Kapal di (5,4) sudah ditemukan!\n";
            }
        }
        else if (tebakan == 55) {
            if (!kena55) {
                kena55 = true;
                skor++;
                cout << "Tebakan Benar! Kapal di (5,5)\n";
            } else {
                cout << "Kapal di (5,5) sudah ditemukan!\n";
            }
        }
        else {
            cout << "Tebakan Salah!\n";
            nyawa--;
            cout << "Nyawa tersisa: " << nyawa << endl;
        }

        cout << "  ";
        for (int j = 1; j <= n; j++) cout << j << " ";
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
            for (int j = 1; j <= n; j++) {
                if ((i == 3 && j == 2 && kena32) || (i == 3 && j == 3 && kena33) ||
                    (i == 5 && j == 4 && kena54) || (i == 5 && j == 5 && kena55))
                    cout << "X ";
                else
                    cout << "* ";
            }
            cout << endl;
        }
    }

    if (skor < 2) {
        cout << "Game Over di Level 2!\n";
        return 0;
    }
    cout << "Hebat! Lanjut ke Level 3!\n\n";

    // ==================== LEVEL 3 ====================
    cout << "--- LEVEL 3 ---\n";
    percobaan = 0;    
    skor = 0;

    while (skor < 2 && nyawa > 0) {
        cout << "Masukkan tebakan Level 3 (misal 21 untuk baris 2 kolom 1): ";
        cin >> tebakan;
        percobaan++;

        if (tebakan == 21) {
            if (!kena21) {
                kena21 = true;
                skor++;
                cout << "Tebakan Benar! Kapal di (2,1)\n";
            } else {
                cout << "Kapal di (2,1) sudah ditemukan!\n";
            }
        }
        else if (tebakan == 22) {
            if (!kena22) {
                kena22 = true;
                skor++;
                cout << "Tebakan Benar! Kapal di (2,2)\n";
            } else {
                cout << "Kapal di (2,2) sudah ditemukan!\n";
            }
        }
        else {
            cout << "Tebakan Salah!\n";
            nyawa--;
            cout << "Nyawa tersisa: " << nyawa << endl;
        }

        cout << "  ";
        for (int j = 1; j <= n; j++) cout << j << " ";
        cout << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
            for (int j = 1; j <= n; j++) {
                if ((i == 3 && j == 2 && kena32) || (i == 3 && j == 3 && kena33) ||
                    (i == 5 && j == 4 && kena54) || (i == 5 && j == 5 && kena55) ||
                    (i == 2 && j == 1 && kena21) || (i == 2 && j == 2 && kena22))
                    cout << "X ";
                else
                    cout << "* ";
            }
            cout << endl;
        }
    }

    if (skor == 2)
        cout << "Selamat! Semua level selesai, kamu MENANG!\n";
    else
        cout << "Game Over di Level 3!\n";

    return 0;
}