#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5 +10;
ll dp[N];
ll arr[N];
ll bl(ll n, ll j){
    if(j==n)return 0;
    if(j>n)return 1e12;
    if(dp[j]!=-1)return dp[j];
    ll ans =1e13;
    ans = min(ans,bl(n,j+arr[j]+1));
    ans = min(ans,bl(n,j+1)+1ll);
    return dp[j]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<bl(n,0)<<endl;
    }
    return 0;
    }