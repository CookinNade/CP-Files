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
        pair<ll,ll> arr[n];
        for(int i=0;i<n;i++){
            cin>>k; ll ans=0;
            for(int j=0;j<k;j++){
                cin>>a;
                ans = max(ans,a-j+1);
            }
            arr[i]={ans,k};
        }
        sort(arr,arr+n);
        ll trc=0; ll def=0; ll realans=0;
        for(int i=0;i<n;i++){
            if(realans<arr[i].first){
                trc = arr[i].first-def;
                realans=arr[i].first+arr[i].second;
            }
            else realans= realans+arr[i].second;
            def=def+arr[i].second;
        }
        cout<<trc<<endl;
    }
    return 0;
    }