#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+2;
vector<int>g[N];
bool vis[N];
int path[N];
int dfs(int v){
    vis[v] = true;
    int ans = 0;
    // cout<<v<<" "<<d<<endl;
    for(auto c:g[v]){
        if(vis[c] and path[v]!=c) {
            path[c] = v;
            // cout<<c<<" "<<v<<endl;
            return c;
        }
        if(vis[c])continue;
        path[c] = v;
        ans = max(ans,dfs(c));
        if(ans)return ans;
    }
    return ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a==b)continue;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        ans = dfs(i);
        if(ans)break;
    }
    if(ans == 0){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int>v;
    int a = path[ans];
    // cout<<a<<" sdf "<<endl;
    v.push_back(ans); 
    while(true){
        if(a==ans)break;
        v.push_back(a);
        a = path[a];
    }
    v.push_back(ans); 
    cout<<(int)v.size()<<'\n';
    for(auto x:v)cout<<x<<" ";
    return 0;
    }