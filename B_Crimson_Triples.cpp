#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll ans = 0;
        for(ll i = 1;i<=n;i++){
            k = n/i;
            ll ncpart = max(0ll,k*(k-1));
            ans = ans + ncpart + k;
        }
        cout<<ans<<"\n";
    }
    return 0;
    }