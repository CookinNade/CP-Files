#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<ll,ll>mp;
    int n;
    cin>>n;
    ll h[n];
    ll v[n];
    for(int i=0;i<n;i++)cin>>h[i];
    for(int i=0;i<n;i++)cin>>v[i];
    mp[h[0]] = v[0];
    for(int i=1;i<n;i++){
        auto it = mp.lower_bound(h[i]);
        ll val = v[i];
        if(it != mp.begin()){
            --it;
            val += (*it).second; 
        }
        while(true){
            if(mp.empty())break;
            auto it = mp.lower_bound(h[i]);
            if(it == mp.end())break;
            if((*it).second <= val)mp.erase((*it).first);
            else break;
        }
        mp[h[i]] = val;
    }
    ll ans = -1;
    for(auto it = mp.begin();it!=mp.end();++it) {
        ans = max((*it).second, ans);
        // cout<<(*it).second<<" "<<(*it).first<<endl;
    }
    cout<<ans;
    return 0;
    }