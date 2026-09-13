#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,q; 
    // cin>>t;
    string s;
    // while (t--){
        cin>>n>>q;
        ll ans=0;
        ll arr[n+1];
        for(int i=1;i<=n;i++){
            cin>>a;
            arr[i]=a;
            ans =ans+a;
            // cout<<i<<" "<<a<<endl;
        }
        ll cur=-1;
        bool first= true;
        set<int>st;
        // cout<<ans<<endl;
        while(q--){
            cin>>a;
            if(a==1){
                int yes=0;
                cin>>b>>c;
                auto it = st.lower_bound(b);
                if (*it==b and it!=st.end()){
                    // cout<<"hello from here\n";
                    yes++;
                }
                else {
                    // cout<<"fhello from 23\n";
                    st.insert(b);
                }
                
                // cout<<b<<" "<<c<<endl;
                if(yes or cur==-1){
                    ans=ans+c-arr[b];
                    arr[b]=c;
                }
                else {
                    // cout<<"hello "<<b<<" "<<c<<endl;
                    ans= ans+c-cur;
                    arr[b]=c;
                }
                cout<<ans<<endl;
            }
            else{
                st.clear();
                cin>>cur;
                ans=cur*n;
                cout<<ans<<endl;
            }
        }

    // }
    return 0;
    }