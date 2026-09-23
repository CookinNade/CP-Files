#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 3e5 + 2;
const ll INF = 1e13;
ll spf[N];
ll hpf[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    fill(spf,spf+N-10,INF);
    spf[1] = 1;
    hpf[1] = 1;
    spf[0] = 1;
    hpf[0] = 1;
    for(ll i = 2;i<N-10;i++){
        if(spf[i] == INF){
            for(ll j = i; j<N-10; j += i){
                spf[j] = min(i,spf[j]);
            }
        }
    }
    for(ll i = 2;i<N-10;i++){
        if(hpf[i] == 0){
            for(ll j = i; j<N-10; j += i){
                hpf[j] = i;
            }
        }
    }
    // for(int i=1e5+20;i<=1e5+30;i++){
    //     cout<<i<<" "<<hpf[i]<<endl;
    // }
    // for(int i=1e5+20;i<=1e5+30;i++){
    //     cout<<i<<" "<<spf[i]<<endl;
    // }
    // cout<<hpf[333]<<endl;
    while (t--){
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll a = arr[i];
            if(a <= k) continue;
            cnt = 1;
            while(a > k){
                ll b = hpf[a];
                if(a / b <= k){
                    ans += cnt;
                    break;
                }
                ll d = spf[a];
                // cout<<d<<" "<<a<<endl;
                ans = ans + cnt;
                cnt = cnt * d;
                a = a/d;
                // cout<<a<<" "<<d<<" "<<ans<<" "<<cnt<<endl;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
    }