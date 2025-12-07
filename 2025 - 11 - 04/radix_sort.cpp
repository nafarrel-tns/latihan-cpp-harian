#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

void countingSortForRadix(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for(int i = n-1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for(int exp = 1; m/exp > 0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Masukkan elemen (angka >= 0): ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nSebelum Radix Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    radixSort(arr, n);

    cout << "Sesudah Radix Sort: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    delete[] arr;
}
