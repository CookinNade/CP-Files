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
        vector<ll>vb;
        vector<ll>va;
        ll arr[n];
        ll ans=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i%2)ans=ans-arr[i];
            else ans=ans+arr[i];
        }
        d=LLONG_MIN;
        r=LLONG_MIN;
        l=LLONG_MAX;
        for(int i=n-1;i>=0;i--){
            if((i)%2==0 and i==n-1)continue;
            if(i%2)r=max(r,2*arr[i]+i+1);
            else d=max(d, r-2*arr[i]-i-1);
            // cout<<d<<endl;
        }
        // cout<<d<<endl;
        r=LLONG_MIN;
        // ll dd=LLONG_MIN;
        // cout<<r<<endl;
        for(int i=1;i<n;i++){
            if(i%2)r=max(r,2*arr[i]-1-i);
            else d=max(d,r-2*arr[i]+i+1);
            // cout<<d<<endl;
        }
        ll anss=ans;
        if(n%2)anss=anss+n-1;
        else anss=anss+n-2;
        cout<<max(anss,ans+d)<<endl;
    }
    return 0;
    }