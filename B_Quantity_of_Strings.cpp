#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans = 1;
    if(k == 1 or k>n){
        for(int i=0;i<n;i++) ans = (ans*m) % M;
        cout<<ans;
        return 0;
    }
    if(k == n){
        for(int i=0;i<n/2 + n%2;i++) ans = (ans*m) % M;
        cout<<ans;
        return 0;
    }
    if(k % 2 == 0){
        cout<<m;
        return 0;
    }
    if(k % 2){
        ans = m*(m-1) % M;
        cout<<ans + m<<'\n';
    }

    return 0;
    }