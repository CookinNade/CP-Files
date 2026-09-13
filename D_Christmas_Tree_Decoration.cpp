#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M= 998244353;
int mul(ll x, ll y) {
  return x * 1LL * y % M;
}
ll binpow(ll x, ll y) {
  ll z = 1;
  while (y > 0) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    ll fact[55];
    fact[0]=1;
    a=1;
    for(ll i=1;i<=54;i++){
        a=(a*i)%M;
        fact[i]=a;
    }
    while (t--){
        cin>>n;
        ll arr[n+1];
        vector<ll>v(n);
        d=0;
        cnt=0;
        for(int i=0;i<=n;i++)cin>>arr[i];
        for(int i=1;i<=n;i++)v[i-1]=arr[i];
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++){
            if(v[0]==v[i]){
                cnt++;
                continue;
            }
            d=d+(v[0]-v[i]-1);
        }
        if(arr[0]>=d+v[0]){
            cout<<fact[n]<<endl;
        }
        else if(arr[0]>=d and arr[0]<d+v[0]){
            
            b=arr[0]-d;
            x=n-cnt;
            if(cnt==n or b>=x){
                cout<<fact[n]<<endl;
                continue;
            }
            // cout<<b<<endl;
            // cout<<cnt<<endl;
            
            // cout<<n-cnt-b<<" "<<cnt+b<<endl;
            // cout<<ans<<endl;
            
            ll ans=1;
            ans=(fact[n-cnt-b]*fact[cnt+b])%M;
            if(b==0){
                cout<<ans<<endl;
                continue;
            }
            ans=(ans*(fact[x]))%M;
            ans=(ans*binpow(fact[b],M-2))%M;
            ans=(ans*binpow(fact[x-b],M-2))%M;
            // ans=(nCr(x,b)*ans)%M;
            cout<<ans<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
    }