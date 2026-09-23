#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 5e5+10;
bool vis[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        } 
        vector<ll>prefsum(n);
        vector<ll>suffsum(n);
        vector<ll>prefmx(n);
        vector<ll>suffmx(n);
        // ll prefsum[n], suffsum[n], prefmx[n], suffmx[n];
        for(int i=0;i<n;i++){
            if(i == 0)prefsum[i] = arr[i];
            else prefsum[i] = arr[i] + prefsum[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(i == n-1)suffsum[i] = arr[i];
            else suffsum[i] = suffsum[i+1] + arr[i];
        }

        fill(vis+1,vis+2+n,false);
        int mx = 1;
        for(int i=0;i<n;i++){
            int a = arr[i];
            vis[a] = true;
            if(a == mx){
                for(int j = mx+1;j<=n+1;j++){
                    if(!vis[j]){
                        mx = j;
                        break;
                    }
                }
            }
            prefmx[i] = mx;
        }
        

        fill(vis+1,vis+2+n,false);
        mx = 1;
        for(int i=n-1;i>=0;i--){
            int a = arr[i];
            vis[a] = true;
            if(a == mx){
                for(int j = mx+1;j<=n+1;j++){
                    if(!vis[j]){
                        mx = j;
                        break;
                    }
                }
            }
            suffmx[i] = mx;
        }

        // for(int i=0;i<n;i++)cout<<prefsum[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<suffsum[i]<<" ";
        ll ans = prefsum[n-1];
        ans = ans - n - 1;
        for(int i=0;i<n;i++){
            ll sum = prefsum[i] - prefmx[i];
            ans = max(sum,ans);
        }
        for(int i=n-1;i>=0;i--){
            ll sum = suffsum[i] - suffmx[i];
            ans = max(ans,sum);
        }
        // cout<<endl;
        cout<<ans<<'\n';
    }
    return 0;
    }