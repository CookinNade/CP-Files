#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    map<ll,ll>mp;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        mp[a]++;
    }
    ll ans = 0;
    for(auto it = mp.begin();it!=mp.end();++it){
        ll b = (*it).second;
        ans = ans + b*(b-1)/2;
    }
    cout<<ans;
    
    return 0;
    }