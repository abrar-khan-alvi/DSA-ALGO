#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define endl '\n'
#define faster ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() {
    faster;
    ll n, m;
    cin >> n >> m;
    ll w[n], p[n];
    ld x[n] = {0.0};
    ld profit = 0.0;
    for (ll i = 0; i < n; i++)
        cin >> w[i];

    for (ll i = 0; i < n; i++)
        cin >> p[i];

    vector<pair<ld, ll>> ratios; 
    for (ll i = 0; i < n; i++)
        ratios.push_back({double(p[i]) / w[i], i});

    sort(ratios.begin(), ratios.end()); 
    
    for (auto ratioItem : ratios) {
        ll i = ratioItem.second;
        if (w[i] <= m) {
            x[i] = 1.0;
            profit += p[i];
            m -= w[i];
        } else {
            x[i] = double(m) / w[i];
            profit += x[i] * p[i];
            break;
        }
    }

    cout << "Fraction taken of each item:" << endl;
    for (ll i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": " << x[i] << endl;
    }

    cout << "Total Profit: " << profit << endl;

    return 0;
}
