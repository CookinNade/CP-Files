#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll summar(ll p, ll s){
    ll q = p;
    return (q+1) * s + 2ll * s * (q*(q+1))/2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k,s; 
    cin>>t;
    vector<ll>v;
    ll sum = 0;
    for(int i=1; ; i++){
        ll a = i/2;
        if(i%2)a++;
        sum += a*a;
        v.push_back(sum);
        if(sum > 1e12)break;
    }
    // cout<<v.size()<<endl;
    while (t--){
        cin >> n >> s;
        while(n--){
            ll z;
            cin >> z;
            ll hi = min(z, (ll)v.size());
            ll lo = 0;
            ll mid;
            while(hi - lo >1){
                mid = hi + lo;
                mid /=2;
                if(v[mid] * s > z) hi = mid ;
                else lo = mid + 1;
            }
            ll p;
            if(v[lo] * s >= z) p = lo +1;
            else p = hi + 1;
            ll rem = z;
            if(p != 1){
                rem -= v[p-2] * s ;
            }
            lo = 0; hi = p / 2;
            if(p % 2 == 0) hi--;
            ll full = summar(hi,s);
            ll start = hi;

            while(hi - lo > 1){
                mid  = hi + lo;
                mid /= 2;
                if(full - summar(mid , s) < rem) hi = mid;
                else lo = mid + 1;
            }
            ll x;
            if(full - summar(lo, s) < rem) x = lo;
            else x = hi;
            ll energy = p - x ;
            
            ll ans = 0;
            if(x == 0){
                ans = rem - full + summar(x,s);
            }
            else if (x == 1) ans = rem - full + summar(x,s) + s;
            else ans = s;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
    }