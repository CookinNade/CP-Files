#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll M =1e9;
        M=M+7;
        ll a[n];ll b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];

        map<ll,ll>mp;
        sort(b,b+n);sort(a,a+n);

        for(int i=0;i<n;i++){
            auto it= lower_bound(b,b+n,a[i]);
            // --it;
            mp[a[i]]=it-b;
        }
        ll ans=1;
        for(ll i=0;i<n;i++){
            ll val=mp[a[i]]-i;
            // cout<<" a[i] was "<<a[i]<<" mp[a[i]] was "<<mp[a[i]]<<" val was "<<val<<endl;
            if(val<1){
                ans=0;
                break;
            }
            ans=(val*ans)%M;
        }
        cout<<ans<<endl;



    }
    return 0;
    }