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
        cin>>n>>k;
        ll a[n]; ll b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        ll suff[n]; ll pref[n];
        suff[n-1]=a[n-1]; pref[0]=a[0];
        for(int i=1;i<n;i++) pref[i]=a[i]+max(pref[i-1],0ll);
        for(int i=n-2;i>=0;i--) suff[i]=a[i]+max(suff[i+1],0ll);
        ll ans = LLONG_MIN;
        if(k%2){
            for(int i=0;i<n;i++)ans=max(ans,suff[i]+pref[i]-a[i]+b[i]);
            cout<<ans<<endl;
        }
        else {
            for(int i=0;i<n;i++)ans=max(ans,suff[i]+pref[i]-a[i]);
            cout<<ans<<endl;
        }
    }
    return 0;
    }