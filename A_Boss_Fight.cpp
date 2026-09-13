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
        int arr[n];
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        int mx = 0;
        int val;
        for(auto it = mp.begin();it!=mp.end();++it){
            if(mx < (*it).second){
                mx = (*it).second;
                val = (*it).first;
            }
        }
        
        if(mx <= n/2 + 1)cout<<accumulate(arr,arr+n,0ll)<<'\n';
        else{
            ll sum =  accumulate(arr,arr+n,0ll);
            int hobe = n - mx + 2;
            hobe = min(hobe,n);
            sum = sum - mx*val;
            sum = sum + hobe*val;
            cout<<sum<<'\n';
        }
        
    }
    return 0;
    }