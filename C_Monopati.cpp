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
        ll a[n]; ll b[n]; ll mxa[n]; ll mxb[n]; ll mna[n]; ll mnb[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        d=b[n-1];
        mxb[n-1]=d;
        for(int i=n-2;i>=0;i--)mxb[i]=max(mxb[i+1],b[i]);
        d=b[n-1];
        mnb[n-1]=d;
        for(int i=n-2;i>=0;i--)mnb[i]=min(mnb[i+1],b[i]);
        d=a[0];
        mxa[0]=d;
        for(int i=1;i<n;i++)mxa[i]=max(mxa[i-1],a[i]);
        d=a[0];
        mna[0]=d;
        for(int i=1;i<n;i++)mna[i]=min(mna[i-1],a[i]);
        ll ans[2*n+1]; fill(ans+1,ans+1+n*2,1e13);
        ll mxans[n]; ll mnans[n];
        for(int i=0;i<n;i++){
            mxans[i]=max(mxa[i],mxb[i]);
            mnans[i]=min(mna[i],mnb[i]);
        }
        for(int i=0;i<n;i++) ans[mnans[i]]=min(ans[mnans[i]],mxans[i]);
        cnt=0;
        for(int i=2*n-1;i>=1;i--)ans[i]=min(ans[i],ans[i+1]);
        for(int i=1;i<=2*n;i++){
            if(ans[i]==1e13)continue;
            cnt=2*n-ans[i]+1ll+cnt;
        }
        cout<<cnt<<endl;
    }
    return 0;
}