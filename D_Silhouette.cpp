#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        map<ll,ll>mp;
        map<ll,ll>ans;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        auto it = mp.begin();
        ll x = (*it).first;
        if(x != 0){
            cout<<-1<<'\n';
            continue;
        }
        if(mp.size()==1){
            for(int i=0;i<n;i++)cout<<1<<" ";
            cout<<'\n';
            continue;
        }
        ll sum = 0;
        ll prev , freq;
        int yes = true;
        ll last = 0;
        ll rlast = 0;
        
        for(auto it = mp.begin();it!=mp.end();++it){
            if(it == mp.begin()){
                prev = (*it).first;
                freq = (*it).second;
                continue;
            }
            ll a = (*it).first;
            ll b = (*it).second;
            ll real = a - sum;
            // cout<<a<<" "<<prev<<" -> "<<real<<endl;
            if(real % freq){
                yes = false;
                // cout<<"vangse\n";
                break;
            }
            real = real/freq;
            if(real<=rlast){
                yes = false;
                break;
            }
            ans[prev] = real;
            sum = sum + real*freq;
            prev = a;
            freq = b;
            last = a;
            rlast = real;
            
        }
        // cout<<last<<" asdf "<<rlast<<'\n';
        ans[last] = rlast+1;
        if(!yes){
            cout<<-1<<'\n';
            continue;
        }
        for(int i=0;i<n;i++){
            cout<<ans[arr[i]]<<" ";
        }
        cout<<'\n';
        
    }
    return 0;
    }