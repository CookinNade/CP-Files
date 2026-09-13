#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using vpl = vector<pair<ll,ll>>;
using vtl = vector<tuple<ll,ll,ll>>;

#define pb push_back
#define pf push_front
#define xrep(i,a,b) for(ll i = a; i < b; i++)
#define rep(i,a,b) for(ll i = a; i <= b; i++)
#define filla(a) for(auto& x : a) cin >> x
#define fillv(v,n) xrep(i,0,n){ll xv; cin >> xv; v.pb(xv);}
#define fills(s,n) xrep(i,0,n){ll xv; cin >> xv; s.insert(xv);}
#define all(x) x.begin(),x.end()



void solve(){


    vll prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    ll n; cin >> n;
    ll mul = 1; ll ind = 0;

    while(mul<=n){
        ll parbo = n / mul;
        if(prime[ind] > parbo) break;
        else mul *= prime[ind];
        ind++;
    }

    ll a = 1;
    xrep(i,0,ind){
        a*=(prime[i]-1);
    }
    a = mul-a;
    ll g = gcd(a,mul);
    cout << (a/g) << "/" << (mul/g) << '\n';
    

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //ll t; 
    //cin >> t;
    //while(t--){
        solve();
    //}

    return 0;
}