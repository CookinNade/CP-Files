#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll x;
ll ncr(ll n, ll r){
    if(r == 0 or r==n)return 1;
    return ncr(n-1, r-1) + ncr(n-1,r);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,r;
    cin>>n>>r;
    cout<<ncr(n,r);
    return 0;
}