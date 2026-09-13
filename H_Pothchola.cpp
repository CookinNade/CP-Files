#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
vector<ll>g[61];
ll best[61];
ll len(int v){
    if(g[v].empty()) return 0;
    if(best[v] != -1)return best[v];
    ll ans = 0;
    for(int i=0; i<(int)g[v].size(); i++){
        ll cnt = 0;
        ll a = g[v][i];
        for(int j = v-1; j>=0; j--){
            ll bcnt = 0;
            if(a & (1ll << j)){
                bcnt = len(j);
            }
            cnt = max(bcnt, cnt);
        }
        ans = max(cnt, ans);
    }
    return best[v] = ans + 1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        memset(best,-1,sizeof(best));
        // fill(best,best+61,false);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            for(int j = 60; j>=0; j--){
                if(arr[i] & (1ll << j)){
                    g[j].push_back(arr[i]);
                    break;
                }
            }
        }
        ll ans = 1;
        for(int i=0; i<61; i++){
            ans = max(ans, len(i));
        }
        for(int i=0; i<61; i++){
            g[i].clear();
        }
        cout<<ans<<endl;
        
    }
    return 0;
    }