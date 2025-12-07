#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> todos;
    int pilihan;
    while(true){
        cout << "\n--- Todo List ---\n1. Tambah\n2. Hapus\n3. Lihat\n4. Keluar\nPilih: ";
        cin >> pilihan; cin.ignore();
        if(pilihan==1){
            string task; cout << "Masukkan tugas: "; getline(cin,task);
            todos.push_back(task);
        }
        else if(pilihan==2){
            string task; cout << "Masukkan tugas yang dihapus: "; getline(cin,task);
            bool found=false;
            for(int i=0;i<todos.size();i++){
                if(todos[i]==task){
                    todos.erase(todos.begin()+i);
                    found=true;
                    break;
                }
            }
            if(!found) cout << "Tugas tidak ditemukan!\n";
        }
        else if(pilihan==3){
            cout << "Daftar tugas:\n";
            for(auto &t: todos) cout << "- " << t << "\n";
        }
        else break;
    }
}
