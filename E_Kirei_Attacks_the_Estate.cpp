#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5+4;
ll ans[N];
ll val[N];
vector<ll>g[N];
ll p[N];
bool vis[N];
void dfs(int v){
    vis[v]=true;
    for(auto c:g[v]){
        if(vis[c] or c==1)continue;
        ans[c]=max(ans[p[v]]-val[v]+val[c],val[c]);
        dfs(c);
    }
}
void par(int v){
    for(auto c:g[v]){
        if(v==1){
            p[c]=v;
            par(c);
            continue;
        }
        if(p[c] or c==1)continue;
        p[c]=v;
        par(c);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>val[i];
            ans[i]=0;
            g[i].clear();
            vis[i]=false;
            p[i]=0;
        }
        ans[1]=val[1];
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            g[a].push_back(b); g[b].push_back(a);
        }
        par(1);
        for(auto c:g[1]){
            ans[c]=val[c];
            dfs(c);
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
    }