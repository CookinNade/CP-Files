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
        ll arr[31];
        fill(arr,arr+31,0);
        ll val[n];
        for(int i=0;i<n;i++){
            cin>>val[i];
        }
        for(int i=0;i<n;i++){
            a=val[i];
            for(int j=0;j<=31;j++){
                if(((a>>j)&1))arr[j]++;
            }
        }
        cnt=0;
        ll real=0;
        for(int i=0;i<=31;i++){
            if(arr[i]==n)real=real+(1ll<<i);
        }
        for(int i=0;i<n;i++){
            a=val[i];
            int noer=0;
            for(int j=0;j<=31;j++){
                if(((a>>j)&1)==((real>>j)&1)) continue;
                else{
                    noer++;break;
                }
            }
            if(noer)continue;
            else cnt++;
        }
        // cout<<real<<endl;
        // cout<<cnt<<endl;
        if(cnt<2)cout<<0<<endl;
        else{
            ll const M= 1e9+7ll;
            ll ans =(cnt*(cnt-1ll))%M;
            // cout<<ans<<"this is ans "<<endl;
            for(ll j =2;j<=n-2;j++){
                ans=(ans*j)%M;
            }
            cout<<ans<<endl;
        }
        // cout<<real<<endl;
        // for(int i=0;i<6;i++){
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
    }
    return 0;
    }