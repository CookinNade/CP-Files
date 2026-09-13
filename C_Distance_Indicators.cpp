#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    ll ans =0;
    map<ll,ll>mp;
    ll arr[n];
    // map<ll,ll>real;
    for(int i=0;i<n;i++){
        cin>>a;
        arr[i]=a;
        mp[(i+1)-a]++;
    }
    for(int i=0;i<n;i++){
        if(mp.find(arr[i]+i+1)!=mp.end())
            ans = ans + mp[arr[i]+i+1];
    }
    cout<<ans<<endl;
    return 0;
    }