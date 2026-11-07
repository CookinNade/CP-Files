#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 3e5+2;
ll siv[N];
ll sum[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    siv[1] = 1;
    siv[0] = 1;
    for(ll i = 2;i<=N;i++){
        if(siv[i] == 0){
            for(ll j = i;j<=N;j+=i){
                siv[j] = i;
            }
        }
    }
    cin>>t;
    while (t--){
        cin>>n>>k;
        set<ll>ofk;
        ll m = k;
        while(m!=1){
            ll d = siv[m];
            while(m % d == 0){
                m /= d;
            }
            ofk.insert(d);
        }
        ll arr[n];

        for(int i = 0;i<n;i++)cin>>arr[i];
        for(int i = 0;i<n;i++){
            ll a = arr[i];
            while(a!=1){
                ll d = siv[a];
                while(a % d == 0){
                    a /= d;
                }
                if(ofk.find(d) != ofk.end())sum[d] += arr[i];
            }
        }
        ll ans = 0;
        for(auto it = ofk.begin();it!=ofk.end();++it){
            ll a = (*it);
            ans = max(ans, sum[a]);
            sum[a] = 0;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }