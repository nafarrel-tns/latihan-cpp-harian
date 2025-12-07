#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n-1; i++) {
        swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int* arr = new int[n];  

    cout << "Masukkan elemen: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nSebelum Bubble Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    bubbleSort(arr, n);

    cout << "Sesudah Bubble Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    delete[] arr;
}
