// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 2;
int parent[N];
int sz[N];
int find (int a){
    if(a ==  parent[a])return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return;
}
vector<int>g[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a = find(a);
        b = find(b);
        if(a == b)continue;
        Union(a,b);
    }
    for(int i=0;i<n;i++){
        int a = i;
        a = find(a);
        g[a].push_back(i);
    }
    
    set<pair<int,int>>st;
    for(int i=0;i<n;i++){
        if(g[i].empty())continue;
        st.insert({ (int)g[i].size() , i });
    }
    // cout<<(int)st.size()<<" this is size\n";
    vector<pair<int,int>>ans;
    while((int)st.size() > 1){
        auto it = --st.end();
        auto nit = it;
        --it;
        int i = (*it).first - 1;
        int j = (*nit).first - 1;
        int a = (*it).second;
        int b = (*nit).second;
        st.erase(it);
        st.erase(nit);
        ans.push_back({g[a][i] , g[b][j]});
        if(i!=0)st.insert({i,a});
        if(j!=0)st.insert({j,b});
    }
    cout<<(int)ans.size()<<'\n';
    for(auto x:ans)cout<<x.first<<" "<<x.second<<'\n';
    // cout<<"okay\n";
}