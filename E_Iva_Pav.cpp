#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,q; 
    cin>>t;

    while (t--){
        cin>>n;
        ll g[n][31];
        memset(g,0,sizeof(g));
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int j=0;j<=30;j++){
            a=arr[0];
            if(a&(1<<j))g[0][j]++;
        }
        for(int i=1;i<n;i++){
            a=arr[i];
            for(int j=0;j<=30;j++){
                if(a&(1<<j))g[i][j]++;
                g[i][j]=g[i-1][j]+g[i][j];
            }
        }
        cin>>q;
        while(q--){
            cin>>l>>k;
            ll lo = l-1;
            ll hi=n-1,mid;
            while(hi-lo>1){
                mid=(hi+lo)/2;
                ll num=0;
                for(int j=0;j<=30;j++){
                    if(l>1){
                        a=g[mid][j];b=g[l-2][j];
                        if(a-b==mid-(l-1)+1)num=num+(1<<j);
                    }
                    else{
                        if(g[mid][j]==mid+1)num=num+(1<<j);
                    }
                }
                if(num>=k)
                    lo=mid;
                else hi=mid-1;
            }
            int arrr[2];
            arrr[0]=hi; arrr[1]=lo;
            ll ans=-2;
            for(int i=0;i<2;i++){
                c=arrr[i];
                ll num=0;
                for(int j=0;j<=30;j++){
                    if(l>1){
                        a=g[c][j];b=g[l-2][j];
                        if(a-b==c-(l-1)+1)num=num+(1<<j);
                    }
                    else {
                        if(g[c][j]==c+1)num=num+(1<<j);
                    }
                }
                if(num>=k)ans=max(ans,c);
            }
            cout<<ans+1<<" ";
        }
        cout<<endl;
    }
    return 0;
    }