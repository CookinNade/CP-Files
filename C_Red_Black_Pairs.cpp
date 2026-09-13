#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5;
string a,b;
ll dp[N+1];
ll n;
ll dpp(ll i){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    ll ans=1e13;
    if(a[i]==b[i]){
        ans=dpp(i+1);
    }
    else ans = 1+dpp(i+1);
    if(i<=n-2){
        ll x=0;
        if(a[i]!=a[i+1])x++;
        if(b[i]!=b[i+1])x++;
        ans=min(dpp(i+2)+x,ans);
    }
    return dp[i]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        cin>>a>>b;
        for(int i=0;i<n;i++)dp[i]=-1;
        cout<<dpp(0)<<endl;;
        
    }
    return 0;
    }