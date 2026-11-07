#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll ncr(ll n, ll d){
    ll up = 1;
    for(int i=2;i<=n;i++)up*=i;
    ll down1 = 1;
    for(int i=2;i<=d;i++)down1 *= i;
    for(int i=2;i<=abs(d-n);i++)down1 *= i;
    return up/down1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        if(n)cout<<0<<'\n';
        else cout<<1<<'\n';
    }
    return 0;
    }