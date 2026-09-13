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
        cin>>n; ll arr[2*n];
        ll pref[n+1]; pref[0]=0; ll prefi[n+1]; prefi[0]=0;
        ll alter[2*n];
        alter[0]=-arr[0];
        
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
        }
        alter[0]=-arr[0];
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+arr[i];
        }
        for(int i=2*n-1,j=1;i>=n;i--,j++){
            prefi[j]=prefi[j-1]+arr[i];
        }
        for(int i=1;i<2*n;i++){
            if(i%2){
                alter[i]=arr[i]+alter[i-1];
            }
            else{
                alter[i]=-arr[i]+alter[i-1];
            }
        }
        ll alterev[2*n];
        alterev[0]=arr[0];
        for(int i=1;i<2*n;i++){
            if(i%2==0){
                alterev[i]=arr[i]+alterev[i-1];
            }
            else{
                alterev[i]=-arr[i]+alterev[i-1];
            }
        }
        for(int i=1;i<=n;i++){
            ll ans=0;
            ans=prefi[i]-pref[i];
            if(i%2){
                ans=ans-alterev[2*n-i-1]+alterev[i-1];
            }
            else{
                ans=ans+alterev[2*n-i-1]-alterev[i-1];
            }
            cout<<ans<<" ";
        }cout<<endl;
    }
    return 0;
    }