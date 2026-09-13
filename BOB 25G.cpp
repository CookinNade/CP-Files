#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt; 
    cin>>t;
    while (t--){
        ll l,r;
        cin>>n>>l>>r;
        vector<ll>v;
        for(int i = 0; i<=60; i++){
            if(!(n & (1ll<<i))){
                v.push_back(i);
            }
        }
        ll bit = (ll)v.size();
        ll lo = 0;
        ll hi = (1ll<<bit) - 1ll;
        ll tot = (1ll<<bit);
        ll mid;
        ll num = 0;
        while(hi - lo > 1){
            num = 0;
            mid = (hi+lo) / 2;
            for(int i = 0; i<(int)v.size(); i++){
                if((mid & (1ll<<i))){
                    num += (1ll<<v[i]);
                }
            }
            // cout<<num<<endl;
            if(num >= l) hi = mid;
            else lo=mid+1;
        }
        mid = lo;
        ll mid2 = hi;
        ll num2 = 0;
        num = 0;
        for(int i = 0; i < (int)v.size(); i++){
            if((mid & (1ll<<i))){
                num += (1ll<<v[i]);
            }
            if((mid2 & (1ll<<i))){
                num2 += (1ll<<v[i]);
            }
        }
        if(num  >= l) {
            tot = tot - lo;
        }
        else if(num2 >= l){
            tot = tot - hi;
        }
        else tot = 0;
        hi = (1ll<<bit) - 1;
        lo = 0;

        while(hi - lo > 1){
            num = 0;
            mid = (hi+lo) / 2;
            for(int i = 0; i<(int)v.size(); i++){
                if((mid & (1ll<<i))){
                    num += (1ll<<v[i]);
                }
            }
            if(num  > r)hi = mid;
            else lo = mid + 1;
        }
        num = 0;
        mid = lo;
        mid2 = hi;
        num2 = 0;
        for(int i = 0; i<(int)v.size(); i++){
            if((mid & (1ll<<i))){
                num += (1ll<<v[i]);
            }
            if((mid2 & (1ll<<i))){
                num2 += (1ll<<v[i]);
            }
        }
        ll mn = 0;
        ll ache = (1ll<<bit) - 1;
        if(num  > r) mn = ache - lo + 1ll;
        else if(num2 > r) mn = ache - hi + 1ll;
        else mn = 0;
        tot = tot - mn;
        cout<<max(0ll,tot)<<'\n';
        cnt = 0;
        num = 1;
    }
    return 0;
    }