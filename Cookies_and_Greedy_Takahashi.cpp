#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        cin>>n;
        set<ll>st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.insert(a);
        }
        ll sum = 0;
        ll cur = 0;
        for(int i=0;i<n;i++){
            auto it = st.lower_bound(cur);
            ll up = 1e17;
            if(it!=st.end())up = (*it);
            ll down = -1e17;
            if(it!=st.begin()){
                --it;
                down = (*it);
            }
            // cout<<up<<" "<<down<<" "<<cur<<endl; 
            if(abs(cur-up) >= abs(cur-down)){
                sum += abs(cur-down);
                cur = down;
            }
            else{
                sum+=abs(cur-up);
                cur = up;
            }
            // cout<<cur<<endl;
            st.erase(cur);
        }
        cout<<sum;
    }
    return 0;
    }