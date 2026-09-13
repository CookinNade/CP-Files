#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll a,b,c;
const ll N = 4e3+4;
ll dp[N];
ll dps(ll left){
    if(left==0)return 0;
    if(dp[left]!=-1)return dp[left];
    ll ans=0;
    if(left>=a) ans = max(ans,dps(left-a)+1);
    // cout<<left<<" "<<ans<<endl;
    if(left>=b) ans = max(ans,dps(left-b)+1);
    // cout<<left<<" "<<ans<<endl;
    if(left>=c) ans = max(ans,dps(left-c)+1);
    // cout<<left<<" "<<ans<<endl;
    if(ans==0)return dp[left]=-1012;
    return dp[left]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,d,cnt,r,l,k,x; 
    cin>>n>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    cout<<dps(n)<<endl;
    return 0;
    }