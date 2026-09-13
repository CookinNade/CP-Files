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
        ll lc=1;
        ll arr[n];
        ll ans[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            lc=lcm(arr[i],lc);
        }
        for(int i=0;i<n;i++) ans[i]=lc/arr[i];
        ll sum=accumulate(ans,ans+n,0ll);
        // cout<<sum<<" "<<lc<<endl;
        if(sum<lc){
            for(int i=0;i<n;i++)cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
    }