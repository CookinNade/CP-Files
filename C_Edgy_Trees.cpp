#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e5+3;
vector<pair<int,int>>g[N];
bool vis[N];
ll dfs(int v){
    vis[v]=true;
    ll ans=1;
    for(auto f:g[v]){
        int child=f.first;
        int allow=f.second;
        if(allow or vis[child])continue;
        ans=ans+dfs(child);
    }
    return ans;
}
const ll M=1e9+7;
ll binexp(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)res=(res*a)%M;
        b=b>>1;
        a=(a*a)%M;
    }
    return res;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,a,b,k,x; 
    cin>>n>>k;
    fill(vis,vis+n+1,false);
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>x;
        g[a].push_back({b,x});
        g[b].push_back({a,x});     
    }
    vector<ll>v;
    // v.push_back(-1111);
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        else v.push_back(dfs(i));
    }
    ll tot=binexp(n,k);
    ll ans=0;
    for(int i=0;i<v.size();i++){
        ans=(ans+binexp(v[i],k))%M;
    }
    cout<<(tot-ans+M)%M<<endl;
    return 0;
    }