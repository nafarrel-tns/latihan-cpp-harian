#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minIndex]) minIndex = j;

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Masukkan elemen: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nSebelum Selection Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    selectionSort(arr, n);

    cout << "Sesudah Selection Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    delete[] arr; 
}
