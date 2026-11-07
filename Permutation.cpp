#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
int n;
string s;
ll dp[3001][3001];
ll f(int i, int j){
    if(i == n) return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    ll way = 0;
    if(i==0){
        for(int k=1;k<=n;k++){
            way = (way + f(1,n-k)) % M;
        }
        return dp[i][j] = way % M;
    }

    if(s[i-1] == '<' and j){
        way = (way + f(i+1,j-1)) % M;
        way = (way + f(i,j-1)) % M;
    }

    ll baki = n-i;
    if(s[i-1] == '>'){
        if(j<baki) way = (way + f(i+1,j)) % M;
        if (j+1<baki) way = way + f(i,j+1);
    }
    return dp[i][j] = way % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin>>n>>s;
    cout<<f(0,0) % M;
    return 0;
    }