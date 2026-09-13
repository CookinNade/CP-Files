#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=4e4;
ll dp[N+1][502];
const ll M = 1e9 + 7;
ll n;
vector<ll>v;
ll part(ll sum, ll k){
    // cout<<sum<<endl;
    if(sum==0)return 1;
    if(dp[sum][k]!=-1)return dp[sum][k];
    ll ans=0;
    if(sum-v[k]>=0)
    ans = (ans + part(sum-v[k],k))%M; 
    if(k+1<v.size())
    ans = (ans + part(sum,k+1))%M;
    // cout<<ans<<" "<<sum<<" "<<" "<<k<<endl;
    return dp[sum][k]=ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,m,a,b,d,cnt,r,l,k,x; 
    memset(dp,-1,sizeof(dp));
    cin>>t;
    string s;
    for(int i=1;i<=N;i++){
        s = to_string(i);
        string c=s;
        reverse(s.begin(),s.end());
        if(s==c)v.push_back(i);
    }
    ll kalo = part(N,0);
    while (t--){
        cin>>n;
        cout<<dp[n][0]<<endl;
    }
    return 0;
    }