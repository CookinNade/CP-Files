#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 101;
ll W;
ll w[N];
ll v[N];
const ll V = 1e5+2;
const ll M = 1e11;
ll dp[N][V];
int n;
ll knap(int i, ll rem){
    if(i == n){
        if(rem == 0)return 0;
        else return M;
    }
    if(dp[i][rem]!=-1)return dp[i][rem];
    ll ans = M;
    if(v[i] <= rem)
    ans = min(ans, w[i] + knap(i+1, rem - v[i]));
    ans = min(ans, knap(i+1, rem));
    return dp[i][rem] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>W;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)cin>>w[i]>>v[i];
    ll val = accumulate(v,v+n,0ll);
    for(;val>=1;val--){
        if((knap(0,val)) <= W)break;
    }
    cout<<val;
    return 0;
    }