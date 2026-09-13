#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

ll n;
const ll N=2e5+2;
ll cnt[N+2];
ll f[N];
void mex(ll n){
    fill(cnt,cnt+2+n,0);
    ll mex=n+1;
    for(int i=0;i<n;i++)cnt[f[i]]++;
    for(int i=0;i<=n;i++){
        if(cnt[i]==0){
            mex=i;
            break;
        }
    }
    // cout<<mex<<endl;
    for(int i=0;i<n;i++){
        if(f[i]>mex)f[i]=mex;
        else if(cnt[f[i]]==1) f[i]=min(mex,f[i]);    
        else f[i]=mex;
    }
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,a,b,c,d,r,l,k,x; 
    cin>>t;
    while (t--){
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>f[i];
        ll ans=0;
        l=k;
        for(int i=0;i<2 and i<l;i++){
            ans=0;
            mex(n);
            k--;
            for(int j=0;j<n;j++) ans=ans+f[j];
        }
        if(k==0){
            cout<<accumulate(f,f+n,0ll)<<endl;
            continue;
        }
        ll fans=0; ll sans=0;
        l=k;
        mex(n);
        for(int i=0;i<n;i++)fans=fans+f[i];
        k--;
        if(k==0){
            cout<<accumulate(f,f+n,0ll)<<endl;
            continue;
        }
        mex(n);
        for(int i=0;i<n;i++)sans=sans+f[i];
        k--;
        if(k==0)cout<<accumulate(f,f+n,0ll)<<endl;
        else{
            ll rem = k/2;
            if(k%2)cout<<fans<<endl;
            else cout<<sans<<endl;
        }
    }
    return 0;
    }