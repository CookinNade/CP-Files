#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 10002;
const ll M = 100000007;
ll n,k;
ll coins[101];
ll dp[101][N];
ll way(int i, ll rem){
    if(rem == 0)return 1;
    if(i >= n)return 0;
    if(dp[i][rem] != -1)return dp[i][rem];
    // cout<<"dhukse "<<i<<" "<<rem<<endl;
    ll ways = 0;
    if(rem - coins[i] >=0)
    ways = (ways + way(i, rem - coins[i])) % M;
    ways = (ways + way(i+1, rem)) % M;
    return dp[i][rem] = ways % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin>>t;
    int tt = 1;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        cin>>n>>k;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++)dp[i][j] = -1;
        }
        for(int i=0;i<n;i++)cin>>coins[i];
        cout<<way(0,k) % M<<'\n';
    }
    return 0;
    }