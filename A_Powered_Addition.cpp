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
            if(i==0)pref[i]=arr[i];
            else pref[i]=max(pref[i-1],arr[i]);            
        }
        d=-1;
        for(int i=0;i<n;i++){
            d=max(pref[i]-arr[i],d);
        }
        ll ans=-1;
        for(int i=0;i<31;i++){
            if(d&(1<<i)) ans=i;
        }
        cout<<ans+1<<endl;
    }
    return 0;
    }