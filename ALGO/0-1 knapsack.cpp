#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define endl '\n'
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() {
    ll n;  
    ll W;  
    cin >> n >> W;

    vector<ll> w(n + 1);  
    vector<ll> b(n + 1); 

    for (ll i = 1; i <= n; ++i) {
        cin >> w[i] >> b[i];
    }

    vector<vector<ll>> V(n + 1, vector<ll>(W + 1, 0));

    for (ll i = 1; i <= n; ++i) {
        for (ll weight = 1; weight <= W; ++weight) {
            if (w[i] <= weight) {
                if (b[i] + V[i - 1][weight - w[i]] > V[i - 1][weight]) {
                    V[i][weight] = b[i] + V[i - 1][weight - w[i]];
                } else {
                    V[i][weight] = V[i - 1][weight];
                }
            } else {
                V[i][weight] = V[i - 1][weight];
            }
        }
    }

    vector<bool> selected(n + 1, false);
    ll i = n;
    ll k = W;

    while (i > 0 && k > 0) {
        if (V[i][k] != V[i - 1][k]) {
            selected[i] = true;
            k -= w[i];
        }
        --i;
    }

  
    cout << "Selected items: "<<endl;
    for (ll i = 1; i <= n; ++i) {
        if (selected[i]) {
            cout <<"Item: "<< i << ", Value: "<<b[i]<<" "<<endl;
        }
    }
    cout<<endl;


    ll totalValue = 0;
    for (ll i = 1; i <= n; ++i) {
        if (selected[i]) {
            totalValue += b[i];
        }
    }
    cout << "Total value: " << totalValue << endl;

    return 0;
}
