#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k,m; 
    cin>>t;
    cin.ignore();
    while (t--){
        cin>>n>>m>>k;
        ll mn = INT_MAX;
        for(int i = 0; i<k; i++){
            ll x,y;
            cin>>x>>y;
            ll mnx = min(abs(x-n),abs(x-1));
            ll mny = min(abs(y-m),abs(y-1));
            ll mnf = min(mnx , mny);
            mn = min(mn , mnf);
        }
        if(mn <5)cout<<"A\n";
        else cout<<"B\n";
    }
    return 0;
    }