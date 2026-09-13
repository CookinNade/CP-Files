#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll dp[3][N];
ll h1[N];
ll h2[N];
ll sz;
ll bball(ll n,ll last){
    
    if(n>sz)return 0;
    if(dp[last][n]!=-1)return dp[last][n];
    ll ans=0;
    if(last!=0) {
        ans= max(ans,bball(n+1,0)+h1[n]);
        ans= max(ans,bball(n+2,2)+h1[n]);
    }
    if(last!=1) {
        ans= max(ans,bball(n+1,1)+h2[n]);
        ans= max(ans,bball(n+2,2)+h2[n]);
    }
    return dp[last][n]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>sz;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=sz;i++)cin>>h1[i];
    for(int i=1;i<=sz;i++)cin>>h2[i];
    cout<<bball(1,2)<<endl;
    return 0;
    }