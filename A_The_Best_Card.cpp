#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        map<ll,ll>mp;
        vector<ll>ans;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        mp[arr[0]]++;
        ans.push_back(arr[0]);
        bool nisi[n];
        fill(nisi,nisi+n,false);
        nisi[0] = true;
        for(int i=1;i<n;i++){
            int sz = (int)ans.size();
            if(arr[i] == ans[sz-1])continue;
            else{
                ans.push_back(arr[i]);
                nisi[i] = true;
                mp[arr[i]]++;
            }
        }
        int sz = (int)ans.size();
        cout<<sz<<'\n';
        for(int i=0;i<n;i++){
            if(nisi[i])continue;
            int a = arr[i];
            if(mp[a] >= sz/2 + 1)continue;
            if((int)ans.size() == 1 and ans[0] == a)continue;
            else{
                // cout<<a<<" "<<mp[a]<<" this sa \n";
                sz++;
                break;
            }
        }
        cout<<sz<<'\n';

    }
    return 0;
    }