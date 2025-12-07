#include <iostream>
#include <string>
using namespace std;

int main() {
    string secretWord, guessWord;
    int maxAttempts = 6, attempts = 0;

    cout << "Player 1, masukkan kata rahasia: ";
    cin >> secretWord;
    cin.ignore();

    string display(secretWord.length(), '*'); // inisialisasi dengan '*'

    cout << "\n--- Game Dimulai ---\n";
    cout << "Kamu punya " << maxAttempts << " kesempatan untuk menebak.\n";

    while(attempts < maxAttempts && display != secretWord) {
        cout << "\nKata saat ini: " << display << "\n";
        cout << "Tebakan huruf: ";
        char guess;
        cin >> guess;

        bool found = false;
        for(int i = 0; i < secretWord.length(); i++){
            if(secretWord[i] == guess && display[i] != guess){
                display[i] = guess;
                found = true;
            }
        }

        if(found) {
            cout << "Benar!\n";
        } else {
            cout << "Salah!\n";
            attempts++;
        }

        cout << "Sisa kesempatan: " << maxAttempts - attempts << "\n";
    }

    if(display == secretWord) {
        cout << "\nSelamat! Kamu berhasil menebak kata: " << secretWord << "\n";
    } else {
        cout << "\nKesempatan habis. Kata yang benar: " << secretWord << "\n";
    }
}
