#include <iostream>
using namespace std;

struct Student {
    string name;
    int *scores;
    int numSubjects;
};

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();

    Student *students = new Student[n]; // array dynamic student

    // Input data mahasiswa
    for(int i=0;i<n;i++){
        cout << "\n=== Mahasiswa ke-" << i+1 << " ===\n";
        cout << "Nama: ";
        getline(cin, students[i].name);
        cout << "Jumlah mata pelajaran: ";
        cin >> students[i].numSubjects;
        cin.ignore();

        students[i].scores = new int[students[i].numSubjects]; // dynamic array untuk score
        for(int j=0;j<students[i].numSubjects;j++){
            cout << "Nilai mata pelajaran ke-" << j+1 << ": ";
            cin >> students[i].scores[j];
        }
        cin.ignore();
    }

    // Menampilkan data dan rata-rata
    cout << "\n=== Daftar Mahasiswa dan Rata-Rata ===\n";
    for(int i=0;i<n;i++){
        int sum = 0;
        cout << "Nama: " << students[i].name << "\nNilai: ";
        for(int j=0;j<students[i].numSubjects;j++){
            cout << students[i].scores[j] << " ";
            sum += students[i].scores[j];
        }
        double avg = (double)sum / students[i].numSubjects;
        cout << "\nRata-rata: " << avg << "\n\n";
    }

    // Cari mahasiswa dengan nilai rata-rata tertinggi
    double maxAvg = -1;
    int idxMax = -1;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<students[i].numSubjects;j++){
            sum += students[i].scores[j];
        }
        double avg = (double)sum / students[i].numSubjects;
        if(avg > maxAvg){
            maxAvg = avg;
            idxMax = i;
        }
    }
    cout << "Mahasiswa dengan rata-rata tertinggi: " << students[idxMax].name
         << " (" << maxAvg << ")\n";

    // Dealokasi memori dynamic
    for(int i=0;i<n;i++){
        delete[] students[i].scores;
    }
    delete[] students;

    cout << "Program selesai.\n";
}
