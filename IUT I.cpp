#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+2;
ll vis[N];
ll dist[N];
vector<int>g[N];
const ll INF = 1e12;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        for(int i=1;i<=n;i++)g[i].clear();
        fill(vis+1,vis+1+n,0);
        fill(dist+1,dist+1+n,0);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            if(x==y)continue;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        queue<pair<ll,int>>q;
        q.push({0,b});
        while(!q.empty()){
            ll v = q.front().second;
            ll w = q.front().first;
            q.pop();

            for(auto c:g[v]){
                if(dist[c] or c == b)continue;
                vis[c]++;
                if(vis[c] == 2){
                    q.push({w+1,c});
                    dist[c] = w+1;
                }
            }
        }
        if(dist[a] == 0)cout<<-1<<'\n';
        else cout<<dist[a]<<'\n';

    }
    return 0;
}