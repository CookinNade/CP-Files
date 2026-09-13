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
        ll a[n];
        ll b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        ll ans = 0;
        for(int i=n-1;i>=0;i--){
            if(a[i] > b[i]) ans = ans - abs(a[i] - b[i]);
            else ans = ans + abs(a[i] - b[i]);
            ans = min(ans, 0ll);
        }
        if(ans>=0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }