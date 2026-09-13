#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,def,mn; 
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    ll tot = accumulate(arr,arr+n-1,0ll);
    ll total = tot+arr[n-1];
    cin>>m;
    ll x[m];
    ll y[m];
    for(int i=0;i<m;i++){
        cin>>x[i];
        cin>>y[i];
    }
    for(int i=0;i<m;i++){
        if(arr[n-1]<=x[i]){
            ll del = x[i]-arr[n-1];
            if(tot>=y[i]) cout<<del<<endl;
            else cout<<del+y[i]-tot<<endl;
        }
        else{
            ll tfnd=x[i];
            int hi = n-1;
            int lo = 0;
            while(hi-lo>1){
                int mid=(hi+lo)/2;
                if(arr[mid]>=tfnd) hi=mid;
                else lo=mid;
                }
                ll hiv=arr[hi]; ll lov=arr[lo]; mn = 1e18;
                if(lov>=x[i]){
                    def=total-lov;
                    if(def>=y[i]) mn=min(0ll,mn);
                    else mn=min(mn,y[i]-def);
                }
                else {
                    ll cnt = x[i]-lov;
                    def=total-lov;
                    if(def>=y[i]) mn=min(cnt,mn);
                    else mn=min(mn,y[i]-def+cnt); 
                }
                if(hiv>=x[i]){
                    def=total-hiv;
                    if(def>=y[i]) mn=min(0ll,mn);
                    else mn=min(mn,y[i]-def);
                }
                // cout<<" i was :"<<i<<endl;
                cout<<mn<<endl;
            }
    }
    return 0;
    }