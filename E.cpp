#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> arr(n);
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        mp[a]++;
        arr[i] = a;
    }
    sort(arr.begin(),arr.end());
    // cout<<mp.size()<<endl;
    for(int i=0;i<n;i++){
        int a = arr[i];
        if(mp.find(a)!=mp.end() and mp[a]%2==0)mp.erase(a);
    }
    // cout<<mp.size()<<"size alter"<<endl;
    ll ans = 0;
    ll mx = 0;
    for(auto it = mp.begin();it!=mp.end();++it){
        ll a = (*it).first;
        // cout<<a<<endl;
        auto nit = upper_bound(arr.begin(),arr.end(),a);
        if(nit == arr.end()){
            ans += INT_MAX;
            mx = INT_MAX;
            continue;
        }
        else{
            ll b = (*nit);
            ll add = b - a;
            mx = max(add,mx);
            ans+=add;
        }
    }
    // cout<<ans<<'\n';
    cout<<ans-mx<<'\n';
    

    return 0;
    }