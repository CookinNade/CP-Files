#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N =1e5+5;
ll dp [4][N];
ll a[N]; ll b[N]; ll c[N];
ll vac(ll n,ll last){
    if(n<0)return 0;
    if(dp[last][n]!=-1) return dp[last][n];
    ll ans=-2;
    // cout<<last<<" "<<ans<<endl;
    if(last!=0) ans=max(ans,a[n]+vac(n-1,0));
    if(last!=1) ans=max(ans,b[n]+vac(n-1,1));
    if(last!=2) ans=max(ans,c[n]+vac(n-1,2));
    return dp[last][n]=ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,d,cnt,r,l,k,x; 
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
    cout<<vac(n-1,3)<<endl;
    return 0;
    }