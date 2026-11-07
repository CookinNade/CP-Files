#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n>>k;
        ll arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        int l = 0;
        int r = n+1;
        ll ans  = 0;
        for(int i=n-k+1;i>=1;i--){
            // cout<<i<<endl;
            if(i < k){
                l = i;
                r = n-l+1;
                break;
            }
            ans += arr[i];
        }
        
        for(;r<=n;r++,l--){
            ans += max(arr[l],arr[r]);
        }
        cout<<ans<<'\n';
    }
    return 0;
    }