#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll n,k;
const ll M = 100000007;
ll dp[51][1001];
ll a[51];
ll c[51];
ll way(ll i, ll rem){
    if(rem == 0)return 1;
    if(i>=n)return 0;
    if(dp[i][rem] != -1)return dp[i][rem] % M;
    
    ll ways = 0;
    for(ll j=0;j<=c[i];j++){
        if(j*a[i] > rem)break;
        ways =  (ways + way(i+1 , rem - j*a[i])) % M;
    }
    return dp[i][rem] = ways % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt; 
    int tt = 1;
    cin>>t;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        cin>>n>>k;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++)dp[i][j] = -1;
        }
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>c[i];
        cout<<way(0,k) % M;
        if(t)cout<<'\n';
        
    }
    return 0;
    }