#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll dp[N];
ll arr[N];
ll dpp(ll n, ll k){
    ll cost = LLONG_MAX;
    // cout<<n<<endl;
    if(n==1)return 0ll;
    if(n==2)return abs(arr[2]-arr[1]);
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=100;i++){
        cost=min(cost,dpp(n-i,k)+abs(arr[n]-arr[n-i]));
        if(n-i==1)break;
    }
    return dp[n]=cost;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,k;
    cin>>n>>k;
    fill(dp+1,dp+n+1,-1ll);
    for(int i=1;i<=n;i++) cin>>arr[i];
    cout<<dpp(n,k)<<endl;
    return 0;
    }