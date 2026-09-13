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
        cin>>n>>m;
        ll arr[n]; ll ans=0;
        
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        if(m>n){
            d= m-n+1;
            for(int i=0;i<n;i++){
                ans=ans+d*arr[i];
                d++;
            }
        }
        else{
            d=1;
            for(int i=n-m;i<n;i++){
                ans=ans+arr[i]*d;
                d++;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
    }