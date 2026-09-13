#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

const ll N=250*501+1;
ll dp[501][N];
const ll M = 1e9+7;
ll ts(ll left,ll n){
    if(left==0)return 1ll;
    if(left<0)return 0;
    if(n<=0) return 0;
    if(dp[n][left]!=-1ll)return dp[n][left];
    ll ans=0;
    ans = (ans+ts(left,n-1ll))%M;
    if(left-n>=0ll)
    ans = (ans+ts(left-n,n-1ll))%M;
    return dp[n][left]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    memset(dp,-1ll,sizeof(dp));
    ll sum = n*(n+1)/2;
    // cout<<sum/2<<endl;
    if(sum%2)cout<<0<<endl;
    else {
        ll val = ts(sum/2,n);
        ll inv2 = (M+1)/2;
        ll ans = (val * inv2) % M;
        cout<<ans<<endl;
    }
    return 0;
    }