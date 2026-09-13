#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll q;
        cin>>n>>q;

        ll arr[n];
        ll srt[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)srt[i] = arr[i];
        sort(srt,srt+n);
        vector<int>v;
        for(int i=0;i<n;i++){
            if(srt[i] != arr[i])v.push_back(i);
        }

        ll pmax[n], smin[n];
        smin[n-1] = arr[n-1];
        pmax[0] = arr[0];
        for(int i=n-2;i>=0;i--)smin[i] = min(smin[i+1],arr[i]);
        for(int i=1;i<n;i++)pmax[i] = max(pmax[i-1],arr[i]);
        if(v.empty()){
            cout<<0<<'\n';
            continue;
        }
        int last = v[(int)v.size() - 1];
        int bit = -1;
        for(int i=21;i>=0;i--){
            if(last & (1ll<<i)){
                bit = i;
                break;
            }
        }
        // for(auto x : v)cout<<x<<" ";
        // cout<<endl;
        bool yes = false;
        ll ans = 0;
        for(int i=0;i<=bit;i++){
            int skip = 1ll<<(i+1);
            int pot = 1ll<<(i);
            bool hobe = true;
            // cout<<skip<<endl;
            for(int j=1;;j++){
                if(skip * j >=n)break;
                // cout<<pmax[j * skip - 1] <<" "<< smin[j * skip]<<'\n';
                if(pmax[j * skip - 1] > smin[j * skip]){
                    hobe = false;
                    break;
                }
            }
            if(hobe){
                ans = pot;
                yes = true;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
    }