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
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans=0;
        for(int i=0; i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,arr[i]^arr[j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }