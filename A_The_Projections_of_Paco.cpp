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
        for(int i=0;i<n;i++)cin>>arr[i];
        ll dest = 0;
        for(int i=n-1;i>=0;i--){
            dest = 2*arr[i] - dest;
        }
        cout<<dest/2<<'\n';
    }
    return 0;
    }