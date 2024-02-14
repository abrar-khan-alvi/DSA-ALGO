#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define endl '\n'
#define faster ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N=10e5+10;

int parent[N];
int size[N];

void make(int v){
    parent[v]=v;
    size[v]=1;
}
int find(int v){
    if(v==parent[v])
    { return v; }
    
    return parent[v]=find(parent[v]);

}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(size[a]<size[b])
        swap(a,b);
    if(a!=b){
        parent[b]=a;
        size[a]+=size[b];
    }

}


int main()
{
faster;
int n,k;
cin>>n>>k;
vector<pair<int,pair<int,int> > > edges;
for(ll i=0;i<k;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges.push_back({w,{u,v}});
}
for(int i=1;i<=n;i++) make(i);
//sort(edges.begin(),edges.end());
sort(edges.rbegin(), edges.rend());
int total_cost=0;
for(auto &edge:edges){
    int w=edge.first;
    int u=edge.second.first;
    int v=edge.second.second;

    if(find(u)==find(v)) continue;
    Union(u,v);
    cout<<u<<" "<<v<<endl;
    total_cost+=w;
}
cout<<total_cost<<endl;
return 0;
}