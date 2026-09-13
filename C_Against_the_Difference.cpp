#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5+1;
vector<ll>g[N+1];
ll dp[N];
ll arr[N];
ll n;
ll mar(ll i){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    ll a = arr[i];
    auto it = lower_bound(g[a].begin(),g[a].end(),i);
    ll ans=mar(i+1);
    int j= it-g[a].begin();
    int sz=g[a].size();
    if(j+a-1<sz)ans=max(ans,mar(g[a][j+a-1]+1)+a);
    return dp[i]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        for(int i=0;i<n+1;i++)dp[i]=-1;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=0;i<n;i++){
            cin>>arr[i];
            g[arr[i]].push_back(i);
        }
        cout<<mar(0)<<endl;
    }
    return 0;
    }