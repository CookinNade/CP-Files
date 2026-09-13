#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n+1];
        for(ll i=1;i<=n;i++){
            cin>>arr[i];
        }
        cnt=0;
        set<pair<ll,ll>>st;
        for(ll i=1;i<=n;i++){
            ll og =i;
            for(ll j=arr[i]-og;j<=n;j=j+arr[i]){
                if(og==j or j<1)continue;
                // cout<<j<<" ";
                // cout<<i<<" "<<j<<" "<<arr[i]<<" "<<arr[j]<<endl;
                if(arr[i]*arr[j]==j+i){
                    // cout<<"YES "<<i<<" "<<j<<endl;
                    int mx = max(j,i);
                    int mn = min(j,i);
                    if(st.find({mx,mn})==st.end()){
                        cnt++;
                        st.insert({mx,mn});
                    }
                    
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
    }