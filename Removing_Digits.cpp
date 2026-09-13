#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

const ll N=1e6;
ll dp[N+5];
ll rd(ll left){
    if(left==0)return 0;
    if(dp[left]!=-1)return dp[left];
    ll ans =1e17;
    string s = to_string(left);
    for(auto x : s){
        if(x=='0')continue;
        ans = min(ans,rd(left-x+'0')+1);
    }
    return dp[left]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rd(n)<<endl;
    // string s = to_string(n);
    // cout<<s<<endl;
    // cout<<s[0]-'0'<<endl;
    return 0;
    }