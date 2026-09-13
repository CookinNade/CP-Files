#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e3+5;

ll dp[N];
ll rod(ll len, vector<ll> &price){
    
    if(len==0)return 0;
    if(dp[len]!=-1)return dp[len];
    ll ans=0;
    for(int i=1;i<=price.size();i++){
        if(len-i>=0)
        ans=max(ans,rod(len-i,price)+price[i-1]);
    }
    // cout<<"hello"<<endl;
    return dp[len]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,k,x; 
    cin>>n;
    vector<ll>price;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>a;
        price.push_back(a);
    }
    cout<<rod(n,price)<<endl;
    return 0;
    }