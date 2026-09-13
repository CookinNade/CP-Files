#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k>>l>>r;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        map<ll,ll>x;
        map<ll,ll>y;
        ll ix=0; ll iy=0;
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(x.size()<k){
                if(ix!=0)ix++;
                for(;ix<n;ix++){
                    x[arr[ix]]++;
                    if(x.size()>=k)break;
                }
            }
            if(y.size()<=k){
                if(iy!=0)iy++;
                for(;iy<n;iy++){
                    y[arr[iy]]++;
                    if(y.size()>k)break;
                }
            }
            if(iy==n)iy--;
            if(y.size()>k and x.size()>=k)
                ans=ans+max(0ll,min(i+r-1,iy-1)-max(i+l-1,ix)+1ll);
            else if(y.size()==k and x.size()>=k)
                ans=ans+max(0ll,min(i+r-1,iy)-max(i+l-1,ix)+1ll);
            x[arr[i]]--;
            y[arr[i]]--;
            if(x[arr[i]]==0)x.erase(arr[i]);
            if(y[arr[i]]==0)y.erase(arr[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
    }