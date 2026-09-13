#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>g[n+1];
    bool vis[n+1];
    fill(vis,vis+n+1,false);
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
    }
    ll dist[n+1];
    fill(dist,dist+1+n,1e17);
    dist[1] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>q;
    q.push({0,1});
    while(!q.empty()){
        ll v = q.top().second;
        ll d = q.top().first;
        q.pop();
        // cout<<v<<endl;
        if(vis[v])continue;
        vis[v] = true;
        for(auto c:g[v]){
            if(vis[c.first])continue;
            if(dist[c.first] > c.second + d){
                q.push({c.second+d,c.first});
                dist[c.first] = c.second + d;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";

    return 0;
    }