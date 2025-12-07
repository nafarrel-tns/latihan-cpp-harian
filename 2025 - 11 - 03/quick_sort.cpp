#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Masukkan elemen: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nSebelum Quick Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    quickSort(arr, 0, n - 1);

    cout << "Sesudah Quick Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    delete[] arr; 
}
