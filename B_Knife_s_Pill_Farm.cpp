#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll m;
        cin>>n>>m;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        if(m==1){
            cout<<*max_element(arr,arr+n)<<'\n';
            continue;
        }
        ll ans = -1e17;
        ll sum = 0;
        multiset<ll>st;
        for(int i=0;i<m-1;i++){
            sum-=arr[i];
            st.insert(arr[i]);
        }
        // cout<<sum<<endl;
        for(int i=m-1;i<n;i++){
            ans = max(ans, sum + m*arr[i]);
            auto it = --st.end();
            ll boro = (*it);
            ll cont = arr[i];
            st.erase(it);
            sum +=boro;
            ll dhukbe = min(cont,boro);
            st.insert(dhukbe);
            sum -= dhukbe;
            // cout<<i<<" "<<(int)st.size()<<'\n';
            // cout<<dhukbe<<" "<<cont<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
    }