#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            int num = c - '0';
            arr[i] = num;
        }
        cnt = 0;
        mp[0]++;
        for(int i=0;i<n;i++){
            cnt--;
            cnt+= arr[i];
            mp[cnt]++;
        }
        ll ans = 0;
        for(auto it = mp.begin();it!=mp.end();++it){
            // cout<<(*it).first<<" "<<(*it).second<<endl;
            if((*it).second == 1)continue;
            k = (*it).second;
            k--;
            ll bare = k*(k+1)/2;
            ans += bare;
        }
        cout<<ans<<'\n';        
    }
    return 0;
    }