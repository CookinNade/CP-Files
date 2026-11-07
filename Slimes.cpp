#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 401;
ll n;
ll a[N];
ll pref[N];
ll dp[N][N];
ll inv(int i, int j){
    if(i == j) return 0;
    if(i+1 == j)return (a[i] + a[j]);
    if(dp[i][j]!=-1)return dp[i][j];
    ll ans = 1e15;
    for(int k = i; k<j; k++){
        if(i==0)ans = min(inv(i,k) + inv(k+1,j) + pref[j], ans);
        else ans = min(inv(i,k) + inv(k+1,j) + pref[j] - pref[i-1], ans);
        // cout<<i<<" "<<k<<" "<<k+1<<" "<<j<<endl;
        // cout<<inv(i,k)<<" "<<inv(k+1,j)<<endl;
    }

    return dp[i][j] = ans;

}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>a[i];
    pref[0] = a[0];
    for(int i=1;i<n;i++)pref[i] = pref[i-1] + a[i];
    cout<<inv(0,n-1);
    return 0;
    }