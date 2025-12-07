#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(vector<int>& arr){ return *max_element(arr.begin(),arr.end()); }

void countingSortForRadix(vector<int>& arr,int exp){
    int n = arr.size();
    vector<int> output(n);
    int count[10]={0};
    for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++) arr[i]=output[i];
}

void radixSort(vector<int>& arr){
    int m = getMax(arr);
    for(int exp=1;m/exp>0;exp*=10)
        countingSortForRadix(arr,exp);
}

int main(){
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Masukkan elemen (angka >= 0): ";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "\nSebelum Radix Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";

    radixSort(arr);

    cout << "Sesudah Radix Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";
}
