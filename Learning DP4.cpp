#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e4;

int dp[310][N+5];

int cc(ll ind, ll amount,vector<int>& coins){
    if(amount==0)return 1;
    if(ind<0)return 0;

    int ways=0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    for(int value=0;value<=amount;value=coins[ind]+value){
        
        ways = ways + cc(ind-1,amount-value,coins);
    }
    return dp[ind][amount]=ways;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    vector<int>coins;
    coins.push_back(1);coins.push_back(2);coins.push_back(5);
    memset(dp, -1, sizeof(dp)); 
    cnt=cc(coins.size()-1,n,coins);
    cout<<cnt<<endl;
    
    
    return 0;
    }