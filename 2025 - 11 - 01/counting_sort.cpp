#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > maxVal) maxVal = arr[i];

    int* count = new int[maxVal + 1]{0}; 

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for(int i = 0; i <= maxVal; i++) {
        while(count[i]--) {
            arr[index++] = i;
        }
    }

    delete[] count; 
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Masukkan elemen (angka >= 0): ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nSebelum Counting Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    countingSort(arr, n);

    cout << "Sesudah Counting Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    delete[] arr; 
}
