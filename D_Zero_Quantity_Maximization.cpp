#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,c,d;
    // ll g=gcd(2,0);
    // cout<<g<<endl;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll b[n];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        if(a[i]<0 and b[i]<0){
            a[i]=abs(a[i]);
            b[i]=abs(b[i]);
        }
        else if(b[i]<0){
            a[i]=-a[i];
            b[i]=abs(b[i]);
        }
    }
    ll cnt=0;
    map<pair<ll,ll>,ll>mp;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(b[i]==0)cnt++;
            continue;
        }
        if(b[i]==0){
            mp[{0,0}]++;
            continue;
        }
        ll g =gcd(a[i],b[i]);
        // cout<<g<<endl;
        c=a[i]/g;
        d=b[i]/g;
        mp[{c,d}]++;
    }
    ll ans=0;
    for(auto it = mp.begin();it!=mp.end();++it){
        ans=max(ans,(*it).second);
    }
    cout<<ans+cnt<<endl;
    return 0;
    }