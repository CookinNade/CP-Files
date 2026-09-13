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
        map<ll,vector<ll>>mp;
        ll arr[n];
        ll answer[n+1];
        fill(answer,answer+n+1,0ll);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            cin>>a;
            mp[arr[i]].push_back(a);
        }
        for(auto it=mp.begin();it!=mp.end();++it){
            sort(mp[(*it).first].rbegin(),mp[(*it).first].rend());
            ll f=(*it).first;
            ll ans=0;
            for(int i=0;i<mp[f].size();i++){
                ans=ans+mp[f][i];
                mp[f][i]=ans;
            }
            for(int i=1;i<=mp[f].size();i++){
                ll tm=mp[f].size()/i;
                answer[i]=answer[i]+mp[f][i*tm-1];
            }
        }
        for(int i=1;i<=n;i++){
            cout<<answer[i]<<" ";
        }cout<<endl;
        
    }
    return 0;
    }