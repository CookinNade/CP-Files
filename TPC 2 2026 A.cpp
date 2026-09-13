#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 151;
ll h[N];
ll b[N];
const ll M = 1e9 + 7;
ll dph[15002][N];
ll dpb[15002][N];
ll n,m,k;
ll comb(ll w, ll i){
    if(w == 0)return 1;
    if(i>=m) return 0;
    if(dpb[w][i]!=-1)return dpb[w][i];
    ll ways = 0;
    for(int j = i;j<m;j++){
        if(w - b[j] >= 0){
            ways += comb(w-b[j], j+1);
        }
    }
    return dpb[w][i] = ways;
}
// sin
ll comh(ll w, ll i){
    if(w == 0)return 1;
    if(i>=n) return 0;
    if(dph[w][i]!=-1)return dph[w][i];
    ll ways = 0;
    for(int j = i;j<n;j++){
        if(w - h[j] >= 0){
            ways += comb(w-h[j], j+1);
        }
    }
    return dph[w][i] = ways;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,cnt,k;
    // cout<<v.size()<<endl;
    cin>>t;
    while (t--){
        ll w;
        cin>>n>>m>>k>>w;
        for(int i=0;i<=w;i++){
            for(int j=0;j<n;j++){
                dph[i][j] = -1;
            }
            for(int j=0;j<m;j++){
                dpb[i][j] = -1;
            }
            // dpb[i][j] = -1;
        }
        for(int i=0;i<n;i++)cin>>h[i];
        for(int i=0;i<m;i++)cin>>b[i];
        comb(w,0);
        comh(w,0);
        ll ans = 0;
        for(int i=0;i<=w;i++){
            ll a = i;
            ll b = w - i;
            if(abs(b-a) > k)continue;
            ans = (ans + (accumulate(dph[a],dph[a]+n,0ll) * accumulate(dpb[b],dpb[b]+m,0ll)) % M) % M;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }