#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 31624;
bool isprime[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(isprime,isprime+N,true);
    vector<ll>v;
    for(ll i = 2; i < N; i++){
        if(isprime[i]){
            v.push_back(i);
            // cout<<i<<" ";
            for(ll j = i * 2; j<N; j = j + i) isprime[j] = false;
        }
    }
    ll t,n,cnt,k;
    // cout<<v.size()<<endl;
    cin>>t;
    while (t--){
        cin>>n;
        bool yes = false;
        ll ans = 1;
        for(int i=0; i<v.size(); i++){
            if(n % v[i] == 0){
                cnt = 0;
                while(n % v[i] == 0){
                    n /= v[i];
                    cnt++;
                }
                if(cnt & 1)yes = true;
                cnt /= 2;
                cnt++;
                ans *= cnt;
            }
        }
        if(n!=1) yes = true;
        if(!yes)ans--;
        cout<<ans<<endl;
    }
    return 0;
    }