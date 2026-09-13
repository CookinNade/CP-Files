#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n+1];cnt=0;ll pref[n+1]; map<ll,ll>mp;
        pref[0]=0;
        for(ll i=1;i<=n;i++)cin>>arr[i];
        for(ll i=1;i<=n;i++){
            if(arr[i]<i) {
                cnt++;
                mp[i]=arr[i];
            }
            pref[i]=cnt;
            
        }
        // for(auto it = mp.begin();it!=mp.end();++it){
        //     cout<<(*it).first<<" "<<(*it).second<<endl;
        // }
        // for(int i=1;i<=n;i++){
        //     cout<<pref[i]<<" ";
        // }cout<<endl;
        ll ans=0;
        for(auto it=mp.begin();it!=mp.end();++it){
            if((*it).second==0)continue;
            ans= ans+pref[(*it).second-1];
        }
        cout<<ans<<endl;

    }
    return 0;
    }