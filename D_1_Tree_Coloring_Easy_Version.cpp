#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
vector<int> g[N];
// ll h[N];
ll d[N];
bool vis[N];
void dfs(ll child,ll par){

    vis[child]=true;
    for(auto v:g[child]){
        if(vis[v])continue;
        // cout<<child<<" "<<v<<endl;
        d[v]=d[child]+1;
        dfs(v,child);
        // h[child]=max(h[child],h[v]+1);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        for(int i=1;i<=n;i++)vis[i]=false;
        dfs(1,0);
        
        map<int,int>mp;
        for(int i=1;i<=n;i++)mp[d[i]]++;
        int ans=0;
        for(int i=1;i<=n;i++){
            // if(i==10)cout<<g[i].size()-1<<" "<<mp[d[i]+1]<<endl;
            if(mp[d[i]+1]==g[i].size()-1 and i!=1)ans=max(ans,mp[d[i]+1]+1);
            if(mp[d[i]+1]==g[i].size() and i==1)ans=max(ans,mp[d[i]+1]+1);
            else ans=max(ans,mp[d[i]+1]);
        }
        
        cout<<ans<<endl;
        // for(int i=1;i<=n;i++)cout<<d[i]<<endl;
        for(int i=1;i<=n;i++){
            d[i]=0;
            g[i].clear();
        }
        
    }
    return 0;
    }