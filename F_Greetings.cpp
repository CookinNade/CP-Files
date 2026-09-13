#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        pair<ll,ll>arr[n];
        ordered_set st;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            arr[i].first=b;
            arr[i].second=a;
        }
        ll ans=0;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            a= arr[i].second;
            b= arr[i].first;
            ans=ans+st.size()-st.order_of_key(a);
            st.insert(a);
            // cout<<st.order_of_key(b)<<" "<<st.order_of_key(a)<<" "<<a<<" "<<b<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
    }