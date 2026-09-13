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
        cin>>n>>k;
        ll arr[n];
        r=k;
        map<ll,ll>mp;
        ll mx=-1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mx=max(mx,arr[i]);
            if(arr[i]==1){
                r--; continue;
            }
            mp[arr[i]]++;
        }
        if(r<0){
            cout<<1<<endl;
            continue;
        }
        ll ans=-1;
        for(auto it =mp.begin();it!=mp.end();++it){
            if(k>=n-(*it).second){
                ans=(*it).first;
            }
        }
        ll hi=mx; ll lo=1; ll mid;
        // cout<<r<<endl;
        while(hi-lo>1){
            c=r;
            mid=(hi+lo)/2;
            cout<<mid<<" these are mid"<<endl;
            for(int i=0;i<n;i++){
                if(arr[i]%mid==0 or arr[i]>=4*mid or arr[i]==1){
                    //siuu
                }
                else {
                    c--;
                }
            }
            // cout<<"these are final c "<<c<<endl;
            if(c>=0){
                lo=mid;
            }
            else hi=mid-1;
        }
        c=r;
        for(int i=0;i<n;i++){
            if(arr[i]%hi==0 or arr[i]>=4*hi){
                //siuu
            }
            else {
                c--;
            }
        }
        // cout<<ans<<" this is ans "<<endl;
        if(c>=0){
            cout<<max(ans,hi)<<endl;
            // cout<<"from hi\n";
        }
        else {
            cout<<max(ans,lo)<<endl;
            // cout<<"from lo\n";
        }
    }
    return 0;
    }