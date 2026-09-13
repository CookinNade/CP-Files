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
    string s;
    while (t--){
        cin>>n>>q;
        ll arr[n+1]; ll tot[n+1]; ll ans[n+1];
        
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        ans[0]=0;
        ans[1]=arr[1]; tot[0]=0;
        for(int i=1;i<=n;i++){
            tot[i]=tot[i-1]+arr[i];
        }
        for(int i=1;i<=n;i++){
            ans[i]=max(ans[i-1],arr[i]);
        }
        while(q--){
            cin>>k;
            int lo=0; int hi=n;
            while(hi-lo>1){
                int mid=(hi+lo)/2;
                if(ans[mid]<=k)lo=mid;
                else hi=mid-1;
            }
            // cout<<k<<" "<<hi<<" "<<lo<<" ";
            if(ans[hi]<=k)cout<<tot[hi]<<" ";
            else cout<<tot[lo]<<" ";
        }cout<<endl;
        // cout<<endl;
        // for(auto y:ans){
        //     cout<<y<<" ";
        // }cout<<endl;
        // for(int i=1;i<=n;i++)cout<<tot[i]<<" ";
        // cout<<endl;
    }
    return 0;
    }