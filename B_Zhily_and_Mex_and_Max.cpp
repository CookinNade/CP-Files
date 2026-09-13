#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        set<ll>st;
        ll mx = -1;
        ll mex = 0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            mx = max(mx,a);
            st.insert(a);
        }
        for(int i=0;i<=n;i++){
            if(st.find(i)!=st.end())mex++;
            else break;
        }
        ll ans = mx * n;
        // cout<<mex<<endl;
        if(mx<mex){
            ans = ans + (mex*(mex+1))/2 - mx + (n-mex) * mex;
        }
        else ans = ans + (mex*(mex+1))/2 + (n-mex -1) * mex ;
        cout<<ans<<'\n';

    }
    return 0;
    }