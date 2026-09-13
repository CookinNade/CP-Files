#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    ll dist[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i == j)dist[i][j] = 0;
            if(i == j)dist[j][i] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        dist[a][b] = min(w,dist[a][b]);
        dist[b][a] = min(w,dist[b][a]);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b] == INF)cout<<"-1\n";
        else cout<<dist[a][b]<<'\n';
    }
    return 0;
    }