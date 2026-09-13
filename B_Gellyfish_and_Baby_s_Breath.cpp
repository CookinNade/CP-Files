#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 998244353;
ll binexp(ll n){
    ll a =2;
    ll ans=1;
    while(n>=1){
        if(n&1){
            ans=(ans*a)%M;
            // cout<<"hello\n";
        }
        n=(n>>1); a=(a*a)%M;
        // cout<<ans<<endl;
    }
    return ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,c,d; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll a[n];
        ll b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        ll mx=-1;
        int ind=-1;
        pair<ll,ll>ans[n];
        pair<ll,ll>bns[n];
        for(int i=0;i<n;i++){
            if(a[i]>mx){
                ind =i;
                mx=a[i];
                ans[i]={b[0],a[i]};
            }
            else{
                ans[i]={mx,b[i-ind]};
            }
        }
        // cout<<binexp(3)<<endl;
        ind=-1; mx=-1;
        for(int i=0;i<n;i++){
            if(b[i]>mx){
                ind=i;
                mx=b[i];
                bns[i]={a[0],b[i]};
            }
            else{
                bns[i]={mx,a[i-ind]};
            }
        }
        for(int i=0;i<n;i++){
            ll mxa = max(ans[i].first,ans[i].second);
            ll mxb = max(bns[i].first,bns[i].second);
            if(mxa>mxb) cout<<(binexp(ans[i].first)+binexp(ans[i].second))%M<<" ";
            else if (mxb>mxa) cout<<(binexp(bns[i].first)+binexp(bns[i].second))%M<<" ";
            else {
                mxa = min(ans[i].first,ans[i].second);
                mxb = min(bns[i].first,bns[i].second);
                if(mxa>mxb) cout<<(binexp(ans[i].first)+binexp(ans[i].second))%M<<" ";
                else cout<<(binexp(bns[i].first)+binexp(bns[i].second))%M<<" ";
            }
        }cout<<endl;

    }
    return 0;
    }