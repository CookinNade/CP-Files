#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M=1e9+7;
const ll N=3e5+5;
ll vis[N+1];
ll par[N+1]; pair<ll,ll>child[N+1];
ll ans[N+1];
// bool vis[N];
void laga(ll p){
    if(vis[p]<2)return;
    ans[p]=(ans[child[p].first]+ans[child[p].second])%M;
    ans[p]=(ans[p]+4)%M;
    vis[par[p]]++;
    laga(par[p]);
}
void dfs(ll v){
    ans[v]=(ans[v]+1)%M;
    ans[v]=(ans[par[v]]+ans[v])%M;
    if (child[v].first==0){
        return;
    }
    dfs(child[v].first);
    dfs(child[v].second);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        fill(vis,vis+n+1,0);
        fill(ans,ans+n+1,0);
        
        vector<ll>v;
        for(int i=1;i<=n;i++){
            cin>>a>>b;
            par[a]=i; par[b]=i;
            child[i]={a,b};
            if(a==0)v.push_back(i);
        }
        for(int i=0;i<v.size();i++){
            ans[v[i]]=0;
            vis[v[i]]=2;
            vis[par[v[i]]]++;
            laga(par[v[i]]);
        }
        // for(int i=1;i<=n;i++)cout<<i<<" "<<ans[i]<<" \n";
        ans[0]=0;
        dfs(1);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
        
    }
    return 0;
    }