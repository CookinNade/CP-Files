#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e5 + 1;
vector<int>g[N];
bool vis[N];
void dfs(int v){
    vis[v] = true;
    for(auto c : g[v]){
        if(vis[c])continue;
        dfs(c);
    }
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    // cin>>t;
    t = 1;

    while (t--){
        int n , m;
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int a , b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int>v;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                v.push_back(i);
                dfs(i);   
            }
        }
        cout<<(int)v.size() - 1<<'\n';
        for(int i=1;i<(int)v.size();i++){
            cout<<v[i-1]<<" "<<v[i]<<'\n';
        }
    }
    return 0;
    }