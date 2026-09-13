#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll dp[N];
ll arr[N];
ll n;
map<ll,vector<ll>>mp;
ll len(ll i){
    if(i>=n)return 0;
    if(i==n-1)return 1;
    if(dp[i]!=-1)return dp[i];
    ll ans=0;
    if(mp[arr[i]+1].empty())return dp[i]=1;
    auto it = upper_bound(mp[arr[i]+1].begin(),mp[arr[i]+1].end(),i);
    if(it==mp[arr[i]+1].end())return dp[i]=1;
    int j=it-mp[arr[i]+1].begin();
    // cout<<j<<endl;
    for(;j<mp[arr[i]+1].size();j++){
        ans=max(ans,len(mp[arr[i]+1][j])+1);
    }
    return dp[i]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]].push_back(i);
    }
    ll ans=-1;
    for(int i=0;i<n;i++){
        if(dp[i]==-1)ans=max(ans,len(i));
    }
    cout<<ans<<endl;
    return 0;
    }