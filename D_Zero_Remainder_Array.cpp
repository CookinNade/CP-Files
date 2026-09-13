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
        cin>>n>>k;
        ll arr[n];
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%k==0)continue;
            else{
                mp[k-(arr[i]%k)]++;
            }
        }
        ll cnt=0;
        for(auto it = mp.begin();it!=mp.end();++it){
            ll val=((*it).second-1)*k + (*it).first;
            cnt=max(cnt,val);
        }
        if(cnt==0)cout<<cnt<<endl;
        else cout<<cnt+1ll<<endl;
    }
    return 0;
    }