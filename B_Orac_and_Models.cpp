#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e5+4;
ll dp[N];
ll arr[N];
ll sz;
ll dpz(ll n){
    if(n>sz)return 0;
    if(dp[n]!=-1)return dp[n];
    ll ans=1;
    ll m = n;
    for(ll i = 2*n;i<=sz;i=i+m){
        if(arr[i]>arr[n]){
            ll real = dpz(i)+1;
            ans = max(ans,real);
            // cout<<real<<" "<<n<<" "<<i<<" "<<ans<<endl;
        }
    }
    return dp[n]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        memset(dp,-1,sizeof(dp));
        cin>>sz;
        for(int i=1;i<=sz;i++)cin>>arr[i];
        ll ans = 0;
        for(int i=1;i<=sz;i++){
            ll real = dpz(i);
            ans=max(ans,real);
            // cout<<real<<" "<<i<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
    }