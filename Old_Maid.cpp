#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        cin>>n;
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            mp[a]++;
        }
        ll sum = 0;
        for(auto it=mp.begin();it!=mp.end();++it){
            if((*it).second % 2 == 0)continue;
            sum += (*it).first;
        }
        cout<<sum<<'\n';
    }
    return 0;
    }