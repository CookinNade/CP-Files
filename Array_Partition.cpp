#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
ll binpow(ll a, ll b){
    ll ans = 1;
    a %= M;
    while(b>0){
        if(b&1) ans = (ans * a) % M;
        a = (a*a) % M;
        b >>= 1;
    }
    return ans;
}
ll modinv(ll a){
    return binpow(a, M-2);
}
const ll N = 1e5 + 2;
const ll S = 1e6 + 2;
ll fact[N];
int parent[S];
int sz[S];
int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
void Union(int a , int b){
    if(sz[a] < sz[b]) swap(b,a);
    sz[a] += sz[b];
    parent[b] = a;
    return;
}
bool use[S];
int spf[S];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    ll f = 1;
    fill(spf,spf+S, 1e8);
    fact[0] = 1;
    fact[1] = 1;
    spf[0] = 1;
    

    for(int i=2;i<N;i++){
        f = (i * f) % M; 
        fact[i] = f;
    }
    for(int i=2;i<S;i++){
        if(spf[i] == 1e8){
            for(int j = i ; j<S; j+= i){
                spf[j] = min(i,spf[j]);
            }
        }
    }
    
    while (t--){
        cin>>n;
        ll arr[n];
        spf[1] = 0;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<S;i++){
            parent[i] = i;
            sz[i] = 1;
            use[i] = false;
        }
        for(int i=0;i<n;i++){
            int a = arr[i];
            int hi = spf[a];
            hi = find(hi);
            use[hi] = true;
            if(a == 1){
                spf[1]++;
                continue;
            }
            while(a != 1){
                int d = spf[a];
                use[d] = true;
                while(a % d == 0){
                    a /= d;
                }
                d = find(d);
                if(d != hi)Union(d,hi);
            }
        }
        ll cnt = spf[1];
        for(int i=2;i<S;i++){
            if(use[i] and i == parent[i])cnt++;
        }
        if(cnt <= 1){
            cout<<0<<'\n';
            continue;
        } 
        ll ans = 0;
        // cout<<cnt<<" from "<<t<<" \n";
        for(ll i = 1; i<=cnt-1; i++){
            ll barbe = 1;
            barbe = (barbe * fact[cnt]) % M;
            barbe = (barbe * modinv(fact[i])) % M;
            barbe = (barbe * modinv(fact[cnt-i])) % M;
            ans = (ans + barbe) % M; 
        }
        cout<<ans<<'\n';
    }
    return 0;
    }