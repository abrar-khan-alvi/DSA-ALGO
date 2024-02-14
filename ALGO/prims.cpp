#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define SIZE 1000
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

const ll INF = 1e9; // Infinity value

// Globally declared graph,weight,parent,inQueue

vector<vector<pair<ll, ll>>> graph;
vector<ll> weight;
vector<ll> parent;
vector<bool> inQueue;

//Prims Algorithm
void primMST(ll start)
{
    ll n = graph.size();
    weight.resize(n, INF);
    parent.resize(n, -1);
    inQueue.resize(n, true);

    weight[start] = 0;

    priority_queue<pair<ll, ll>> pq;

    pq.push({weight[start], start});

    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        inQueue[u] = false;

        for (auto edge : graph[u])
        {
            ll v = edge.first;
            ll w = edge.second;
            //cout<<v<<"   "<<w<<endl;
            if (inQueue[v] && w < weight[v])
            {
                parent[v] = u;
                weight[v] = w;
                pq.push({weight[v], v});
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;

    graph.resize(n);

    for (ll i = 0; i < e; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, -w}); // Take the negative of the weight
        graph[v].push_back({u, -w}); // Take the negative of the weight
    }

    ll start;
    cin >> start;

    primMST(start);

    cout << "Included Edges:" << endl;
    for (ll i = 0; i < n; ++i)
    {
        if (parent[i] != -1)
            cout << parent[i] << " " << i << endl;
    }

    cout << "Maximum Cost:" << endl;
    ll maximumCost = 0;
    for (ll i = 0; i < n; ++i)
        maximumCost -= weight[i]; // Take the negative to get the maximum cost
    cout << maximumCost << endl;

    return 0;
}
