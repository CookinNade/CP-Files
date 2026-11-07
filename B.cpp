#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M  = 1e9+7;
ll binpow(ll b) {
    long long res = 1;
    ll a = 26;
    while(b>0){
        if(b&1){
            res=(res*a) % M;
        }
        a = (a*a) % M;
        b >>= 1;
    }
    return res;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    if(n==2)cout<<26<<" "<<650<<" "<<0;
    else cout<<26<<" "<<0<<" "<<(binpow(n)-26+M)%M;
    return 0;
    }