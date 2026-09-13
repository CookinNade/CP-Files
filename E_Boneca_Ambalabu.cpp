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
        ll act[35];
        fill(act,act+35,0ll);
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ll a = arr[i];
            for(int j = 0;j<33;j++){
                if(a & (1ll<<j))act[j]++;
            }
        }
        // for(int j = 5;j>=0;j--)cout<<act[j]<<" ";
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll a = arr[i];
            ll num = 0;
            for(int j=0;j<33;j++){
                if((a & (1ll << j) == 0) and act[j] == 0)continue;
                else if((a & (1ll << j))){
                    ll mul = n - act[j];
                    num = num + mul * (1ll<<j);
                }
                else if(!(a & (1ll<<j))){
                    num = num + act[j]*(1ll<<j);
                }
            }
            ans = max(ans, num);
        }
        cout<<ans<<'\n';
    }
    return 0;
    }