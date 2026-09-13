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
        ll a[n],b[n],c[n];
        for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
        ll free=0;
        ll neg=0;
        int yes=0;
        for(int i=0;i<n;i++) {
            free=free+(b[i]-1)*a[i];
            neg=neg+c[i];

            if(a[i]*b[i]-c[i]>0)yes++;
        }
        ll ans = LLONG_MAX;
        if(free>=k)cout<<0<<endl;
        else if(yes==0)cout<<-1<<endl;
        else{
            k=k-free;
            d=k;

            for(int i=0;i<n;i++){
                d=k;
                if(a[i]*b[i]-c[i]<=0)continue;
                else{
                    ll anss=1;
                    d=k-a[i]+c[i];
                    d=d-(a[i])*(b[i]-1ll);
                    if(d<=0){
                        ans=min(ans,anss);
                        continue;
                    }
                    r = a[i]*b[i]-c[i];
                    anss = anss + (d/r);
                    if(d%r) anss++;
                    ans=min(anss,ans);
                }
            }
            cout<<ans<<endl;
        }
        
        
    }
    return 0;
    }