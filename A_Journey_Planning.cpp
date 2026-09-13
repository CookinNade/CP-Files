#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N =2e5+5;
ll sz;
ll dp[N];
ll arr[N];

// ll beauty(ll n){
//     if(n>sz)return 0;
//     if(dp[n]!=-1)return dp[n];
    
//     ll ans=arr[n];
//     for(int i=n+1;i<=sz;i++){
//         if(i-n==arr[i]-arr[n]) ans= max(ans, beauty(i)+arr[n]);
//     }
//     return dp[n]=ans;
// }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x;
    memset(dp,-1,sizeof(dp));
    cin>>sz;
    map<ll,ll>mp;
    for(int i=1;i<=sz;i++){
        cin>>arr[i];
        mp[arr[i]-i]=arr[i]+mp[arr[i]-i];
    }
    ll ans=0;
    for(auto it = mp.begin();it!=mp.end();++it){
        ans=max(ans,(*it).second);
    }
    cout<<ans<<endl;    
    return 0;
    }