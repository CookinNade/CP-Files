#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,f; 
    cin>>t;
    ll s;
    while (t--){
        cin>>n>>m;
        pair<int,int>arr[m+1];
        for(int i=0;i<m;i++){
            cin>>a>>b;
            ll mn = min(a,b);
            ll mx = max(a,b);
            arr[i]={mx,mn};
        }
        arr[m]={n+1,n};
        sort(arr,arr+m+1);
        l=1; ll ans =0;
        for(int i=0;i<=m;i++){
            s=arr[i].second;f=arr[i].first;
            if(s<l)continue;
            else{
                for(;l<=s;l++) ans=ans+f-l;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }