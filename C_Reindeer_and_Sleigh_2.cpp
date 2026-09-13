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
    
    while (t--){
        cin>>n;
        ll w[n];ll p[n];
        ll ans[n];
        for(int i=0;i<n;i++)cin>>w[i]>>p[i];
        for(int i=0;i<n;i++)ans[i]=w[i]+p[i];
        sort(ans,ans+n,greater<int>());
        ll sum=accumulate(w,w+n,0ll);
        ll real=0,cnt=0;
        for(int i=0;i<n;i++){
            if(real>=sum){
                cnt=n-i;
                break;
            }
            real=real+ans[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
    }