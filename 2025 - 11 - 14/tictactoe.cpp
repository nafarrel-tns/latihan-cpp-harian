#include <iostream>
using namespace std;

char board[3][3];

void initBoard(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) board[i][j]=' ';
}

void printBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << board[i][j];
            if(j<2) cout << "|";
        }
        cout << "\n";
        if(i<2) cout << "-+-+-\n";
    }
}

bool checkWin(char p){
    for(int i=0;i<3;i++)
        if(board[i][0]==p && board[i][1]==p && board[i][2]==p) return true;
    for(int j=0;j<3;j++)
        if(board[0][j]==p && board[1][j]==p && board[2][j]==p) return true;
    if(board[0][0]==p && board[1][1]==p && board[2][2]==p) return true;
    if(board[0][2]==p && board[1][1]==p && board[2][0]==p) return true;
    return false;
}

int main(){
    initBoard();
    char player='X';
    int moves=0;
    while(moves<9){
        printBoard();
        int r,c; cout << "Player " << player << " baris kolom: ";
        cin >> r >> c;
        if(board[r][c]==' '){
            board[r][c]=player;
            if(checkWin(player)){
                printBoard();
                cout << "Player " << player << " menang!\n";
                return 0;
            }
            player = (player=='X')?'O':'X';
            moves++;
        } else cout << "Sudah diisi!\n";
    }
    cout << "Seri!\n";
}
