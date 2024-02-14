#include <bits/stdc++.h>

using namespace std;

int MatrixChainOrder(int p[], int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int row = 0; row < n - len + 1; row++) {
            
            int col = row + len - 1;

            dp[row][col] = INT_MAX;

            for (int k = row; k < col; k++) {
                dp[row][col] = min(dp[row][col], dp[row][k] + dp[k + 1][col] + p[row] * p[k + 1] * p[col + 1]);
            }
        }
    }

    return dp[0][n - 1]; 
}

int main() {
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    int mcm = MatrixChainOrder(arr, N - 1);
    cout << mcm << endl;
    return 0;
}
