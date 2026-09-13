#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e4;

ll dp[N+1];
ll arr[N];
ll lis(int n){
    ll ans=1;
    if(dp[n]!=-1)return dp[n];
    for(int i=0;i<n;i++){
        if(arr[i]<arr[n])ans = max(ans, lis(i)+1);
    }
    return dp[n]=ans;
}
ll fib(ll n){
    if(n==1 or n==2 or dp[n]!=-1) return dp[n];
    else return dp[n]=fib(n-1)+fib(n-2);
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    fill(dp, dp+n+1,-1);
    cnt=-1;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        cnt=max(cnt,lis(i));
    }
    cout<<cnt<<endl;
    return 0;
    }