#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll INF = 1e17;
const ll N = 1e6 + 5;
const ll M = 1e9 + 7;
ll dp[N];
ll n;
ll d(ll sum){
    if(sum == n)return 1ll;
    if(dp[sum] != -1)return dp[sum];
    // cout<<sum<<endl;
    ll ways = 0;
    for(ll i = 1;i<=6;i++){
        if(sum + i <=n) ways = (ways + d(sum + i)) % M;
    }
    return dp[sum] = ways;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<d(0)<<endl;
    return 0;
    }