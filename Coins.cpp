#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll n,k,m,w;
ll s[150];
ll h[150];
ll dps[15001][150];
ll dph[15001][150];
const ll M = 1e9 + 7;
ll cs(ll baki, ll i){
    if(baki == 0) return 1ll;
    if(i >= n)return 0;
    if(dps[baki][i] != -1)return dps[baki][i];

    ll ways = cs(baki,i+1);
    if(baki-s[i] >= 0) ways = (ways + cs(baki-s[i],i+1)) % M;
    return dps[baki][i] = ways;
}
ll cd(ll baki, ll i){
    if(baki == 0) return 1ll;
    if(i >= m)return 0;
    if(dph[baki][i] != -1)return dph[baki][i];

    ll ways = cd(baki,i+1);
    if(baki-h[i] >= 0) ways = (ways + cd(baki-h[i],i+1)) % M;
    return dph[baki][i] = ways;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt; 
    cin>>t;
    while (t--){
        cin>>n>>m>>k>>w;
        // cout<<n<<m<<k<<w<<endl;
        for(int i=0;i<n;i++)cin>>s[i];
        for(int i=0;i<m;i++)cin>>h[i];

        
        for(int i=0;i<n;i++){
            for(int j=0;j<=w;j++)dps[j][i] = -1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<=w;j++)dph[j][i] = -1;
        }
        ll ans = 0;
        for(int i=0;i<=w;i++){
            int b = w-i;
            if(abs(b-i) > k)continue;
            ans = (ans + (cs(i,0) * cd(b,0)) % M) % M;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }