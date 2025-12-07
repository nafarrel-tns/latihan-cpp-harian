#include <iostream>
#include <string>
using namespace std;

struct Contestant {
    string name;
    int A, B, C, D;
};

int totalScore(const Contestant &c) {
    return c.A + c.C;
}

int totalPenalty(const Contestant &c) {
    return c.B + c.D;
}

bool isGreater(const Contestant &x, const Contestant &y) {
    int scoreX = totalScore(x);
    int scoreY = totalScore(y);
    if(scoreX != scoreY) return scoreX > scoreY;
    int penX = totalPenalty(x);
    int penY = totalPenalty(y);
    if(penX != penY) return penX < penY;
    return x.name < y.name;
}

void sortContestants(Contestant arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(!isGreater(arr[j], arr[j+1])) {
                Contestant temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    Contestant contestants[100];
    for(int i=0;i<N;i++) {
        cin >> contestants[i].name >> contestants[i].A >> contestants[i].B >> contestants[i].C >> contestants[i].D;
    }
    sortContestants(contestants, N);
    for(int i=0;i<N;i++) {
        cout << contestants[i].name << "\n";
    }
    return 0;
}
