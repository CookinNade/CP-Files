#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,y; 
    cin>>t;
    string s;
    while (t--){
        ll rm,lm;
        cin>>k>>l>>r>>lm>>rm;
        m=k;
        ll ans=0;
        k=1;
        for(;k<=rm/l;k=k*m){
            b=1e15;
            ll hi=r,lo=l,mid;
            while(hi-lo>1){
                mid=(hi+lo)/2;
                if(mid*k<=rm)lo=mid;
                else hi=mid-1;
            }
            if(hi*k<=rm and hi*k>=lm)b=hi;
            else if(lo*k<=rm and lo*k>=lm)b=lo;
            if(b==1e15)continue;
            hi=b;lo=l;
            while(hi-lo>1){
                mid=(hi+lo)/2;
                if(mid*k>=lm) hi=mid;
                else lo=mid+1;
            }
            if(lo*k>=lm){
                ans=ans+b-lo+1;
                // cout<<ans<<" "<<k<<" "<<b<<" "<<lo<<endl;
            }
            else {
                ans=ans+b-hi+1;
                // cout<<ans<<" "<<k<<" "<<b<<" "<<hi<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }