#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, tot, s;
    cin>>n>>s>>tot;
    ll arr[n];
    for(int i=1;i<n;i++)cin>>arr[i];
    vector<ll>dane;
    vector<ll>bame;
    vector<ll>bamepref;
    vector<ll>danepref;
    ll sum = 0;
    for(int i=s;i<n;i++){
        sum += arr[i];
        dane.push_back(arr[i]);
        danepref.push_back(sum);
    }
    sum = 0;
    for(int i=s-1;i>=1;i--){
        sum+=arr[i];
        bame.push_back(arr[i]);
        bamepref.push_back(sum);
    }
    
    ll ans = 1;
    ll used = 0;
    for(int i=0;i<(int)dane.size();i++){
        used += dane[i];
        if(used > tot)break;
        auto it = upper_bound(bamepref.begin(),bamepref.end(), tot - used*2);
        if(it == bamepref.begin())ans = max(ans, (ll)i+2);
        else if(it == bamepref.end()) ans = max(ans, (ll)bamepref.size() + i+2);
        else{
            --it;
            ll bcount = it - bamepref.begin() + 1;
            ans = max(ans, (ll)i+2 + bcount);
        }
    }
    used = 0;
    for(int i=0;i<(int)bame.size();i++){
        used += bame[i];
        if(used > tot)break;
        else ans = max(ans, (ll)i+2);
        auto it = upper_bound(danepref.begin(),danepref.end(), tot - used*2);
        if(it == danepref.begin())ans = max(ans, (ll)i+2);
        else if(it == danepref.end()) ans = max(ans, (ll)danepref.size() + i+2);
        else{
            --it;
            ll bcount = it - danepref.begin() + 1;
            ans = max(ans, (ll)i+2 + bcount);
        }
        // cout<<
    }
    // cout<<bame.size()<<'\n';
    // cout<<dane.size()<<'\n';
    cout<<ans<<'\n';
    return 0;
    }