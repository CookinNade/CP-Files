#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1002;
ll n,m;
ll g[N][N];

ll dp1[N][N];
ll dp2[N][N];
ll dp3[N][N];
ll dp4[N][N];
ll dpz1(ll i , ll j){
    if(dp1[i][j]!=-1)return dp1[i][j];
    ll ans=g[i][j];
    ll mx=0;
    if(i<n) mx=dpz1(i+1,j);
    if(j<m) mx=max(dpz1(i,j+1),mx);
    ans= ans+mx;
    return dp1[i][j]=ans;
}
ll dpz2(ll i , ll j){
    if(dp2[i][j]!=-1)return dp2[i][j];
    ll ans =g[i][j];
    ll mx=0;
    if(i>1) mx=dpz2(i-1,j);
    if(j<m) mx=max(mx,dpz2(i,j+1));
    ans= ans+mx;
    return dp2[i][j]=ans;
}
ll dpz3(ll i , ll j){
    if(dp3[i][j]!=-1)return dp3[i][j];
    ll ans =g[i][j];
    ll mx=0;
    if(i<n) mx=dpz3(i+1,j);
    if(j>1) mx=max(mx,dpz3(i,j-1));
    ans= ans+mx;
    return dp3[i][j]=ans;
}
ll dpz4(ll i , ll j){
    if(dp4[i][j]!=-1)return dp4[i][j];
    ll ans =g[i][j];
    ll mx=0;
    if(i>1) mx=dpz4(i-1,j);
    if(j>1) mx=max(mx,dpz4(i,j-1));
    ans= ans+mx;
    return dp4[i][j]=ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>g[i][j];
    }
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    memset(dp3,-1,sizeof(dp3));
    memset(dp4,-1,sizeof(dp4));
    
    dpz1(1,1);
    dpz2(n,1);
    dpz3(1,m);
    dpz4(n,m);
    ll ans=0;
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            ll real=dp4[i-1][j]+dp1[i+1][j]+dp3[i][j-1]+dp2[i][j+1];
            real = max(real,dp4[i][j-1]+dp1[i][j+1]+dp3[i+1][j]+dp2[i-1][j]);
            ans=max(ans,real);
        }
    }
    cout<<ans<<endl;
    return 0;
    }