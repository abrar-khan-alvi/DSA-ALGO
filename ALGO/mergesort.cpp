#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

void Merge(ll low, ll mid, ll high, ll A[])
{
    ll m = mid - low + 1;
    ll n = high - mid;
    ll arr[m + 1], brr[n + 1];

    for (ll i = 0; i < m; i++)
    {
        arr[i] = A[low + i];
    }
    for (ll i = 0; i < n; i++)
    {
        brr[i] = A[mid + i + 1];
    }
    arr[m] = INT_MAX;
    brr[n] = INT_MAX;
    //Ziyad aka YOUR_VARIABLE
    ll p, q, r;

    p = q = 0;
    // r = low;

    for (ll r = low; r <= high; r++)
    {
        if (arr[p] <= brr[q])
        {
            A[r] = arr[p];
            p++;
        }
        else
        {
            A[r] = brr[q];
            q++;
        }
    }
}

void MERGE_SORT(ll low, ll high, ll Array[])
{
    if (low < high)
    {
        ll mid = (low + high) / 2;

        MERGE_SORT(low, mid, Array);
        MERGE_SORT(mid + 1, high, Array);

        Merge(low, mid, high, Array);
    }
}

int main()
{
    ll arr[] = {5,8,9,47,7,1,2,65,990,4,5265,4645};
    MERGE_SORT(0, 12, arr);

    for (ll i = 0; i < 12; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}