#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        ll ans=0;
        ll sum=0;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){

            if(i==0){
                sum=sum+abs(arr[i]-arr[i+1]);
                ans= max(ans,abs(arr[i]-arr[i+1]));
            }
            else if(i==n-1){
                ans= max(ans,abs(arr[n-1]-arr[n-2]));
            }
            else{
                sum=sum+abs(arr[i]-arr[i+1]);
                ll mn = abs(arr[i-1]-arr[i+1]);
                ll real=abs(arr[i-1]-arr[i])+abs(arr[i+1]-arr[i]);
                ans=max(ans,real-mn);
                // cout<<real-mn<<" "<<arr[i]<<endl;
            }
        }
        // cout<<ans<<endl;
        // cout<<sum<<endl;
        cout<<sum-ans<<endl;
    }
    return 0;
    }