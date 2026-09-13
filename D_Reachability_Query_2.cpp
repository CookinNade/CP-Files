#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll n,m;
const ll N=3e5+5;
vector<ll>g[N+1];  
bool vis[N+1];
void dfs(ll v){
    vis[v]=true;
    for(auto child : g[v]){
        if(vis[child])continue;
        dfs(child);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d,cnt,r,l,k,q; 
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[b].push_back(a);
    }
    cin>>q;
    while(q--){
        cin>>a>>b;
        if(a==1){
            if(vis[b])continue;
            else dfs(b);
        }
        else {
            if(vis[b])cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
    }