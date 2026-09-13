#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[b].push_back(a);
        g[a].push_back(b);
    }
    queue<pair<int,int>>q;
    q.push({1,0});
    bool vis[n+1];
    int path[n+1];
    fill(vis,vis+1+n,false);
    int ans = -1;
    while(!q.empty()){
        int v = q.front().first;
        int d = q.front().second;
        q.pop();
        if(v == n){
            ans = d;
            break;
        }
        for(auto c : g[v]){
            if(vis[c])continue;
            vis[c] = true;
            q.push({c,d+1});
            path[c] = v;
        }
    }
    if(ans == -1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int>v;
    int a = n;
    while(true){
        v.push_back(a);
        if(a==1)break;
        a = path[a];
    }
    reverse(v.begin(),v.end());
    cout<<ans+1<<"\n";
    for(auto x:v)cout<<x<<" ";
    return 0;
    }