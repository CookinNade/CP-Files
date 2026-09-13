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
    while (t--){
        cin>>n>>k>>a>>b;
        ll f[n],s[n];
        ll arr[n];
        ll p[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            f[i]=arr[i]%a;
            s[i]=arr[i]%b;
            s[i]=s[i]%a;
        }
        for(int i=0;i<n;i++)p[i]=min(f[i],s[i]);
        for(int i=1;i<n;i++)p[i]=p[i-1]+p[i];
        for(int i=1;i<n;i++)s[i]=s[i]+s[i-1];
        for(int i=1;i<n;i++)f[i]=f[i]+f[i-1];
        ll ans=1e18;
        for(int i=0;;i++){
            if(i+k>n)break;
            if(i==0)c=0;
            else c=f[i-1];
            d=f[i+k-1];
            m=d-c;
            if(i==0)c=0;
            else c=s[i-1];
            d=s[i+k-1];
            m=min(m,d-c);
            ll tot=0;
            if(i==0)tot=0;
            else tot=p[i-1];
            tot=tot+m;
            if(i+k!=n)tot=p[n-1]-p[i+k-1]+tot;
            ans=min(ans,tot);
        }
        cout<<ans<<endl;

    }
    return 0;
    }