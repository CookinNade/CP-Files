#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,a,b;
    cin>>n>>k;
    map<ll,ll>mp;
    ll arr[n+1];
    fill(arr+1,arr+n+1,0ll);
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==0)continue;
        else {
            cnt++;
            mp[arr[i]]++;
        }
    }
    // cout<<cnt<<endl;
    ll ans=0;
    for(int i=0;i<-k+cnt;i++){
        auto it = mp.begin();
        a=(*it).first; b=(*it).second;
        // cout<<a<<" "<<b<<endl;
        mp[a]--;

        ans=ans+a;
        if(mp[a]==0)mp.erase(a);
    }
    cout<<ans<<endl;

    return 0;
    }