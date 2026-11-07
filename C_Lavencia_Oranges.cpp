#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll n;
bool hobe(ll ans){
    ll baki = n;
    for(ll i=ans;i>=1;i--){
        ll a = ans/i;
        // if(ans==3)cout<<i<<" "<<a<<endl;
        baki = max(0ll, baki - a*i);
        if(baki == 0)break;
    }
    return (baki == 0);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll hi = n;
        ll lo = 1;
        while(hi-lo>1){
            ll mid = hi+lo;
            mid /= 2;
            if(hobe(mid))hi = mid;
            else lo = mid+1;
        }
        ll ans = 1;
        if(hobe(lo))ans = lo;
        else ans = hi;
        cout<<ans<<'\n';
        ll baki = n;
        vector<pair<ll,ll>>v;
        for(ll i=ans;i>=1;i--){
            ll a = ans/i;
            if(baki - a*i >=0){
                v.push_back({i,a});
                baki = max(0ll, baki - a*i);
            }
            else{
                a = baki/i;
                v.push_back({i,a});
                baki = baki - a*i;
            }
            if(baki == 0)break;
        }
        k = 1;
        // for(int i=0;i<(int)v.size();i++)cout<<v[i].first<<" yo "<<v[i].second<<endl;
        for(int i=0;i<(int)v.size();i++){
            for(int j=0;j<v[i].second;j++){
                for(int l=0;l<v[i].first;l++)cout<<k<<" ";
                k++;
            }
        }
        cout<<'\n';
    }
    return 0;
    }