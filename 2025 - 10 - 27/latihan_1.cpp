#include <bits/stdc++.h>
using namespace std;

struct Contestant {
    string name;
    int A, B, C, D;
};

// Fungsi pembanding custom untuk sorting
bool cmp(const Contestant &x, const Contestant &y) {
    int totalX = x.A + x.C;
    int totalY = y.A + y.C;
    if (totalX != totalY) return totalX > totalY; // poin lebih besar dulu

    int penaltyX = x.B + x.D;
    int penaltyY = y.B + y.D;
    if (penaltyX != penaltyY) return penaltyX < penaltyY; // penalti lebih kecil dulu

    return x.name < y.name; // nama lexicographically lebih kecil dulu
}

int main() {
    int N;
    cin >> N;

    vector<Contestant> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].name >> v[i].A >> v[i].B >> v[i].C >> v[i].D;
    }

    sort(v.begin(), v.end(), cmp);

    for (auto &c : v) {
        cout << c.name << "\n";
    }

    return 0;
}
