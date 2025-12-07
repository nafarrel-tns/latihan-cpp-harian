#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Masukkan elemen: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nSebelum Insertion Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    insertionSort(arr, n);

    cout << "Sesudah Insertion Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    delete[] arr; 
}
