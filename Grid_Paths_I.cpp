#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1003;
char g[N][N];
ll dp[N][N];
const ll M = 1e9+7;
ll can(ll i, ll j, ll n){
    
    if(i==n-1 and j==n-1)return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ways = 0;
    if(i+1<n and g[i+1][j]!='*') ways = (ways+can(i+1,j,n))%M;
    if(j+1<n and g[i][j+1]!='*') ways = (ways+can(i,j+1,n))%M;
    return dp[i][j]=ways;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)cout<<g[i][j]<<" ";\
    //     cout<<endl;
    // }
    if(g[0][0]=='*')cout<<0<<endl;
    else cout<<can(0,0,n)%M<<endl;
    return 0;
    }