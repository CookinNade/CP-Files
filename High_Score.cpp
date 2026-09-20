#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll INF = 1e14;
ll val[2501];
vector<pair<ll,ll>>g[2501];
bool vis[2501];
ll n,m;
pair<ll,bool> dfs(int v){
    if(v == n)return {0,true};
    bool jabe = false;
    ll cost = -1e17;
    for(auto c:g[v]){
        if(vis[c.first])continue;
        vis[c.first] = true;
        pair<ll,bool>ans = dfs(c.first);
        if(ans.second){
            cost = max(ans.first,cost);
            jabe = true;
        }
    }
    return {cost,jabe};
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
    }
    fill(val+1,val+1+n,-1e17);
    val[1] = 0;
    for(int i=0;i<max(n-1,1ll);i++){
        for(int j=1;j<=n;j++){
            if(val[j] == -1e17)continue;
            // cout<<j<<endl;
            for(auto c:g[j]){
                int b = c.first;
                int a = j;
                ll w = c.second;
                
                val[b] = max(val[a] + w, val[b]);
                // cout<<b<<" "<<a<<" "<<w<<" "<<val[b]<<endl;
            }
        }
    }
    for(int i=0;i<max(n-1,1ll);i++){
        for(int j=1;j<=n;j++){
            if(val[j] == -1e17)continue;
            for(auto c:g[j]){
                int b = c.first;
                int a = j;
                ll w = c.second;
                if(val[a] + w > val[b] or val[a] == INF){
                    val[b] = INF;
                }
            }
        }
    }
    if(val[n] >= INF)cout<<-1;
    else cout<<val[n];
    return 0;
    }