#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for(int gap = n/2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Masukkan elemen: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nSebelum Shell Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    shellSort(arr, n);

    cout << "Sesudah Shell Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    delete[] arr; 
}
