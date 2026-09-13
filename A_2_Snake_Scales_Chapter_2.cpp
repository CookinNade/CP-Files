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
    int j=1;
    while (j<=t){
        cin>>n;
        ll arr[n];
        ll  right[n]; ll left[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            if(i==0)right[i]=arr[i];
            else{
                right[i]=min(abs(arr[i]-arr[i-1]),arr[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1)left[i]=arr[i];
            else{
                left[i]=min(abs(arr[i]-arr[i+1]),arr[i]);
            }
        }
        ll narr[n];
        for(int i=0;i<n;i++){
            narr[i]=min(min(arr[i],right[i]),left[i]);
        }
        for(int i=1;i<n;i++){
            left[i]=max(narr[i],narr[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(narr[i],narr[i+1]);
        }

        ll rightt=max(arr[0],right[1]);
        ll leftt=max(arr[n-1],left[n-2]);
        cout<<rightt<<" "<<leftt<<endl;
        ll ans =min(rightt,leftt);
        for(int i=1;i<n-1;i++){
            ll reall = max(left[i],right[i]);
            ll real=max(reall,arr[i]);
            if(real<ans)cout<<i<<endl;
            ans= min(real,ans);
        }
        if(n==1)cout<<"Case #"<<j<<": "<<arr[0]<<endl;
        else cout<<"Case #"<<j<<": "<<ans<<endl;
        
        for(auto y:left){
            cout<<y<<" ";
        }cout<<endl;
        for(auto y:right){
            cout<<y<<" ";
        }cout<<endl;
        j++;
    }
    return 0;
    }