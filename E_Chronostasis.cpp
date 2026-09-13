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
        vector<ll>pos;
        vector<ll>neg;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a>=0)pos.push_back(a);
            else neg.push_back(abs(a));
        }
        ll sum = 0;
        ll nsum = 0;
        if(!pos.empty())
        sum = accumulate(pos.begin(),pos.end(),0ll);
        if(!neg.empty())
        nsum = accumulate(neg.begin(),neg.end(),0ll);
        map<ll,ll>mp;
        if(sum <= nsum){
            cout<<-1<<endl;
            continue;
        }
        
        
        for(int i=0;i<(int)neg.size();i++)mp[neg[i]]++;
        ll start = 1;
        sort(pos.begin(),pos.end());
        for(int i=0;i<(int)pos.size();i++){
            if(pos[i] != 0){
                start = pos[i];
                break;
            }
        }
        vector<ll>ans;
        ans.push_back(start);


        k = 0;
        int f = 0;
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<start<<endl;
            if(mp.empty()){
                // cout<<"from pos "<<i<<" "<<start<<" "<<pos[k]<<endl;
                if(f == 0 and pos[k] == ans[0]){
                    f++; k++;
                    // cout<<" got continued\n";
                    continue;
                }
                ans.push_back(start + pos[k]);
                start +=pos[k];
                k++;
                continue;
            }
            auto it = mp.lower_bound(start);
            if(it == mp.begin()){
                // cout<<"from pos "<<i<<" "<<start<<" "<<pos[k]<<endl;
                if(f == 0 and pos[k] == ans[0]){
                    f++; k++;
                    // cout<<" got continued\n";
                    continue;
                }
                ans.push_back(start + pos[k]);
                start +=pos[k];
                k++;
                continue;
            }
            else{
                --it;
                ll a = (*it).first;
                // ll b = (*it).second;
                // cout<<"from neg "<<i<<" "<<start<<" "<<a<<endl;
                start = start - a;
                ans.push_back(start);
                mp[a]--;
                if(mp[a]==0)mp.erase(a);
                continue;
            }
        }
        for(auto x:ans)cout<<x<<" ";
        cout<<'\n';

    }
    return 0;
    }