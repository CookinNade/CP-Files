#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll factorial(ll n){
    if(n==0)return 1;
    return n*factorial(n-1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}