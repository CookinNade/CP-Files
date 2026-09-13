#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e6 + 1;
// ll lpf[N];
ll hpf[N];
ll tot[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    for(ll i = 2;i<N;i++){
        if(!hpf[i]){
            hpf[i] = i;
            for(int j = 2*i;j<N;j = j + i){
                hpf[j] = i;
            }
        }
    }
    hpf[1] = 1;
    tot[1] = 0;
    for(ll a = 2;a<N;a++){
        ll ase = 1;
        ll b = a;
        while(b>1){
            ll cnt = 0;
            ll d = hpf[b];
            while(b%d == 0){
                cnt++;
                b /= d;
            }
            cnt *=2;
            ase *= (cnt+1);
        }
        tot[a] = (ase-1) / 2; 
    }
    for(int i = 2;i<N;i++){
        tot[i] += tot[i-1];
    }
    while (t--){
        cin>>n;
        cout<<tot[n]<<'\n';
    }
    return 0;
    }