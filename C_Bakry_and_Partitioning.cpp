#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e5+5;
vector<ll>g[N];
ll x[N];
ll val[N+1];
ll par[N+1];
bool vis[N];
void dfs(ll v){
    x[v]=val[v];
    vis[v]=true;
    for(auto child : g[v]){
        if(vis[child])continue;
        par[child]=v;
        dfs(child);
        x[v]=x[child]^x[v];
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        b=0;
        for(int i=1;i<=n;i++){
            cin>>val[i];
            b=b^val[i];
        }
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        
        
        if(k==2){
            if(b==0)cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        par[1]=-1;
        fill(vis,vis+1+n,false);
        for(int i=1;i<=n;i++)x[i]=0;
        dfs(1);
        int yes=0;
        for(int i=1;i<=n;i++){
            cout<<x[i]<<" ";
        }
        
    }
    return 0;
    }