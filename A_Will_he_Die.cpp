#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 3e5+2;
const ll M = 1e9 + 7;
ll fact[N];
ll binpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>=1;
    }
    return ans;
}
ll modinv(ll a){
    return binpow(a, M-2);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k;
    fact[1] = 1;
    fact[0] = 1;
    ll f = 1;
    for(ll i = 2;i<N;i++){
        fact[i] = (fact[i-1] * i) % M;
    }
    cin>>t;
    while (t--){
        ll m;
        cin>>n>>m;
        n = abs(n);
        if(abs(n) > m){
            cout<<0<<'\n';
            continue;
        }
        int rem = m - n;
        if(rem % 2){
            cout<<0<<'\n';
            continue;
        }
        n = n + rem/2;
        
        // for(int i=0;i<m;i++){
            // niche = (niche * 2) % M;
        // } 
        ll niche = binpow(2,m);
        ll upore = fact[m];
        niche = (fact[n] * niche)  % M;
        niche = (fact[m-n] * niche) % M;
        niche = modinv(niche);
        cout<< (upore * niche) % M<<'\n';
        
    }
return 0;
}