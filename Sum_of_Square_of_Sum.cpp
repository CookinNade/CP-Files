#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 998244353;
ll binpow(ll a, ll b){
    ll ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a)%M;
        }
        b = b>>1;
        a = (a*a)%M;
    }
    return ans;
}
ll fact(ll f){
    ll ans = 1;
    while(f>=1){
        ans = (ans*f)%M;
        f--;
    }
    return ans;
}
ll nCk(ll n, ll k){
    if(k<=0 or n<=0 or k>n)return 0;
    ll numero = fact(n);
    ll deno = (fact(n-k) * fact(k)) % M;
    deno = binpow(deno, M-2);
    return (numero*deno)%M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        ll a,b,c;
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum = (sum + arr[i]) % M;
        }
        b = (nCk(n,k) - nCk(n-1,k) + M) % M;
        c = (nCk(n-1,k-1) - nCk(n-2,k-1) + M) % M;
        ll res = 0;
        for(int i=0;i<n;i++){
            ll a = arr[i] % M;
            ll te = (b*a)%M;
            ll s = (sum - a + M) % M;
            te = (te + ((c*s) % M)) % M;
            te = (te * a) % M;
            res = (res+te) % M;
        }
        cout<<res;
    }
    return 0;
    }