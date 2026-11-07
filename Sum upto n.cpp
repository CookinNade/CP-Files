#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll sum(ll n){
    if(n == 0)return 0;
    return n + sum(n-1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<sum(n);
    return 0;
}