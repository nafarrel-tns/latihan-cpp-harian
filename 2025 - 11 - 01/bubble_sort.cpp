#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    bool swapped;
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
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
    vector<int> arr(n);
    cout << "Masukkan elemen: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "\nSebelum Bubble Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";

    bubbleSort(arr);

    cout << "Sesudah Bubble Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";
}
