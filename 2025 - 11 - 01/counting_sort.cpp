#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr){
    int maxVal = *max_element(arr.begin(),arr.end());
    vector<int> count(maxVal+1,0);
    for(int x: arr) count[x]++;
    int index=0;
    for(int i=0;i<=maxVal;i++)
        while(count[i]--) arr[index++] = i;
}

int main(){
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Masukkan elemen (angka >= 0): ";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "\nSebelum Counting Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";

    countingSort(arr);

    cout << "Sesudah Counting Sort: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";
}
