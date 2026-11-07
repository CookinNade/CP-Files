#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        int ase = 0;
        int mx = *max_element(arr,arr+n);
        for(int i=0;i<n;i++)if(mx == arr[i])ase++;
        if(ase >k){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        sort(arr,arr+n);
        vector<ll>v;
        int cnt = 0;
        int last = 0;
        for(int i=n-1;cnt<k;i--,cnt++){
            v.push_back(arr[i]);
            last = i;
        }
        reverse(v.begin(),v.end());
        for(auto x:v)cout<<x<<" ";
        for(int i=last-1;i>=0;i--)cout<<arr[i]<<" ";
        cout<<'\n';
    }
    return 0;
    }