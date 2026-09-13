#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n,x;
const ll N = 1e6+1;
const ll M = 1e9+7;
int coins[100];
int dp[N][100];
ll lagao(ll baki, ll i){
    if(baki == 0) return 1;
    if(i>=n) return 0;
    if(dp[baki][i] != -1) return dp[baki][i];
    ll ways = 0;
    ll coin = coins[i];
    for(int j=0;;j++){
        if(coin*j > baki)break; 
        ways = (ways + lagao(baki - coin*j, i+1)) % M; 
    }
    return dp[baki][i] = ways % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    // cin>>t;
    t = 1;
    while (t--){

        memset(dp,-1,sizeof(dp));        
        cin>>n>>x;
        for(int i=0;i<n;i++)cin>>coins[i];
        cout<<lagao(x,0);
    }
    return 0;
    }