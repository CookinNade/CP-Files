#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2e5+1;
vector<int>g[N];
bool cr [N];
int val[N];
int a , b;
int dfs(int v, int p){
    if(v == b)return 0;
    if(val[v] != 0) return val[v];

    int k1 = INT_MAX ;
    int k2 = INT_MAX ;
    cr[v] = true;
    for(auto c : g[v]){
        if(cr[c])continue;
        int k = 1 + dfs(c,v);
        if (!k)continue;
        if(k < k1){
            k2 = k1;
            k1 = k;
        }
        else if(k < k2){
            k2 = k;
        }
    }
    if(k2 == INT_MAX) k2 = -1;
    cr[v] = false;
    return val[v] = k2;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt; 
    int m;
    cin>>t;
    while (t--){
        cin>>n>>m>>a>>b;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            if(x==y)continue;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout<<dfs(a,0)<<'\n';
        for(int i=0;i<=n;i++)g[i].clear();
        for(int i=0;i<=n;i++){
            val[i] = 0;
        }
    }
    return 0;
    }