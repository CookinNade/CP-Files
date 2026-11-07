#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = (1ll<<21) + 100;
ll dp[N];
bool g[21][21];
int n;
const ll M = 1e9+7;
ll f(ll mask){
    if(__builtin_popcountll(mask) == n)return 1;
    if(dp[mask]!=-1)return dp[mask] % M;
    int i = __builtin_popcountll(mask);
    ll ans = 0;
    for(int j=0;j<n;j++){
        if(g[i][j] and !(mask & (1ll<<j))) ans = (ans + f(mask + (1ll<<j))) % M;
    }
    return dp[mask] = ans % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int a;
        cin>>a;
        if(a)g[i][j] = 1;
        else g[i][j] = 0;
    }
    cout<<f(0);
    return 0;
    }