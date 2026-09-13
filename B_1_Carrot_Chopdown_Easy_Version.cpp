#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        int m;
        cin>>n>>m;
        int arr[n];
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            mp[a]++;
            arr[i] = a;
        }
        sort(arr,arr+n);
        ll ans = n;
        ll tot = 0;
        for(auto it = mp.begin();it!=mp.end();++it){
            ll num = (*it).first;
            ll ase = (*it).second;
            if(num % 2)continue;
            auto nit = lower_bound(arr,arr+n,num/2);
            ll hobe = nit - arr;
            hobe = n - hobe;
            hobe = hobe + ase;
            ans = max(ans,hobe);
        }
        cout<<ans<<'\n';
    }
    return 0;
    }