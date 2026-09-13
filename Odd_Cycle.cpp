#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+2;
vector<int>g[N];
bool vis[N];
int parent[N];
int depth[N];
pair<int,int>dfs(int v){
    vis[v] = true;
    pair<int,int>ans = {0,0};
    for(auto c:g[v]){
        if(c == parent[v])continue;
        if(vis[c] and (depth[v] - depth[c] + 1) % 2)return {v,c};
        if(vis[c])continue;
        parent[c] = v;
        depth[c] = depth[v] + 1;
        ans = dfs(c);
        if(ans.first)return ans;
    }
    return ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)vis[i] = false;
        for(int i=1;i<=n;i++)depth[i] = 0;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            if(a==b)continue;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        pair<int,int>ans;
        ans = dfs(1);
        if(ans.first == 0){
            cout<<-1<<'\n';
            continue;
        }
        vector<int>v;
        int a = ans.first;
        while(true){
            v.push_back(a);
            if(a == ans.second)break;
            a = parent[a];
        }
        cout<<(int)v.size()<<'\n';
        for(auto x:v)cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    }