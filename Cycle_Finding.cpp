#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2501;
vector<pair<int,int>>g[N];
ll dist[N];
// const ll NEG = -1e13;
int parent[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
    }
    pair<int,int>ans = {0,0};
    for(int i=0;i<n-1;i++){
        for(int v=1;v<=n;v++){
            for(auto edge : g[v]){
                int c = edge.first;
                ll w = edge.second;
                if(dist[c] > dist[v] +  w){
                    dist[c] = dist[v] + w;
                    parent[c] = v;
                }
            }
        }
    }
    for(int v=1;v<=n;v++){
        for(auto edge : g[v]){
            int c = edge.first;
            ll w = edge.second;
            if(dist[c] > dist[v] +  w){
                ans = {c,v};
                parent[c] = v;
            }
        }
    }
    if(ans.first == 0){
        cout<<"NO";
        return 0;
    }
    vector<int>v;
    cout<<"YES\n";
    v.push_back(ans.second);
    int a = ans.second;
    while(a!=ans.first){
        a = parent[a];
        v.push_back(a);        
    }
    reverse(v.begin(),v.end());
    v.push_back(ans.first);
    for(auto x:v)cout<<x<<" ";
    return 0;
    }