#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
vector<pair<int,int>>g[N];
pair<ll,ll> h[N];
void dfs(ll v){
    if(v==1)h[v].first=1;
    if(v==1)h[v].second=0;
    for(auto child:g[v]){
        ll real=child.first;
        ll serial=child.second;
        if(h[real].first)continue;
        h[real].second=serial;
        if(serial>h[v].second)h[real].first=h[v].first;
        else h[real].first=h[v].first+1;
        dfs(real);
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        ll n,a,b,cnt,c,d;
        cin>>n;
        for(int i=1;i<=n;i++)h[i].first=0;
        for(int i=1;i<=n;i++)h[i].second=0;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            g[a].push_back({b,i+1});
            g[b].push_back({a,i+1});
        }
        ll ans=0;
        dfs(1);
        for(int i=1;i<=n;i++)ans=max(ans,h[i].first);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)g[i].clear();
        // cout<<g[0].size()<<endl;
    }
}