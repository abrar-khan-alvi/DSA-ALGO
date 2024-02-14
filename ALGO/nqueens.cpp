#include<bits/stdc++.h>
#define INF INT_MAX 
#define N 10000
using namespace std;
int x[N];

bool place( int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } else {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    
    int n;
    cin >> n;
    NQueens(1, n);

    return 0;
}
