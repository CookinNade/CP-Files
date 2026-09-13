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
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans=0;
        if(k>1){
            sort(arr,arr+n,greater<int>());
            for(int i=0;i<k+1;i++)ans=ans+arr[i];
        }
        else{
            ans = max(arr[0]+arr[n-1],ans);
            for(int i=1;i<n-1;i++){
                ll real = max(arr[0]+arr[i],arr[i]+arr[n-1]);
                ans=max(ans,real);
                // cout<<arr[i]<<" ";
            }
            // cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
    }