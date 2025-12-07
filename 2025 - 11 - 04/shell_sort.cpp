#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr){
    int n = arr.size();
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp = arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
    }
}

int main(){
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Masukkan elemen: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "\nSebelum Shell Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";

    shellSort(arr);

    cout << "Sesudah Shell Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";
}
