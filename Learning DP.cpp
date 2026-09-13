#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e4;
ll dp[N+1];

ll fib(ll n){
    if(n==1 or n==2 or dp[n]!=-1) return dp[n];
    else return dp[n]=fib(n-1)+fib(n-2);
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    fill(dp+2,dp+N,-1ll);
    dp[1]=1; dp[2]=1;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
    }