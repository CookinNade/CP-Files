#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll x;
ll power(ll n){
    if(n == 0)return 1;
    return x * power(n-1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>x>>n;
    cout<<power(n);
    return 0;
}