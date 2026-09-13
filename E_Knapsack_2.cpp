#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 105;
ll dp[N][100005];
ll wt[N];
ll val[N];
ll knp(ll n, ll left){
    if(left==0)return 0;
    if(n<0 )return 1e15;
    if(dp[n][left]!=-1) return dp[n][left]; 
    ll ans = knp(n-1,left);
    if(left-val[n]>=0) ans = min(ans,knp(n-1,left-val[n])+wt[n]);
    return dp[n][left] =ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    ll t,n,m,a,b,w,d,cnt,r,l,k,x; 
    cin>>n>>w;
    for(int i=0;i<n;i++)cin>>wt[i]>>val[i];
    for(int i=1e5;i>=1;i--){
        cnt=knp(n-1,i);
        // cout<<cnt<<endl;
        if(cnt<=w){
            cout<<i<<endl;
            break;
        }
    }
    
    return 0;
    }