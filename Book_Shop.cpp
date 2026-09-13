#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e5+1;
int price[1001];
int page[1001];
int dp[1001][N];
int k;
int dpz(int n, int val){
    if(n<0)return 0ll;
    if(dp[n][val]!=-1)return dp[n][val];
    int ans=0;
    ans=dpz(n-1,val);
    if(val+price[n]<=k)
    ans = max(ans,dpz(n-1,price[n]+val)+page[n]);
    return dp[n][val]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,x; 
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n;i++)cin>>page[i];
    cout<<dpz(n-1,0)<<endl;
    return 0;
    }