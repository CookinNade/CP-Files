#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin>>t;
    while(t--){
       ll a,b,n,f,s,tot;
       map<ll,ll>mp;
       map<ll,pair<ll,ll>>out;
       cin>>n;
       ll arr[n]; tot=0;
       for(int i=0;i<n;i++){
            cin>>a;
            arr[i]=a;
            mp[a]++;
       }
       int noer=0;
       for(auto it=mp.begin();it!=mp.end();++it){
            f = (*it).first; s= (*it).second;
            tot = tot+s;
            if(s%f!=0){
                noer++;break;
            }
       }
       if(tot!=n or noer)cout<<-1<<endl;
       else{
        ll num=1;
        for(auto it=mp.begin();it!=mp.end();++it){
            f = (*it).first; s= (*it).second;
            for(int i=0;i<(s/f);i++){
                out[f].first=num;
                out[f].second=0;
                num++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<out[arr[i]].first<<" ";
            out[arr[i]].second++;
            if(out[arr[i]].second==arr[i]){
                out[arr[i]].second=0;
                out[arr[i]].first--;
            }
        }
        cout<<endl;
       }
    }
}