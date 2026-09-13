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
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll prev = 0;
        for(int i=0;i<n;i++){
            prev = (prev + arr[i]) % k;
            arr[i] = prev;
        }
        set<ll>st;
        st.insert(0ll);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(st.find(arr[i]) != st.end()){
                ans++;
                st.clear();
                st.insert(arr[i]);
            }
            else st.insert(arr[i]);
        }
        cout<<ans;
        
    }
    return 0;
    }