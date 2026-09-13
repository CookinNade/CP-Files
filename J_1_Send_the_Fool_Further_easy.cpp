#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=105;bool vis[N];
ll h[N];vector<pair<ll,ll>>g[N];
void dfs(ll child){

    vis[child]=true;
    for(auto v:g[child]){
        if(vis[v.first])continue;
        h[v.first]=h[child]+v.second;
        dfs(v.first);
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    fill(vis,vis+n,false);
    dfs(0);
    cout<<*max_element(h,h+n)<<endl;
    return 0;
    }