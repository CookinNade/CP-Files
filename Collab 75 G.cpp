#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;


ll g[501][501];
bool yes [501][501];
ll dp[501][501][11];
ll c,r,n;
ll path(int i, int j, int k){
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(j==c-1 and k==n){
        // cout<<i<<" "<<j<<" "<<k<<" this gives answer"<<endl;
        return dp[i][j][k]=g[i][j];
    }
    else if (j==c-1 and k!=n) {
        // cout<<i<<" "<<j<<" "<<k<<" this gives answer"<<endl;
        return dp[i][j][k]=1e11;
    }
    ll ways=1e11;
    if(i+1 != r and g[i+1][j+1]!=-1){
        if(!yes[i+1][j+1]) ways = min(ways , g[i][j] + path(i+1,j+1,k));
        else if(k<n) ways = min(ways , g[i][j] + path(i+1,j+1,k+1));
    }
    if(i != 0 and g[i-1][j+1]!=-1){
        if(!yes[i-1][j+1]) ways = min(ways , g[i][j] + path(i-1,j+1,k));
        else if(k<n) ways = min(ways , g[i][j] + path(i-1,j+1,k+1));
    }
    if(g[i][j+1]!=-1){
        if(!yes[i][j+1]) ways = min(ways , g[i][j] + path(i,j+1,k));
        else if(k<n) ways = min(ways , g[i][j] + path(i,j+1,k+1));
    }
    return dp[i][j][k]=ways;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,d,k,l,cnt;
    memset(dp,-1,sizeof(dp));
    cin>>r>>c>>n;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>g[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 or i==r-1 or j==c-1 or j==0){
                yes[i][j] = false;
                continue;
            }
            d = g[i][j];
            if(d > g[i][j-1] and g[i][j-1]!=-1 and d > g[i][j+1] and g[i][j+1]!=-1 and d<g[i+1][j] and g[i+1][j]!=-1 and d<g[i-1][j] and g[i-1][j]!=-1) yes[i][j] = true;
            else yes[i][j]=false;
        }
    }
    ll ans=1e10;
    for(int i=0;i<r;i++){
        if(g[i][0]==-1)continue;
        ans=min(ans,path(i,0,0));
    }
    if(ans>=1e9)cout<<"impossible";
    else cout<<ans<<endl;
    
    return 0;
    }