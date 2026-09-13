#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll t,n,m,l,a,b,c,d,cnt;
    string s;
    // cin>>t;
    // while(t--){
       map<ll,ll>mp;
       cin>>n>>m;
       ll arr[n];
       ll mx=1e9+10;
       for(int i=0;i<n;i++) cin>>arr[i];
       for(int i=0;i<m;i++){
            cin>>a;
            mx=min(a,mx);
            mp[a]++;
       }
       ll ans=0;
       sort(arr,arr+n,greater<int>());
       for(int i=0;i<n;i++){
        cnt=m;int f=0;
            while(cnt>0){
                auto it =mp.lower_bound(arr[i]);
                
                if(it!=mp.end()){
                    if(arr[i]!=(*it).first and f==0){
                        f++; cnt--; ans=ans+arr[i];
                        // cout<<"it was used  and it was " <<arr[i]<<endl;
                    }
                    else f++;
                    if(cnt>=(*it).second){
                        cnt = cnt-(*it).second;
                        ans = ans + ((*it).second) * ((*it).first);
                        mp.erase((*it).first);
                    }
                    else{
                        ans = ans + cnt*((*it).first);
                        mp[(*it).first]=(*it).second-cnt;
                        cnt=0;
                    }
                }
                else{
                    ans = ans + cnt*arr[i];
                    cnt=0;
                }
            }
       }
    //    cout<<mx<<" "<<arr[0]<<endl;
       if(mx<arr[0])cout<<-1<<endl;
       else cout<<ans<<endl;
    // }
    

    
} 