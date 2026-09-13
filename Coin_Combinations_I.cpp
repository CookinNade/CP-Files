#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll arr[101];
const ll N=1e6;
const ll M = 1e9+7;
int n;
ll dp[N+5];
ll hobe(int baki){
    if(baki == 0)return 1ll;
    if(dp[baki] != -1)return dp[baki];
    ll ways = 0;
    for(int i=0;i<n;i++){
        if(baki - arr[i] >= 0) ways = (ways + hobe(baki - arr[i])) % M;
    }
    return dp[baki] = ways;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>x;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<hobe(x);
    return 0;
    }