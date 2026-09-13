#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

const int N = 1e5+1;
vector<int>g[N];
int c[N+1];
bool dfs(int v, int k){
    c[v] = k;
    int yes = true;
    for(auto x : g[v]){
        if(c[x] and k!=c[x])continue;
        if(c[x] and k == c[x]) return false;
        if(k==2) yes &= dfs(x,1);
        else yes &= dfs(x,2);
    }
    return yes;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        int m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        bool hobe = true;
        for(int i=1;i<=n;i++){
            if(c[i])continue;
            bool yes = dfs(i,1);
            if(!yes){
                hobe = false;
                break;
            }
        }
        if(!hobe) cout<<"IMPOSSIBLE";
        else for(int i = 1;i<=n;i++)cout<<c[i]<<" ";
        
    }
    return 0;
    }