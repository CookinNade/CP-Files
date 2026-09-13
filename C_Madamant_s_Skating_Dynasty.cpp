#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 998244353;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n,greater<int>());
        for(int i=0;i<n;i++) arr[i] %= M;
        ll sum = 0;
        ll ans = 0;
        ll fact[n+4];
        ll f = 1;
        fact[0] = 1;
        for(ll i = 1;i<=n;i++){
            f = (f * i) % M;
            fact[i] = f % M;
        }
        
        for(int i=0;i<n;i++){
            if(i!=0){
                ans = (ans * i) % M;
                ll kombe = (arr[i] * fact[i]) % M;
                ll barbe = (sum * fact[i-1]) % M;
                ans = (ans  + barbe) % M;
                ans = (ans + M - kombe) % M;
            }
            sum = (sum + arr[i]) % M;
            // cout<<sum<<" "<<arr[i]<<" "<<i<<" "<<ans<<endl;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }