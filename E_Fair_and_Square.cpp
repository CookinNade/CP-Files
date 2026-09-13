#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+1;
vector<ll>g[N];
ll sz[N];
ll wt[N];
ll par[N];
bool vis[N];
ll h[N];
void p(int v){
    vis[v] = true;
    for(auto c:g[v]){
        if(vis[c])continue;
        par[c] = v;
        h[c] = 1 + h[v];
        p(c);
    }
}
void ad(int v){
    sz[par[v]] = sz[par[v]] + sz[v] + 1;
    // cout<<v<<" "<<sz[v]<<endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>wt[i];
        }
        vector<pair<int,int>>v;
        vector<ll>ans;
        for(int i=0;i<n-1;i++){
            ll a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        p(1);
        for(int i=2;i<=n;i++) v.push_back({h[i] , i});
        sort(v.rbegin(), v.rend());
        for(int i=0;i<v.size();i++){
            ad(v[i].second);
        }
        for(int i=1;i<=n;i++){
            int j = round(sqrt(wt[i]));
            if(j*j == wt[i]){
                ans.push_back(sz[i]);
            }
        }
        cnt = 0;
        for(int i=0;i<ans.size();i++){
            cnt = cnt + (n-1)*(n-2) - (ll)ans.size() * ans[i];
            cout<<i<<" "<<(n-1)*(n-2) - (ll)ans.size() * ans[i]<<" "<<cnt<<endl;
        }
        cout<<max(0ll,cnt)<<endl;
        for(int i=1;i<=n;i++){
            h[i] = 0;
            vis[i] = false;
            sz[i] = 0;
            g[i].clear();
        }
    }
    return 0;
}