#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll digitsum(ll n){
    if(n == 0)return 0;
    return n%10 + digitsum(n/10);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<digitsum(n);
    return 0;
}