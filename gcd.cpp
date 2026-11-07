#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
    if(b == 0)return a;
    return gcd(b, a%b);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b;
    cin>>a>>b;
    cout<<gcd(max(a,b) , min(a,b));
    
    return 0;
}