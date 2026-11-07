#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll x;
void tobinary(ll n){
    if(n == 0)return;
    tobinary(n/2);
    cout<<n%2;
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    tobinary(n);
    return 0;
}