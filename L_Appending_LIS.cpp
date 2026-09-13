#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll psum[n];
        psum[0] = arr[0];
        for(int i=1;i<n;i++)psum[i] = psum[i-1] + arr[i];
        int yes[n] = {};
        ll c = 0;
        // for(int i=1;i<n;i++)yes[i] += yes[i-1];
        vector<ll>lds;
        lds.push_back(arr[0]);
        ll sze[n];
        sze[0] = 1;
        if(arr[0] <= 0)yes[0] = 1;
        for(int i=1;i<n;i++){
            if(arr[i] > lds.back())lds.push_back(arr[i]);
            else{
                auto it = lower_bound(lds.begin(),lds.end(),arr[i]);
                ll ind = it - lds.begin();
                lds[ind] = arr[i];
            }
            ll sz = (ll)lds.size();
            sze[i] = sz;
            if(lds.back() < sz)yes[i] = 1;
        }

        for(int i=0;i<n;i++){
            if(yes[i]){
                ll tot = psum[i];
                ll jog = sze[i] + k - 1;
                ll sum = (jog * (jog+1ll)) /2;
                ll biyog = (sze[i] * (sze[i]-1)) /2;
                biyog = max(0ll, biyog);
                sum -= biyog;
                tot += sum;
                cout<<tot<<" ";
                continue;
            }
            else{
                ll tot = psum[i];
                tot = tot + k*sze[i];
                cout<<tot<<" ";
                continue;
            }
        }
        cout<<'\n';
    }
    return 0;
    }