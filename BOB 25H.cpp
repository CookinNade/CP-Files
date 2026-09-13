#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
bool isprime(ll n){
    if(n == 1)return false;
    for(ll i = 2; i*i <=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    const ll N = 1e12;
    cin>>t;
    vector<ll>f = {2,4,6,10,12,16,18,22,28,30,36,40,42,46,52,58,60};
    while (t--){
        cin>>n;
        ll g = 0;
        for(int i = 0; i<n; i++){
            ll a;
            cin>>a;
            g = __gcd(a,g);
        }
        vector<int>v;
        // cout<<g<<endl;
        for(ll i = 2; i*i<= min(N,g); i++){
            if(g % i == 0){
                cnt = 0;
                while(g % i == 0){
                    cnt++;
                    g /= i;
                }
                // cout<<i<<" "<<cnt<<endl;
                if(cnt == 1) continue;
                else v.push_back(cnt);
            }
        }
        ll ans = 0;
        ll hi =  1e9;
        ll lo = 2,mid;
        while(hi - lo > 1){
            mid = (hi+lo)/2;
            if(mid * mid>= g) hi = mid;
            else lo = mid + 1;
        }
        if(lo * lo == g and g!=1 and isprime(lo)) ans++;
        else if(hi * hi == g and g!=1 and isprime(hi))ans++;
        hi = 1e6;
        lo = 2;
        while(hi - lo > 1){
            mid = (hi+lo)/2;
            if(mid * mid * mid >= g) hi = mid;
            else lo = mid + 1;
        }
        if(lo * lo * lo == g and g!=1 and isprime(lo)) {
            ans++;
            g = 1;
        }
        else if(hi * hi * hi == g and g!=1 and isprime(hi)) {
            ans++;
            g = 1;
        }
        for(int i = 0;i<v.size();i++){
            auto it = upper_bound(f.begin(),f.end(),v[i]);
            int ad;
            if(it != f.end()) ad = it - f.begin();
            else{
                --it;
                ad = it - f.begin();
                ad++;
            }
            ans = ans + ad;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }   