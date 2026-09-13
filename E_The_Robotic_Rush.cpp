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
        cin>>n>>m>>k;
        ll arr[n];
        vector<ll>v;
        map<ll,vector<ll>>mp;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<m;i++){
            cin>>a;
            v.push_back(a);
        }
        cin>>s;
        sort(v.begin(),v.end());
        ll alive[n];
        for(int i=0;i<n;i++)alive[i]=1;
        for(int i=0;i<n;i++){
            a=arr[i];
            auto it = upper_bound(v.begin(),v.end(),a);
            if(it==v.end()){
                mp[1e15].push_back(i);
                --it;
                mp[(*it)-a].push_back(i);
            }
            else if(it==v.begin()){
                mp[(*it)-a].push_back(i);
                mp[-1e15].push_back(i);
            }
            else{
                mp[(*it)-a].push_back(i);
                --it;
                mp[(*it)-a].push_back(i);
            }
        }
        ll cnt=n;
        ll move=0;
        for(int i=0;i<k;i++){
            if(s[i]=='R')move++;
            else move--;
            if(mp.find(move)==mp.end()){
                cout<<cnt<<" ";
                continue;
            }
            else{
                for(int i=0;i<mp[move].size();i++){
                    if(alive[mp[move][i]]){
                        alive[mp[move][i]]=0;
                        cnt--;
                    }
                }
                cout<<cnt<<" ";
                mp.erase(move);
            }
        }
        cout<<endl; 
    }
    return 0;
    }