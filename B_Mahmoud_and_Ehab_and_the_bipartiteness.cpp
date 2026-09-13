#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e5+5;
bool vis[N];
vector<ll>g[N];
set<ll>a;
set<ll>b;
void dfs(ll v, ll m){
    vis[v]=true;
    if(m==1)a.insert(v);
    else b.insert(v);
    for(auto child:g[v]){
        if(vis[child])continue;
        if(m==1)dfs(child,0);
        else dfs(child,1);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,c,d,cnt,r,l,k,x; 
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>c>>d;
        g[c].push_back(d);
        g[d].push_back(c);
    }
    dfs(1,0);
    // for(auto it=a.begin();it!=a.end();++it){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    //     for(auto it=b.begin();it!=b.end();++it){
    //     cout<<*it<<" ";
    // }
    cout<<endl;
    ll ans=0;
    ll aa=a.size();
    ll bb=b.size();
    for(int i=1;i<=n;i++){
        if(a.find(i)!=a.end()){
            ans=ans+bb-g[i].size();
        }
        else ans=ans+aa-g[i].size();
        // cout<<ans<<" "<<g[i].size()<<endl;
    }
    cout<<ans/2<<endl;

    return 0;
    }