#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2e5+2;
ll arr[N];
int n;
ll f(ll a){
    ll ans = 0;
    // cout<<a<<" this is a "<<endl;
    for(int i=0;i<n;i++) {
        ans = ans + abs(a -  arr[i]);
        // cout<<a - arr[i]<<" "<<arr[i]<<" "<<a<<" "<<ans<<endl;
    }
    // cout<<arr[0]<<" this is arr[i] "<<endl;
    // cout<<ans<<" "<<a<<endl;
    return ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        
        vector<ll>plus;
        vector<ll>minus;
        for(int i=0;i<n;i++)cin>>arr[i];
        
        ll avg = *min_element(arr,arr+n);
        // avg = accumulate(arr,arr+n,0ll) / n;
        for(int i=0;i<n;i++){
            if(arr[i] > avg) plus.push_back(arr[i]);
            else if(arr[i] < avg) minus.push_back(arr[i]);
        }
        ll opp = 0 , opm = 0;
        ll cost = 0;
        for(int i=0;i<(int)plus.size();i++){
            plus[i] = abs(plus[i] - avg);
        }
        for(int i=0;i<(int)minus.size();i++){
            minus[i] = abs(minus[i] - avg);
        }
        if(!plus.empty()){
            sort(plus.begin(),plus.end());
            for(int i=0;i<(int)plus.size();i++){
                cost += plus[i];
                plus[i] -= opp;
                opp += plus[i];
            }
        }
        if(!minus.empty()){
            sort(minus.begin(),minus.end());
            for(int i=0;i<(int)minus.size();i++){
                cost += minus[i];
                minus[i] -= opm;
                opm += minus[i];
            }
        }
        ll hi = *max_element(arr,arr+n);
        ll lo = *min_element(arr,arr+n);
        while(hi-lo>2){
            ll m1 = lo + (hi-lo)/3;
            ll m2 = hi - (hi-lo)/3;
            if(f(m1) > f(m2)) lo = m1;
            else hi = m2;
        }
        cout<<min(f(lo), min(f(lo+1), f(hi)))<<" "<<opp+opm<<'\n';
    }
    return 0;
    }