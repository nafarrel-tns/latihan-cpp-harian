#include <iostream>
using namespace std;

const int N = 5; 
char papan[N+1][N+1]; 

int nyawa = 5;  // nyawa pemain

// ==================== JUDUL GAME ====================
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

// ==================== RESET PAPAN ====================
void resetPapan() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            papan[i][j] = '*';
        }
    }
}

// ==================== CETAK PAPAN ====================
void cetakPapan() {
    cout << "   ";
    for (int j = 1; j <= N; j++) cout << j << " ";
    cout << endl;
    for (int i = 1; i <= N; i++) {
        cout << i << "  ";
        for (int j = 1; j <= N; j++) {
            cout << papan[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Nyawa: " << nyawa << "\n\n";
}

// ==================== CEK STATUS ====================
bool cekStatusGame(int skor, int& level) {
    if (skor == 2 && level == 3) {
        cout << "Selamat! Semua kapal sudah dihancurkan, kamu MENANG!\n";
        return false; 
    } else if (skor == 2) {
        level++;
        cout << "Level selesai! Naik ke Level " << level << "!\n\n";
        return true; 
    } else if (nyawa <= 0) {
        cout << "Nyawamu habis! Game Over di Level " << level << "!\n";
        return false;
    } else {
        cout << "Game Over di Level " << level << "!\n";
        return false; 
    }
}

// ==================== MAIN GAME ====================
bool mainGame(int &level, int kapal[2][2]) {
    int percobaan = 0, skor = 0;
    resetPapan();
    cout << "=== LEVEL " << level << " ===\n\n";

    while (skor < 2 && nyawa > 0) {
        cetakPapan();
        int x, y;
        cout << "Masukkan tebakan Level " << level << " (baris kolom): ";
        cin >> x >> y;
        percobaan++;

        bool kena = false;
        for (int k = 0; k < 2; k++) {
            if (kapal[k][0] == x && kapal[k][1] == y) {
                if (papan[x][y] == 'X') {
                    cout << "Kapal di (" << x << "," << y << ") sudah kena sebelumnya!\n";
                } else {
                    papan[x][y] = 'X';
                    skor++;
                    cout << "BOOM! Kapal musuh di (" << x << "," << y << ") tenggelam!\n";
                }
                kena = true;
                break;
            }
        }
        if (!kena) {
            if (papan[x][y] == 'O') {
                cout << "Kamu sudah menembak sini, tetap meleset!\n";
            } else {
                papan[x][y] = 'O';
                nyawa--; 
                cout << "Meleset! Tidak ada kapal di (" << x << "," << y << ")\n";
                cout << "Nyawa tersisa: " << nyawa << endl;
            }
        }
        cout << endl;
    }
    return cekStatusGame(skor, level);
}

// ==================== MAIN ====================
int main() {
    judulGame();   
    int level = 1;

    // level 1: kapal di (3,2) & (3,3)
    int kapal1[2][2] = {{3,2},{3,3}};
    if (!mainGame(level, kapal1)) return 0;

    // level 2: kapal di (5,4) & (5,5)
    int kapal2[2][2] = {{5,4},{5,5}};
    if (!mainGame(level, kapal2)) return 0;

    // level 3: kapal di (2,1) & (2,2)
    int kapal3[2][2] = {{2,1},{2,2}};
    if (!mainGame(level, kapal3)) return 0;

    return 0;
}