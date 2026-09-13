#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e4;

int dp[N+5];

int cc(ll amount,vector<int>& coins){
    int ans=INT_MAX;

    if(amount==0)return 0;
    if(dp[amount]!=-1) return dp[amount];
    for( auto coin : coins){
        if(amount-coin>=0) ans=min(ans,cc(amount-coin,coins)+1);
    }
    return dp[amount]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    vector<int>coins;
    coins.push_back(1);coins.push_back(2);coins.push_back(5);
    fill(dp, dp+n+1,-1);
    cnt=cc(n,coins);
    if(cnt==INT_MAX)cout<<-1<<endl;
    else cout<<cnt<<endl;

    
    
    return 0;
    }