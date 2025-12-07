#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Masukkan elemen: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "\nSebelum Insertion Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";

    insertionSort(arr);

    cout << "Sesudah Insertion Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";
}
