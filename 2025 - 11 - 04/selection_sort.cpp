#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Masukkan elemen: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "\nSebelum Selection Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";

    selectionSort(arr);

    cout << "Sesudah Selection Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";
}
