#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll arr[101];
const ll N=1e6;
const ll M = 1e9+7;
ll dp[N+5];
ll mc(ll left, ll n){
    if(left==0)return 0;
    if(left<0)return 1e15;
    if(dp[left]!=-1)return dp[left];
    ll ans=1e15;
    for(int i=n-1;i>=0;i--){
        ans = min(ans,mc(left-arr[i],n)+1ll);
    }
    return dp[left]=ans;
}

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];
    ll ans = mc(k,n);
    if(ans==1e15)cout<<-1<<endl;
    else cout<<ans<<endl;    
    return 0;
    }