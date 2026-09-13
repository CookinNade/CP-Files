#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,h; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>h>>k;
        r=n+k;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll tot = accumulate(arr,arr+n,0ll);
        ll rem = h%tot;
        ll time = h/tot;
        ll ans=time*r;
        if(rem==0)ans=ans-k;
        ll pref[n];
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+arr[i];
        }
        ll pre[n];ll suff[n];
        pre[0]=arr[0]; 
        suff[n-1]=arr[n-1];
        for(int i=1;i<n;i++)pre[i]=min(pre[i-1],arr[i]);
        for(int i=n-2;i>=0;i--)suff[i]=max(arr[i],suff[i+1]);

        for(int i=0;i<n;i++){
            if(rem==0)break;
            ll p=pref[i]+max(suff[i+1],pre[i])-pre[i];
            if(i==n-1)ans=ans+n;
            else if(p>=rem){
                ans=ans+i+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }