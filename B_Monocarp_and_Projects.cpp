#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    ll x,y,z;
    cin>>t;
    while (t--){
        cin>>x>>y>>k;
        ll cur = x;
        ll rem = 0;
        ll ans = 0;
        ll i = 0;
        for(;i<k;i++){
            if((y+i) / (cur+i) == 1){
                rem = (y+i) % (cur+i);
                break;
            }
            ans = ans + (y+i) % (cur+i);
        }
        ll baki = k - i ;
        ans = ans + rem * baki;
        cout<<ans<<'\n';
    }
    return 0;
    }