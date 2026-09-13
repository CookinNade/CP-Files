#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=4005;
bool vis[N];
vector<ll>g[N];
pair<ll,ll>cnt[N];
string s;
void dfs(ll v){
    vis[v]=true;
    for(auto child:g[v]){
        if(vis[child]) continue;
        dfs(child);
        cnt[v].first=cnt[child].first+cnt[v].first;
        cnt[v].second=cnt[child].second+cnt[v].second;
    }
    if(s[v-1]=='W')cnt[v].first++;
    else cnt[v].second++;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,r,l,k,x; 
    cin>>t;
    while (t--){
        cin>>n;
        fill(vis,vis+n+1,false);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)cnt[i]={0,0};
        for(int i=2;i<=n;i++){
            cin>>a;
            g[i].push_back(a);
            g[a].push_back(i);
        }
        cin>>s;
        dfs(1);
        ll ans=0;
        for(int i=1;i<=n;i++)if(cnt[i].first==cnt[i].second)ans++;
        cout<<ans<<endl;
    }
    return 0;
    }