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
        ll arr[n];
        ll pref[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll mx=arr[0];
        for(int i=0;i<n;i++){
            mx=max(arr[i],mx);
            pref[i]=mx;
        }
        ll ans=0;
        for(int i=1;i<n;i++){
            if(i==n-1 and i%2==1){
                arr[i]=pref[i];
                if(arr[i-1]>=arr[i]){
                    ans=ans+arr[i-1]-arr[i]+1;
                    arr[i-1]=arr[i]-1;
                }
            }
            else if(i%2==1){
                arr[i]=pref[i];
                if(arr[i-1]>=arr[i]){
                    ans=ans+arr[i-1]-arr[i]+1;
                    arr[i-1]=arr[i]-1;
                }
                if(arr[i+1]>=arr[i]){
                    ans=ans+arr[i+1]-arr[i]+1;
                    arr[i+1]=arr[i]-1;
                }

            }
        }
        cout<<ans<<endl;
        // for(auto y:arr){
        //     cout<<y<<" ";
        // }cout<<endl;
        // for(auto y:pref){
        //     cout<<y<<" ";
        // }cout<<endl;
    }
    return 0;
    }