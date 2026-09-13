#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,c,d,cnt,r,l,k,x; 
    cin>>n>>m;
    const ll M = 998244353;
    ll a[n]; vector<ll>b(m); ll pref[m+1];
    for(int i=0;i<n;i++)cin>>a[i];
    pref[0]=0;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(b.begin(),b.end());
    for(int i=0;i<m;i++)pref[i+1]=b[i]+pref[i];
    ll ans=0;
    for(int i=0;i<n;i++){
        auto it = upper_bound(b.begin(),b.end(),a[i]);
        // cout<<it-b.begin()<<endl;
        ll mul=it-b.begin();
        
        ans = (ans + mul*a[i]-2*pref[mul] + pref[m]-a[i]*(m-mul))%M;
        // cout<<n-mul<<" "<<a[i]<<" "<<pref[mul]<<" "<<pref[m]<<endl;
        // cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
    }