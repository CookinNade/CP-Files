#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
ll binexp(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b&1){
            ans = (ans * a) % M;
        } 
        b = b>>1;
        a = (a * a) % M;
    }
    return ans % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<binexp(2,n)<<endl;

    return 0;
    }