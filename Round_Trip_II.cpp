#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e5+2;
vector<int>g[N];
int parent[N];
int vis[N];
pair<int,int>dfs(int v){
    if(vis[v] == 2)return {0,0};
    // cout<<v<<endl;
    vis[v] = 1;
    for(auto c:g[v]){
        if(vis[c] == 2)continue;
        if(vis[c] == 1)return {c,v};
        parent[c] = v;
        pair<int,int>ans = dfs(c);
        if(ans.first)return ans;
    }
    vis[v] = 2;
    return {0,0};
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    pair<int,int>ans = {0,0};
    vector<int>v;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" er childs : ";
    //     for(auto x:g[i])cout<<x<<" ";
    //     cout<<'\n';
    // }
    // cout<<ans.first<<" "<<ans.second<<'\n';
    for(int i=1;i<=n;i++){
        ans = dfs(i);
        if(ans.first)break;
    }
    if(ans.first == 0){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int c = ans.second;
    v.push_back(ans.second);
    while(c != ans.first){
        c = parent[c];
        v.push_back(c);
    }
    reverse(v.begin(),v.end());
    v.push_back(ans.first);
    // cout<<"YES\n";
    cout<<(int)v.size()<<'\n';
    for (auto x:v)cout<<x<<" ";
    
    return 0;
    }