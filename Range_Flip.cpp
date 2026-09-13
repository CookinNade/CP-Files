#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+2;
ll a[N],b[N];
ll dp[N][11][2];
int n;
ll lagao(int i, int k, int con){
    if(i>=n)return 0;
    if(dp[i][k][con]!=-1)return dp[i][k][con];
    ll ans = 0;
    if(con){
        ans = max(ans, lagao(i+1, k, 1) + b[i]);
        ans = max(ans, lagao(i+1,k,0) + a[i]);
    }
    else{
        if(k>0)ans = max(ans, lagao(i+1,k-1,1) + b[i]);
        ans = max(ans, lagao(i+1,k,0) + a[i]);
    }
    return dp[i][k][con] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    cout<<lagao(0,k,0);
    return 0;
    }