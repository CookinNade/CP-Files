#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,aa,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        ll a[n+1];
        ll b[n+1];
        ll c[n+1];
        ll ans[n+1];
        for(int i=1;i<=n;i++){
            cin>>aa;
            a[i]=aa+i;
            b[i]=aa+n+1-i;
            c[i]=min(a[i],b[i]);
            ans[i]=min(a[i],b[i]);
            
        }
        ll sum=0;
        sort(ans+1,ans+n+1);sort(c+1,c+n+1);
        cnt=0;
        for(int i=1;i<=n;i++){
            sum=sum+ans[i];
            ans[i]=sum;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<a[i]<<" ";
        // }cout<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<b[i]<<" ";
        // }cout<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<c[i]<<" ";
        // }cout<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        
        // cout<<endl;
        for(int i=1;i<=n;i++){
            ll lo=1;ll hi=n;
            while(hi-lo>1){
                ll mid=(hi+lo)/2;
                if(c[mid]>a[i]){
                    if(ans[mid]<=k){ // Possible
                        lo=mid;
                    }
                    else hi=mid;
                }
                else{
                    if(ans[mid]+a[i]<=k){ // Possible
                        lo=mid;
                    }
                    else hi=mid;
                }

            }
            if(lo==1){
                if(ans[1]+a[i]<=k and i!=2){cnt=max(cnt,2ll);}
                else if(a[i]<=k)cnt=max(cnt,1ll);
                else cnt=max(cnt,0ll);
            }
            else if(hi==n){
                if(ans[n]<=k){
                    cnt=max(cnt,hi);
                    // cout<<"from here\n";
                    break;
                }
                else cnt=max(cnt,hi-1);
            }
            else{
                cnt=max(cnt,lo);
            }
        }
        // cout<<endl;
        if(n==1){
            if(a[1]<=k)cout<<1<<endl;
            else cout<<0<<endl;
        }
        else cout<<cnt<<endl;
    }    
    return 0;
}   