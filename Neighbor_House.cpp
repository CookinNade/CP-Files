#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll n;
const int N = 21;
ll dp[N][3];
ll g[N][3];
ll house(int i, int k){
    if(i>=n)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    ll ans = 1e12;
    if(i==0 or k!=0)ans = min(ans, g[i][0] + house(i+1,0));
    if(i==0 or k!=1)ans = min(ans, g[i][1] + house(i+1,1)); 
    if(i==0 or k!=2)ans = min(ans, g[i][2] + house(i+1,2));
    return dp[i][k] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,cnt,k; 
    cin>>t;
    int tt = 1;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)cin>>g[i][0]>>g[i][1]>>g[i][2];
        cout<<house(0,0)<<'\n';
    }
    return 0;
    }