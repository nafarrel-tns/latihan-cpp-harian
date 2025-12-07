#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr,int low,int high){
    int pivot=arr[high], i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr,int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Masukkan elemen: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "\nSebelum Quick Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";

    quickSort(arr,0,arr.size()-1);

    cout << "Sesudah Quick Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";
}
